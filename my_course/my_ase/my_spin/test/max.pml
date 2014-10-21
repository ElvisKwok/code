active proctype p() {
    int a = 2, b = 3;
    int max;
    if
        :: a >= b -> max = a
        :: a <= b -> max = b
    fi;
    assert(max==(a>b->a:b))
}
