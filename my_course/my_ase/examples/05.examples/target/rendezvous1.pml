chan request = [0] of { byte };

active proctype Client0() {
  request ! 0;
}

active proctype Client1() {
  request ! 1;
}

active proctype Server() {
  byte client;
end:
  do
    :: request ? client ->
       printf("serving client %d\n",
	      client);
  od
}
