int n = 0;
bool flag = false;

active proctype p() {
  do
    ::  flag -> break;
    ::  else -> n = 1 - n
  od;
end:
  skip
}

active proctype q() {
  flag = true
}

ltl termination { <> p@end }
ltl nAlways1or0 { [] (n==1 || n==0) }