mtype={ok, err, msg1, msg2, msg3, keyA, keyB, agentA, agentB, nonceA, nonceB };

typedef Crypt {mtype key, content1, content2};

chan network=[0] of {mtype,/*msg*/
mtype,/* receiver */
Crypt
};

/*global variables for verification*/
mtype partnerA, partnerB;
mtype statuA =err;
mtype statuB =err;

/* Agent Alice */
active proctype Alice(){
mtype pkey; //the other agent's public key
mtype pnonce; //nonce that we receive from the other agent
Crypt messageAB;//our encrypted message to the other party
Crypt data; //received encrypted message



//initialization
partnerA =agentB;
pkey=keyB;

//prepare the first message

messageAB.key=pkey;
messageAB.content1 =agentA;
messageAB.content2 =nonceA;

//send the first message to the other party

network ! msg1(partnerA, messageAB);

/* wait for an answer, observe that we are pattern-matching on the messages that start with msg2 and agentA,
that is ,copy the third component to the variable data
*/

network? (msg2, agentA, data);

/*
only if the key field of the data matchs keyA and the received nonce is the one that we have sent earlier
*/

(data.key==keyA) && (data.content1 ==nonceA);

pnonce =data.content2;

//prepare the last message
messageAB.key=pkey;
messageAB.content1=pnonce;
messageAB.content2 =0; //content2 not used in the last message

network ! msg3(partnerA, messageAB);

statuA=ok;
}



active proctype Bob(){
printf("bob\n");
//local variables
Crypt messageBA;//message sent to Alice
Crypt data; //received message
mtype pkey;
mtype pnonce;//received nonce from Alice

//inintialized
pkey=keyA;
partnerB=agentA;

//prepare to receive message from alice
network? msg1(agentB,data);

//check the content of the message
(data.key==keyB)&&(data.content1==partnerB);

pnonce =data.content2;

//prepare to sent message to Alice

messageBA.key=pkey;
messageBA.content1=pnonce;
messageBA.content2=nonceB;

network !msg2(partnerB,messageBA);

//prepar to receive the last message from Alice
network ? msg3(agentB,data);

//check the message content
(data.key==keyB)&&(data.content1==nonceB);

statuB=ok;
}

ltl BOTH_ARE_OK{<>((statuA==ok)&&(statuB==ok))}