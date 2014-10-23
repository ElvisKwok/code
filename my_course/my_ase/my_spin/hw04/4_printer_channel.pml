chan request = [0] of {byte};  

active [2] proctype computer() {
    do 
        ::  printf("computer %d is requesting the printer\n", _pid);
            request ! _pid;
    od
}

active proctype printer() {
    byte tmp;
    do
        ::  atomic {
                request ? tmp;
                printf("computer %d can print\n", tmp);
            }
    od
}
