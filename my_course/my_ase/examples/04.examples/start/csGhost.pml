bool enterCriticalP = false;
bool enterCriticalQ = false;
byte critical = 0;

active proctype P() {
  do
    :: printf("P non-critical action\n");
       enterCriticalP = true;
       !enterCriticalQ;
       /* begin critical section */
       critical++;
       printf("P uses shared resource\n");
       assert (critical < 2);
       critical--;
       /* end critical section */
       enterCriticalP = false
  od
}

active proctype Q() {        
  do 
    :: printf("Q non-critical action\n");
       enterCriticalQ = true;
       !enterCriticalP;
       /* begin critical section */
       critical++;
       printf("Q uses shared resource\n");
       assert (critical < 2);
       critical--;
       /* end critical section */
       enterCriticalQ = false
  od
}
