mtype = {ok, err, msg1, msg2, msg3, keyA, keyB, agentA, agentB, nonceA, nonceB, agentI, keyI, nonceI};
typedef Crypt {mtype key, content1, content2, content3};
chan network = [0] of {mtype, /* msg# */
                       mtype, /* receiver */
                       Crypt
};

/* global variables for verification*/
mtype partnerA, partnerB;
mtype statusA = err;
mtype statusB = err;
bool knows_nonceA, knows_nonceB;

/* ltl PROP_AB {[]((statusA==ok && statusB==ok) -> (partnerA==agentB && partnerB==agentA))} */
/* ltl PROP_A {[]((statusA==ok && partnerA==agentB) -> (!knows_nonceA))} */
ltl PROP_B {[]((statusB==ok && partnerB==agentA) -> (!knows_nonceB))}

/* Agent (A)lice */
active proctype Alice() {
	/* local variables */
	mtype pkey; /* the other agent's public key */
	mtype pnonce; /* nonce that we receive from the other agent */
	Crypt messageAB; /* our encrypted message to the other party */
	Crypt data; /* received encrypted message */

	/* Initialization */
    if
	    :: partnerA = agentB;
	       pkey = keyB;
        :: partnerA = agentI;
           pkey = keyI;
    fi;
	/* Prepare the first message */
	messageAB.key = pkey;
	messageAB.content1 = agentA;
	messageAB.content2 = nonceA;

	/* Send the first message to the other party */
	network ! msg1 (partnerA, messageAB);

	/* 
     * Wait for an answer. Observe the we are pattern-matching on the
	 * messages that start with msg2 and agentA, that is, we block until
	 * we see a message with values msg2 and agentA as the first and second
	 * components. The third component is copied to the variable data.
	 */
	network ? (msg2, agentA, data);

	/* 
     * We proceed only if the key field of the data matches keyA and the
	 * received nonce is the one that we have sent earlier; block otherwise. 
     */
	(data.key == keyA) && (data.content1 == nonceA) && (data.content3 == partnerA);

	/* Obtain Bob's nonce */
	pnonce = data.content2;

	/* Prepare the last message */
	messageAB.key = pkey;
	messageAB.content1 = pnonce;
	messageAB.content2 = 0; /* content2 is not used in the last message, just set it to 0 */

	/* Send the prepared messaage */
	network ! msg3 (partnerA, messageAB);

	/* and last - update the auxilary status variable */
	statusA = ok;
}

active proctype Bob() {
	/* local variables */
	mtype pkey; /* the other agent's public key */
	mtype pnonce; /* nonce that we receive from the other agent */
	Crypt messageBA; /* our encrypted message to the other party */
	Crypt data; /* received encrypted message */

    
    /* inintialized */
    if
        :: pkey = keyA;
           partnerB = agentA;
        :: pkey = keyI;
           partnerB = agentI;
    fi;
    /* prepare to receive message from alice */
    network ? (msg1, agentB, data);
    
    /* check the content of the message */
    (data.key == keyB) && (data.content1 == agentA);
    
    pnonce = data.content2;
    
    /* prepare to sent message to Alice */
    
    messageBA.key = pkey;
    messageBA.content1 = pnonce;
    messageBA.content2 = nonceB;
    messageBA.content3 = agentB;
    network ! msg2(partnerB, messageBA);
    
    /* prepar to receive the last message from Alice */
    network ? (msg3, agentB, data);
    
    /* check the message content */
    (data.key == keyB) && (data.content1 == nonceB);
    
    statusB = ok;
    
}

active proctype Intruder() {
	mtype msg, recpt;
	Crypt data, intercepted;

    knows_nonceA = false;
    knows_nonceB = false;
    mtype pnonceA, pnonceB;

	do
		:: network ? (msg, _, data) ->
		if 
            /* sniff msg from Alice */
            :: data.key == keyI ->
               if
                    :: msg == msg1 ->
                       knows_nonceA = true;
                       pnonceA = data.content2;
                    :: msg == msg3 ->
                       knows_nonceB = true;
                       pnonceB = data.content1;
               fi;
            :: else ->
               /* expected msg from Bob */
			   intercepted.key = data.key;
			   intercepted.content1 = data.content1;
			   intercepted.content2 = data.content2;
		fi;

        ::     /* disguise to send a valid msg */
        if
            /* choose a msg to send according to sniffed nonce */
            :: knows_nonceA && !knows_nonceB ->
               msg = msg1;
            :: knows_nonceA && knows_nonceB ->
               msg = msg3;
            :: else ->
               msg = msg2;
        fi;

        if
            /* choose a receiver accord to the msg */
            :: msg == msg1 || msg == msg3 ->
               recpt = agentB;
            :: msg == msg2 ->
               recpt = agentA;
        fi;

        if
            /* the disguised msg content */
            :: msg == msg1 ->
               data.key = keyB;
               data.content1 = agentA;
               data.content2 = pnonceA;
            :: msg == msg2 ->
               data.key = keyA;
               data.content1 = intercepted.content1;
               data.content2 = intercepted.content2;
            :: msg == msg3 ->
               data.key = keyB;
               data.content1 = pnonceB;
               data.content2 = 0;
        fi;

		network ! msg (recpt, data);
	od
}
