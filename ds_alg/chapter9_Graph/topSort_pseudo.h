void topSort(Graph G) {
    Queue Q;
    int count = 0;
    Vertex V, W;
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);
    
    for each vertex V
        if (Indegree[V] == 0)
            Enqueue(V, Q);

    while (!IsEmpty(Q)) {
        V = Dequeue(Q);
        TopNum[V] == ++count;
        for each W adjacent to V
            if (--Indegree[W] == 0)
                Enqueue(W, Q);
    }

    if (count != NumVertex)
        Error("Graph has a circle");

    DisposeQueue(Q);    // free the memory
}
