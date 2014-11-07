#define NUM_PHIL 4
/*Using partial order to avoid deadlock*/
byte forks[NUM_PHIL];


//code for philosopher
proctype phil(int id) {

//for phi-id, it need fork[id] and fork[(id+1)%NUM_PHIL] to eat
do
::printf("philosopher %d is thinking\n",id);
/* entry protocol */
printf("%d is hungry\n",id);
atomic
{
forks[id]==0;
forks[id]++;
printf("%d get its left fork\n",id);
}
atomic
{
 forks[(id+1)%NUM_PHIL]==0;
  forks[(id+1)%NUM_PHIL]++;
assert(forks[id]<=1);
printf("forks[id]=%d\n",forks[id]);
assert(forks[(id+1)%NUM_PHIL]<=1);

printf("%d eating with fork %d and %d\n",id,id,(id+1)%NUM_PHIL);
}
/* exit protocol */
forks[id]--;
forks[(id+1)%NUM_PHIL]--;
od
}

init {

int i = 0;
do
:: i >= NUM_PHIL -> break
:: else -> run phil(i);
i++;
od
}



