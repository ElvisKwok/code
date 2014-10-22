#define N 5
active proctype ARRAY() {
    int a[N];
    int prod = 1;

    int i;
    for(i : 0 .. N-1) {
        if
            :: a[i] = 1
            :: a[i] = 2
            :: a[i] = 3
            :: a[i] = 4
            :: a[i] = 5
        fi
        printf("a[%d] = %d ", i, a[i]);
        prod = prod * a[i];
    }

    assert(prod >= 0);
    for(i : 0 .. N-1) {
        assert(prod >= a[i]);
    }
    printf("\nThe product is: %d\n", prod)
}
