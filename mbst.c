#include <stdio.h>
#include <stdlib.h>

#include "mbst.h"
#include "median.h"

float getMedianOfEdges(graph* g) {
    int i = 0, j = 0;
    pointer next = NULL;

    float median = 0;
    float* weights = (float*)malloc(g->nEdges * sizeof(float));

    //for each edge that has weight less or equal than media add
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[0]; next != NULL; next = next->next) {
            weights[j] = next->weight;
            j++;
        }
    }

    median = median_find(weights, g->nEdges);
    free(weights);

    return  median;
}

graph* createSubGraph(graph* g, float median) {
    int i = 0;
    pointer next = NULL;

    graph* g_sub = makeGraph(g->nNodes);

    //for each edge that has weight less or equal than media add
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[0]; next != NULL; next = next->next) {
            if (next->weight <= median) {
                insertEdge(g_sub, i, next->id);
            } 
        }
    }

    return g_sub;

}

void dfs(int node, int color, int* visited, int* sets, graph* g) {
    pointer next = NULL;

    visited[node] = 1;
    sets[node] = color;

    //for each each leaving node 
    for (next = g->edges[node]; next != NULL; next = next->next) {
        //if visited for the first time
        if (visited[next->id] == 0) {
            dfs(next->id, color, visited, sets, g);
        }
    }
}

//generate a graph with each vertex is a connected component
graph* connectedComponets(graph* g, graph* g_sub) {
    int i = 0;
    pointer next = NULL;

    //one color for each component
    int color = 0;

    //new graph
    graph* n_g = NULL;

    int* visited = (int*)calloc(g_sub->nNodes, sizeof(int));
    int* sets = (int*)calloc(g_sub->nNodes, sizeof(int));

    //DFS
    for (i = 0; i < g_sub->nNodes; i++) {
        dfs(i, color, visited, sets, g_sub);
        color++;
    }

    n_g = makeGraph(color - 1);

    //add all edges not in the same component
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            if (sets[i] != sets[next->id]) {
                insertEdge(n_g, sets[i]; sets[next->id], next->weight);
            }
        }
    }

    free(visited);
    free(sets);

    return n_g;
}


float mbst(graph* g) {

    float bottleneck = 0;

    float median = 0;
    graph* g_sub = NULL;
    graph* components = NULL;

    if (g->nEdges == 1) {
        /*return edge*/
    } else {

        median = getMedianOfEdges(g);
        g_sub = createSubGraph(g, median);
        components = connectedComponets(g, g_sub);

        if (components->nNodes == 1) {
            
            bottleneck = mbst(g_sub);
            removeGraph(g_sub);
            removeGraph(components);

            return bottleneck;
        
        } else {

            bottleneck = mbst(components);
            removeGraph(g_sub);
            removeGraph(components);

            return bottleneck;

        }
        
    }

}