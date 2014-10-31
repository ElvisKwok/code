#define NUM_PHIL    4
bool fork[5] = {0, 0, 0, 0, 0}

proctype phil(int id) {
    do
        ::  printf("Philosopher %d is thinking\n", id);
            atomic {
                assert(fork[(id+5)%5] == 0);
                assert(fork[(id+4)%5] == 0);
                fork[(id+5)%5] == 1;
                fork[(id+4)%5] == 1;
            }

            printf("Philosopher %d is eating with fork %d and %d\n", id, (id+5)%5, (id+4)%5);
            atomic {
                fork[(id+5)%5] == 0;
                fork[(id+4)%5] == 0;
            }
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
