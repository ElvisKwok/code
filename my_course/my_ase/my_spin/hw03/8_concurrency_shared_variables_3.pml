byte b = 0;

proctype P() {
  byte tmp = 0;
  atomic {
    tmp = b;
    tmp++;
    b=tmp
  }
}

init {
  atomic {
    run P();
    run P()
  }
  /* wait for Ps to finish:*/
  (_nr_pr == 1);
  /*
  printf("b = %d\n", b)
  */
  assert(b == 2)
}
