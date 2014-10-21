bool enterCriticalP = false;
bool enterCriticalQ = false;
byte critical = 0;

active proctype P() {
  do
    :: printf("P non-critical actionsP\n");
  
       atomic {
         !enterCriticalQ;
         enterCriticalP = true
       }

       /* begin critical section */
       critical++;
       printf("P uses shared recourses\n");
       critical--;
       /* end critical section */

       enterCriticalP = false
  od
}

active proctype Q() {
  do
    :: printf("Q non-critical actions\n");

       atomic {
         !enterCriticalP;
         enterCriticalQ = true
       }

       /* begin critical section */
       critical++;
       printf("Q uses shared recourses\n");
       critical--;
       /* end critical section */

       enterCriticalQ = false
  od
}

active proctype Z() {
   assert (critical >= 0 && critical <= 1);
   /* This also works */
   assert (! (enterCriticalP && enterCriticalQ) )
}