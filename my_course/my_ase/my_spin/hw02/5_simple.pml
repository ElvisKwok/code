active proctype P() {
    int x = 0;
    x++;
    int y = x;
    assert(y==1);
}
