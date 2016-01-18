/*
 * Starting vertex: Start
 * 
 * Table T(Initial state):
 *      v   known     dist     path
 *      ---------------------------
 *      v1    0         0       0
 *      v2    0     Infinity    0
 *      v3    0     Infinity    0
 *      v4    0     Infinity    0
 *      v5    0     Infinity    0
 *      v6    0     Infinity    0
 *      v7    0     Infinity    0
 *      
 */

 typedef int Vertex;

 struct TableEntry
 {
    List     Header;    // Adjacent list
    int      Known;
    DistType Dist;
    Vertex   Path;
}

#define NotAVertex (-1)
typedef struct Table[NumVertex];

void InitTable(Vertex Start, Graph G, Table T) {
    int i;
    ReadGraph(G, T);
    for (i = 0; i < NumVertex; i++) {
        T[i].Known = False;
        T[i].Dist  = Infinity;
        T[i].Path  = NotAVertex;
    }
    T[Start].dist = 0;
}

void PrintPath(Vertext V, Table T) {
    if (T[V].path != NotAvertex) {
        PrintPath(T[V].Path, T);
        printf(" -> ");
    }
    printf("%d", V);
}

void Dijkstra(Table T) {
    Vertext V, W;
    While (true) {
        V = smallest unknown distance vertex;
        if (V == NotAVertex)
            break;

        T[V].known = true;
        for each W adjacent to V
            if (!T[W].Known) 
                if (T[V].Dist + Cvw < T[W].Dist) {
                    T[W].Dist = T[V].Dist + Cvw;
                    T[W].Path = V;
                }
    }
}
