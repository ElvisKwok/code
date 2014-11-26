bool inCriticalP = false;
bool inCriticalQ = false;

active proctype P() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalQ;
          inCriticalP = true
        }
cs:     /* critical activity */
        inCriticalP = false
  od
}

active proctype Q() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalP;
          inCriticalQ = true
        }
cs:     /* critical activity */
        inCriticalQ = false
  od
}

ltl m { !(P@cs && Q@cs) }