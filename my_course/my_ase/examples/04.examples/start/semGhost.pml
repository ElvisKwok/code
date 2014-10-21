byte sem = 5;
byte critical = 0; /* ghost variable
                      for verification only */

active [10] proctype P() {
  do ::
        printf("Non critical section P\n");
        atomic { /* "wait(sem)" */
          sem > 0;
          sem-- 
        }
        /* begin critical section */
        critical++;
        printf("Critical section P\n");
        assert (critical <= 5);
        critical--;
        /* end critical section */
        sem++    /* "signal(sem)" */
  od
}

