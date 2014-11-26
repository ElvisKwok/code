bool inCriticalP = false;
bool inCriticalQ = false;
bool csp = false;
bool csq = false;

active proctype P() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalQ;
          inCriticalP = true
        }
        csp = true;
        /* critical activity */
        csp = false;
        inCriticalP = false
  od
}

active proctype Q() {
  do :: /* non-critical activity */
        atomic {
          !inCriticalP;
          inCriticalQ = true
        }
        csq = true;
        /* critical activity */
        csq = false;
        inCriticalQ = false
  od
}

ltl l { <>csp && <>csq}
