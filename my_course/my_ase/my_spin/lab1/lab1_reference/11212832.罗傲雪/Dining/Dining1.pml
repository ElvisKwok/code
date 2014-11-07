#define NUM_PHIL 4


byte forks[4];

ltl safety{[]((forks[0]<=1)&&forks[1]<=1 &&forks[2]<=1)}

proctype phil(int id){

int x;
int y;
//to ensure request fork with smaller id fist, then the larger id.
if
::id<(id+1)%NUM_PHIL ->
 x=id;
y=(id+1)%NUM_PHIL;
::else->
 x=(id+1)%NUM_PHIL; 
y=id;
fi;
do::printf("%d thinking\n",id);
atomic
{
forks[x]==0;
forks[x]++;

}

atomic
{
forks[y]==0;
forks[y]++;
}
printf("%d eating with forks%d and %d\n",id,id,(id+1)%NUM_PHIL);

//release the forks
atomic
{
forks[x]--;
printf("%d release forks %d\n",id,id);
}
atomic
{
forks[y]--;
printf("%d release forks %d\n",id,(id+1)%NUM_PHIL);
}
od
}


init {
int i = 0;
do
:: i >= NUM_PHIL -> break
:: else -> run phil(i);
i++;
od
}

