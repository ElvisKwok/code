byte b = 0;

proctype P() {
  byte tmp;
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
  (_nr_pr == 1) -> assert(b == 2)
}
