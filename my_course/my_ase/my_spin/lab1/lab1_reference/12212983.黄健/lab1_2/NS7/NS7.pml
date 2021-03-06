mtype = {ok, err, msg1, msg2, msg3, keyA, keyB, agentA, agentB, nonceA, nonceB, agentI, keyI, nonceI};
typedef Crypt { mtype key, content1, content2, content3};
chan network = [0] of {mtype, /* msg# */
						mtype, /* receiver */
						Crypt
						};

/* global variables for verification*/
mtype partnerA = false, partnerB =  false;
mtype statusA = err;
mtype statusB = err;

bool knows_nonceA, knows_nonceB;

//ltl BOTH_ARE_OK {<>(statusA==ok && statusB==ok)}
ltl {[]((statusA==ok && statusB==ok) -> (partnerA==agentB && partnerB==agentA))}
ltl {[]((statusA==ok && partnerA==agentB) -> (!knows_nonceA))}
ltl {[]((statusB==ok && partnerB==agentA) -> (!knows_nonceB))}

/* Agent (A)lice */
active proctype Alice() {
	/* local variables */
	mtype pkey; /* the other agent's public key */
	mtype pnonce; /* nonce that we receive from the other agent */
	Crypt messageAB; /* our encrypted message to the other party */
	Crypt data; /* received encrypted message */
	/* Initialization */
	if
		::partnerA = agentB;
		pkey = keyB
		::partnerA = agentI;
		pkey = keyI
	fi;
	/* Prepare the first message */
	messageAB.key = pkey;
	messageAB.content1 = agentA;
	messageAB.content2 = nonceA;
	messageAB.content3 = 0;
	/* Send the first message to the other party */
	network ! msg1 (partnerA, messageAB);
	/* Wait for an answer. Observe the we are pattern-matching on the
	messages that start with msg2 and agentA, that is, we block until
	we see a message with values msg2 and agentA as the first and second
	components. The third component is copied to the variable data.
	*/
	network ? (msg2, agentA, data);
	/* We proceed only if the key field of the data matches keyA and
	the
	received nonce is the one that we have sent earlier; block
	otherwise. */
	(data.key == keyA) && (data.content1 == partnerA) && (data.content2 == nonceA);
	/* Obtain Bob's nonce */
	pnonce = data.content3;
	/* Prepare the last message */
	messageAB.key = pkey;
	messageAB.content1 = pnonce;
	messageAB.content2 = 0; /* content2 is not used in the last message,
	just set it to 0 */
	messageAB.content3 = 0;
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
	/* Initialization */
	network ? (msg1, agentB, data);
	
	data.key == keyB;
	partnerB = data.content1;
	if
		::partnerB == agentA;
		pkey = keyA;
		::partnerB == agentI;
		pkey = keyI;
	fi;
	pnonce = data.content2;

	messageBA.key = pkey;
	messageBA.content1 = agentB;
	messageBA.content2 = pnonce;
	messageBA.content3 = nonceB;

	network ! msg2 (partnerB, messageBA);
	
	network ? (msg3, agentB, data);

	(data.key == keyB) && (data.content1 == nonceB);
	
	statusB = ok;
}

active proctype Intruder() {
	mtype msg, recpt;
	Crypt data, intercepted;
	accept_Intruder: 
	do
		:: network ? (msg, _, data) ->
		if /* perhaps store the message */
			::intercepted.key = data.key;
			intercepted.content1 = data.content1;
			intercepted.content2 = data.content2;
			intercepted.content3 = data.content3;
			:: skip;
		fi;
		if
			::intercepted.key == keyI;
			if
				::msg == msg1;
				knows_nonceA = true;
				::msg == msg2;
				knows_nonceA = true;
				knows_nonceB = true;
				::msg == msg3;
				knows_nonceB = true;
			fi;
			::else -> skip;
		fi;
		:: /* Replay or send a message */
		if /* choose message type */
			:: msg = msg1;
			:: msg = msg2;
			:: msg = msg3;
		fi;
		if /* choose a recepient */
			:: recpt = agentA;
			:: recpt = agentB;
		fi;
		if /* replay intercepted message or assemble it */
			:: knows_nonceA || knows_nonceB;
			data.key = keyB;
			data.content1 = intercepted.content1;
			data.content2 = intercepted.content2;
			data.content3 = intercepted.content3;
			:: data.key = intercepted.key;
			data.content1 = intercepted.content1;
			data.content2 = intercepted.content2;
			data.content3 = intercepted.content3;
			:: if /* assemble content1 */
				:: data.content1 = agentA;
				:: data.content1 = agentB;
				:: data.content1 = agentI;
				:: data.content1 = nonceI;
			fi;
			if /* assemble key */
				:: data.key = keyA;
				:: data.key = keyB;
				:: data.key = keyI;
			fi;
			data.content2 = nonceI; 
			data.content3 = nonceI;
		fi;
		network ! msg (recpt, data);
	od
}
