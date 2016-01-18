/*
 * Starting vertex: S.
 * 
 * Table T(Initial state):
 *      v   known     dist     path
 *      ---------------------------
 *      v1    0     Infinity    0
 *      v2    0     Infinity    0
 *      v3    0         0       0
 *      v4    0     Infinity    0
 *      v5    0     Infinity    0
 *      v6    0     Infinity    0
 *      v7    0     Infinity    0
 *      ---------------------------
 *      Q:        v3
 *      
 */

void SSSP_unweighted_BFS(Table T) {
    Queue Q;
    Vertex V, W;
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);
    Enqueue(S, Q)
    while (!IsEmpty(Q)) {
        V = Dequeue(Q);
        T[V].known = true;  // Not really needed
        
        for each W adjacent to V
            if (T[W].Dist == Infinity) {
                T[W].Dist = T[V].dist + 1;
                T[W].path = V;
                Enqueue(W, Q);
            }
    }
    DisposeQueue(Q);
}
