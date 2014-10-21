byte sem = 1;

active [2] proctype P() {
  do ::
        printf("Non critical section P\n");
        /* begin critical section */
        atomic { /* wait(sem) */
          sem > 0;
          sem-- 
        }
        printf("Critical section P\n");
        sem++    /* signal(sem) */
        /* end critical section */
  od
}

active proctype Q() {
	assert (sem < 2)
}


