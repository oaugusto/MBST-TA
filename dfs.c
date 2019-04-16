#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "dfs.h"


void dfs(int node, int* visited, graph* g) {
    pointer next = NULL;

    visited[node] = 1;

    for (next = g->edges[node]; next != NULL; next = next->next) {
        //visited for the first time
        if (visited[next->id] == 0) {
            dfs(next->id, visited, g);
        }
    }
}


int isConnectDFS(graph* g) {
    int i = 0;
    int* visited = (int*)calloc(g->nNodes, sizeof(int));

    //DFS
    dfs(0, visited, g);

    //verify if all nodes were visited
    for (i = 0; i < g->nNodes; i++) {
        if (visited[i] == 0) {
            free(visited);
            return 0;
        }
    }

    free(visited);
    return 1;
}