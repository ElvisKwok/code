bool enterCriticalP = false;
bool enterCriticalQ = false;

active proctype P() {
  do
    ::
       printf("P non-critical actions\n");
       enterCriticalP = true;
       !enterCriticalQ;
       /* begin critical section */
       printf("P uses shared recourses\n");
       assert(!enterCriticalQ);
       /* end critical section */
       enterCriticalP = false;
  od
}

active proctype Q() {
  do
    ::
       printf("Q non-critical actions\n");
       enterCriticalQ = true;
       !enterCriticalP;
       /* begin critical section */
       printf("Q uses shared recourses\n");
       assert(!enterCriticalP);
       /* end critical section */
       enterCriticalQ = false;
  od
}
