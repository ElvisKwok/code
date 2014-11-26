#define legal (sem <= 2)
#define empty (sem == 2)
#define full (sem == 0)

byte sem = 2;

active [4] proctype P() {
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


