#define NUM_PHIL    5
bool fork[NUM_PHIL] = {0, 0, 0, 0, 0}

ltl {[](fork[0]<=1 && fork[1]<=1 && fork[2]<=1 && fork[3]<=1 && fork[4]<=1)} 
proctype phil(int id) {
    do
        ::  printf("Philosopher %d is thinking\n", id);
            atomic {
                fork[id] == 0 && fork[(id+1)%NUM_PHIL] == 0;
                fork[id]++;
                fork[(id+1)%NUM_PHIL]++;
            }

            printf("Philosopher %d is eating with fork %d and %d\n", id, id, (id+1)%NUM_PHIL);

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
