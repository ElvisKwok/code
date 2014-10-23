bool lock;
proctype P(byte i) {
    do :: 
        printf("Computer%d non-critical action\n", i); 
        atomic {
            bool old;
            atomic {
                old = lock;
                lock = true;
            }
            do 
                :: !old -> break;
                :: else -> skip
            od;
            /* begin critical section */
            printf("Computer %d uses shared printer\n", i);
            /* end critical section */
            lock = false
        }
    od;
}

init {
    run P(1);
    run P(2)
}
