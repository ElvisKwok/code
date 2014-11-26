bool inCriticalP = false;
bool inCriticalQ = false;
byte critical = 0;

active proctype P() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalQ;
          inCriticalP = true
        }
        critical++;
        /* critical activity */
        critical--;
        inCriticalP = false
  od
}

active proctype Q() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalP;
          inCriticalQ = true
        }
        critical++;
        /* critical activity */
        critical--;
        inCriticalQ = false
  od
}
