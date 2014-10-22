byte n=0;
active [2]proctype p() {
    n = _pid;
    printf("Process %d, n = %d\n", _pid, n);
}
