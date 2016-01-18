void dfs(Vertex V) {
    Visited[V] = true;
    for each W adjacent to V
        if (!Visited[W]) 
            dfs(W);
}
