#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "dfs.h"


void dfs(int node, int* visited, graph g, int size) {
    pointer next = NULL;

    visited[node] = 1;

    for (next = g[node]; next != NULL; next = next->next) {
        //visited for the first time
        if (visited[next->id] == 0) {
            dfs(next->id, visited, g, size);
        }
    }
}


int isConnectDFS(graph g, int size) {
    int i = 0;
    int* visited = (int*)calloc(size, sizeof(int));

    if (size < 0) {
        return -1;
    }

    //DFS
    dfs(0, visited, g, size);

    //verify if all nodes were visited
    for (i = 0; i < size; i++) {
        if (visited[i] == 0) {
            free(visited);
            return 0;
        }
    }

    free(visited);
    return 1;
}