byte sem = 1;

active [3] proctype P() {
  do ::
        printf("Non critical section P\n");
        atomic { /* wait(sem) */
          sem > 0;
          sem-- 
        }
        /* begin critical section */
        printf("Critical section P\n");
        /* end critical section */
        sem++    /* signal(sem) */
  od
}

