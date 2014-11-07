#define NUM_PHIL 4
int fork[4] = 0;
	
proctype phil(int d){
	do
		::printf("Philosopher %d is thinking\n", d);
		atomic {
			fork[d] == 0 && fork[(d+NUM_PHIL-1)%NUM_PHIL] == 0;
			fork[d]++;
			fork[(d+NUM_PHIL-1)%NUM_PHIL]++
		}
		printf("Philosopher %d is eating with fork %d and %d\n", d, d, (d+NUM_PHIL-1)%NUM_PHIL);
		assert(fork[d] <= 1);
		assert(fork[(d+NUM_PHIL-1)%NUM_PHIL] <= 1);
		fork[d]--;
		fork[(d+NUM_PHIL-1)%NUM_PHIL]--;
	od
}

init{
	int i = 0;
	do
		::i >= NUM_PHIL	-> break;
		::else -> run phil(i);
		i++
	od
}
