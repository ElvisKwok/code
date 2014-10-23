chan myChan = [0] of {byte}
byte value  = 0;
int i = 0;
active proctype P() {
    do
        :: i < 10 ->
            myChan ! i;
            i++;
        :: else -> break;
    od
}

active proctype Q() {
    do
        :: myChan ? value ->
                printf("receive value %d\n", value)
        :: i >= 10 -> break;
    od
}   
