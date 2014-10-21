byte    n = 0;

active proctype P() {
  n = 1;
  printf("Proc P, n = %u\n", n)
}

active proctype Q() {
  n = 2;
  printf("Proc Q, n = %u\n", n)
}





































proctype R() {
  assert (n == n)
}


