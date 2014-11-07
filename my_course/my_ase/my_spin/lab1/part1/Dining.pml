#define NUM_PHIL    5
bool fork[NUM_PHIL] = {0, 0, 0, 0, 0}

proctype phil(int id) {
    do
        ::  printf("Philosopher %d is thinking\n", id);
            atomic {
                fork[id] == 0;
                fork[id]++;
            }
            atomic {
                fork[(id+1)%NUM_PHIL] == 0;
                fork[(id+1)%NUM_PHIL]++;

                assert(fork[id] <= 1);
                assert(fork[(id+1)%NUM_PHIL] <= 1);
                printf("Philosopher %d is eating with fork %d and %d\n", id, id, (id+1)%NUM_PHIL);
            }

            fork[id]--;
            fork[(id+1)%NUM_PHIL]--;
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
