bool enterCriticalP = false;
bool enterCriticalQ = false;

active proctype P() {
  do
    :: printf("Non-critical section P\n");
       enterCriticalP = true;
       /* begin critical section */
       printf("Critical section P\n");
       assert( !enterCriticalQ );
       /* end critical section */
       enterCriticalP = false
  od
}

active proctype Q() {
  do 
    :: printf("Non-critical section Q\n");
       enterCriticalQ = true;
       /* begin critical section */
       printf("Critical section Q\n");
       assert( !enterCriticalP );
       /* end critical section */
       enterCriticalQ = false
  od
}
