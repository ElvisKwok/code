byte n = 0;

proctype P() {
  byte temp;
  byte i;
  for (i : 1..5) {
       temp = n;
       n = temp + 1
  }
}

init {
  atomic {
    run P();
    run P()
  }
  (_nr_pr == 1);
  printf("The value is %d\n", n)
}
