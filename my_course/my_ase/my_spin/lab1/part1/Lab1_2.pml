#define NUM_PHIL    4

proctype phil(int id) {
    do
        ::  printf("Philosopher %d is thinking\n", id);
            /* ... */
            printf("Philosopher %d is eating with fork %d and %d\n", id, (id+5)%5, (id+4)%5);
            /* ... */
    od
}

init {
    int i = 0;
    do
        ::  i >= NUM_PHIL -> break;
        ::  else -> run phil(i);
            i++;
    od
}
