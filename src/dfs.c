#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"
#include "../include/dfs.h"


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


//return 1 if the graph is connected or 0 otherwise
int isConnectDFS(graph* g) {
    V_t i = 0;
    V_t* visited = (V_t*)calloc(g->nNodes, sizeof(V_t));

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
