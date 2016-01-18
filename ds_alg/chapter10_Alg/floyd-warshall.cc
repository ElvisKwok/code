/****************************************************************************************
 *
 * Compute All-Shortest Paths
 * A[][] contains the adjacency matrix with A[i][i] presumed to be zero
 * D[][] contains the values of the shortest path
 * N is the numbers of vertices
 * A negative cycle exists iff D[i][i] is set to a negative value
 * Actual path can be computed using Path[][]
 * All arrays are indexed starting at 0
 * NotAVertex is -1
 *
 ****************************************************************************************/

void AllPairs(int **A, int **D, int **Path, int N) {
    int i, j, k;

    // Initial D and Path
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            D[i][j] = A[i][j];
            Path[i][j] = NotAVertex;
        }
    }

    for (k = 0; k < N; k++) {
        // consider each vertex k as an intermediate
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][j] = k;
                    // Path[i][k] = k;      // book mistake?
                }
            }
        }
    }
}
