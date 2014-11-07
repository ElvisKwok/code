mtype = {ok, err, msg1, msg2, msg3, keyA, keyB, agentA, agentB,
  nonceA, nonceB };
typedef Crypt { mtype key, content1, content2};
chan network = [0] of {mtype, /* msg# */
  mtype, /* receiver */
  Crypt
};
/* global variables for verification*/
mtype partnerA, partnerB;
mtype statusA = err;
mtype statusB = err;

ltl BOTH_ARE_OK {<>(statusA == ok && statusB == ok)};

/* Agent (A)lice */
active proctype Alice() {
  /* local variables */
  mtype pkey; /* the other agent's public key */
  mtype pnonce; /* nonce that we receive from the other agent */
  Crypt messageAB; /* our encrypted message to the other party */
  Crypt data; /* received encrypted message */
  /* Initialization */
  partnerA = agentB;
  pkey = keyB;
  /* Prepare the first message */
  messageAB.key = pkey;
  messageAB.content1 = agentA;
  messageAB.content2 = nonceA;
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
  (data.key == keyA) && (data.content1 == nonceA);
  /* Obtain Bob's nonce */
  pnonce = data.content2;
  /* Prepare the last message */
  messageAB.key = pkey;
  messageAB.content1 = pnonce;
  messageAB.content2 = 0; /* content2 is not used in the last message,
                             just set it to 0 */
  /* Send the prepared messaage */
  network ! msg3 (partnerA, messageAB);
  /* and last - update the auxilary status variable */
  statusA = ok;
}

/* Agent (B)ob */
active proctype Bob() {
   /* local variables */
  mtype pkey; /* the other agent's public key */
  mtype pnonce; /* nonce that we receive from the other agent */
  Crypt messageBA; /* our encrypted message to the other party */
  Crypt data; /* received encrypted message */
  /* Initialization */
  partnerB = agentA;
  pkey = keyA;
  /* Wait for an answer. Observe the we are pattern-matching on the
     messages that start with msg1 and agentB, that is, we block until
     we see a message with values msg2 and agentA as the first and second
     components. The third component is copied to the variable data.
   */
  network ? (msg1, agentB, data);
  /* We proceed only if the key field of the data matches keyB and
     the
     message was sent from agentA; block
     otherwise. */
  (data.key == keyB) && (data.content1 == agentA);
  
  /* Obtain A's nonce. */
  pnonce = data.content2;
  /* Prepare the message 
  */
  messageBA.key = pkey;
  messageBA.content1 = pnonce;
  messageBA.content2 = nonceB;
  
  network ! msg2 (partnerB,messageBA);
  
  /* Wait for the last message.
  */
  network ? (msg3, agentB, data);
  

  /* We proceed only if the key field of the data matches keyB and
     the
     received nonce is the one that we have sent earlier; block
     otherwise. */
  (data.key == keyB) && (data.content1 == nonceB);

  /* and last - update the auxilary status variable */
  statusB = ok;
}
