#define NUM_PHIL 5


chan fork_ch[NUM_PHIL] = [0] of {int};
chan release_ch[NUM_PHIL] = [0] of {int};
chan phil_ch[NUM_PHIL] = [0] of {int};

int fork_used[NUM_PHIL];

ltl fork_unique {[](fork_used[0] < 2 && fork_used[1] < 2 && fork_used[2] < 2 && fork_used[3] < 2 && fork_used[4] < 2)};

proctype phil(int id) {
  int response;
  int fork_left = (id + NUM_PHIL - 1) % NUM_PHIL, fork_right = id;
  do
    ::printf("Philosopher %d thinking\n", id);
      do
        ::fork_ch[fork_left] ! id;
          phil_ch[id] ? response;
          if
            ::response == 1 -> break;
            ::else -> skip;
          fi
      od;
      fork_used[fork_left]++;

      do
        ::fork_ch[fork_right] ! id;
          phil_ch[id] ? response;
          if
            ::response == 1 -> break;
            ::else -> skip;
          fi
      od;
      fork_used[fork_right]++;

      assert(fork_used[fork_left] < 2);
      assert(fork_used[fork_right] < 2);

      printf("Philosopher %d is eating with fork %d and %d\n", id, fork_left, fork_right);

      fork_used[fork_left]--;
      release_ch[fork_left] ! 1;

      fork_used[fork_right]--;
      release_ch[fork_right] ! 1;
  od
}

proctype fork_proc(int fork_id) {
  int cur_serve, next_serve , temp;
  int req;

  if
    ::fork_id % 2 == 0 -> 
      cur_serve = fork_id;
      next_serve = (fork_id + 1) % NUM_PHIL;
    ::else ->
      cur_serve = (fork_id + 1) % NUM_PHIL;
      next_serve = fork_id;
  fi;

  do
    ::fork_ch[fork_id] ? req;
      if
        ::req == cur_serve -> phil_ch[req] ! 1;
          release_ch[fork_id] ? req;
          temp = cur_serve;
          cur_serve = next_serve;
          next_serve = temp;

        ::else -> phil_ch[req] ! -1;
      fi
  od
}

init {
  int i = 0;
  do
    :: i >= NUM_PHIL -> break
    :: else -> run phil(i);
        run fork_proc(i);
        i++
  od
}
