#define N 5
active proctype ARRAY() {
    int a[N];
    int prod = 1;

    int i;
    for(i : 0 .. N-1) {
        if
            :: true -> a[i] = 1
            :: true -> a[i] = 2
            :: true -> a[i] = 3
            :: true -> a[i] = 4
            :: true -> a[i] = 5
        fi
        prod = prod * a[i];
    };


    printf("The product is: %d\n", prod)
}
