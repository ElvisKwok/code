byte n = 0;

proctype P() {
  n = n + 1
}

init {
  atomic {
    run P();
    run P()
  }
  /* wait for Ps to finish:*/
  (_nr_pr == 1);
  printf("The value is %d\n", n)
}


