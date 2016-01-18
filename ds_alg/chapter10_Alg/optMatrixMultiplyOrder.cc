/****************************************************************************************
 *
 * Compute optimal ordering of matrix multiplication
 * C contains number of columns for each of the N matrices
 * C[0] is the number of rows in matrix 1 as well
 * Minimum number of multiplication is left in M[1][N] -- from matrix 1 to matrix N
 * Actual ordering is computed via another procedure using LastChange
 * M and LastChange are indexed starting at 1, instead of 0
 * Note: Entries below main diagonals of M and LastChange are meaningless and unitialized
 *
 ****************************************************************************************/

void optMatrixMultiplyOrder(const long C[], int N, long **M, int **LastChange) {
    int i, k, left, right;
    long thisM;
    
    for (left = 1; left <= N; left++)
        M[left][left] = 0;
    for (k = 1; k < N; k++)
        for (left = 1; left <= N-k; left++) {
            right = left + k;
            M[left][right] = Infinity;  // INT_MAX;
            for (i = left; i < right; i++) {
                thisM = M[left][i] + M[i+1][right] + C[left-1]*C[i]*C[right];
                if (thisM < M[left][right]) {
                    M[left][right] = thisM;
                    LastChange[left][right] = i;
                }
            }
        }
}
