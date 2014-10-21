bool inCriticalP = false;
bool inCriticalQ = false;
byte critical = 0;

active proctype P() {
  do
    :: printf("Non-critical section P\n");
       atomic {
         !inCriticalQ;
         inCriticalP = true
       }
       /* begin critical section */
       critical++;
       printf("Critical section P\n");
       assert (critical <= 1);
       critical--;
       /* end critical section */
        inCriticalP = false
 od
}

active proctype Q() {        
  do 
    :: printf("Non-critical section Q\n");
       atomic {
         !inCriticalP;
         inCriticalQ = true
       }
       /* begin critical section */
       critical++;
       assert (critical <= 1);
       critical--;
       printf("Critical section Q\n");
       /* end critical section */
       inCriticalQ = false
  od
}
