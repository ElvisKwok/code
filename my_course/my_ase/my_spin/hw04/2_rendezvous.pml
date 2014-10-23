chan com = [0] of {byte}
byte value = 0;
proctype P() {
    byte i = 0;
    do
    ::  if
        :: i >= 5 -> break
        :: else -> printf("Doing something else\n");
                    i++
        fi
    :: com ? value;
    printf("P received: %d\n", value)
    od
}
init {
    atomic { run P() }
    
    int i = 0;
    do  :: i>10 -> break;
        :: i++
    od
    
    end : com ! 100
}
