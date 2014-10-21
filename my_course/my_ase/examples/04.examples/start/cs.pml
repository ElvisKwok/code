bool enterCriticalP = false;
bool enterCriticalQ = false;

active proctype P() {
  do
    :: printf("P non-critical actionsP\n");       
       enterCriticalP = true;
       /* begin critical section */       
       printf("P uses shared recourses\n");
       /* end critical section */
       enterCriticalP = false
  od
}

active proctype Q() {
  do
    :: printf("Q non-critical actions\n");
       enterCriticalQ = true;
       /* begin critical section */
       printf("Q uses shared recourses\n");
       /* end critical section */
       enterCriticalQ = false
  od
}
