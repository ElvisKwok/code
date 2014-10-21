/* ANTI PATTERN
   works, but does not carry over to more
   interesting critical section examples,
   neither to systems where atomicity is
   an inappropriate assumption */

bool enterCriticalP = false;
bool enterCriticalQ = false;

active proctype P() {
  do
    :: printf("P non-critical actions\n");
       atomic{
         enterCriticalP = true;
         /* begin critical section */
         printf("P uses shared recourses\n");
         assert( !enterCriticalQ );
         /* end critical section */
         enterCriticalP = false
      }
  od
}

active proctype Q() {
  do
    :: printf("Q non-critical actions\n");
       atomic{
         enterCriticalQ = true;
         /* begin critical section */
         printf("Q uses shared recourses\n");
         assert( !enterCriticalP );
         /* end critical section */
         enterCriticalQ = false
       }
  od
}
