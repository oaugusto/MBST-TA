#include <stdio.h>
#include <stdlib.h>

#include "../include/mbst.h"
#include "../include/median.h"

float getMedianOfEdges(graph* g) {
    int i = 0, j = 0;
    pointer next = NULL;

    float median = 0;
    float* weights = (float*)malloc(g->nEdges * sizeof(float));

    //for each edge that has weight less or equal than media add
    //and considering only one edge (i < j)
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            if (i < next->id) {
                weights[j] = next->weight;
                j++;
            }
        }
    }

    median = medianFind(weights, g->nEdges);
    free(weights);

    return  median;
}

graph* createSubGraph(graph* g, float median) {
    int i = 0;
    pointer next = NULL;

    graph* g_sub = makeGraph(g->nNodes);

    //for each edge that has weight less or equal than media add
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            //the edge doesn't exist and the weight is not greater than median
            if ((!isEdge(g_sub, i, next->id)) && next->weight <= median) {
                insertEdge(g_sub, i, next->id, next->weight);
            } 
        }
    }

    return g_sub;

}

void dfsGroupNodes(int node, int color, int* visited, int* sets, graph* g) {
    pointer next = NULL;

    visited[node] = 1;
    sets[node] = color;

    //for each each leaving node 
    for (next = g->edges[node]; next != NULL; next = next->next) {
        //if visited for the first time
        if (visited[next->id] == 0) {
            dfsGroupNodes(next->id, color, visited, sets, g);
        }
    }
}

//generate a graph with each vertex is a connected component
graph* connectedComponents(graph* g, graph* g_sub) {
    int i = 0;
    pointer next = NULL;

    //one color for each component
    int color = 0;

    //new graph
    graph* n_g = NULL;

    int* visited = (int*)calloc(g_sub->nNodes, sizeof(int));
    int* sets = (int*)calloc(g_sub->nNodes, sizeof(int));

    //DFS: visit all nodes and label each one with the right component
    for (i = 0; i < g_sub->nNodes; i++) {
        if (visited[i] == 0) {
            dfsGroupNodes(i, color, visited, sets, g_sub);
            color++;
        }
    }

    n_g = makeGraph(color);

    //add all edges not in the same component
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            //the edge doesn't exist yet and the vertexes is not in the same set
            if (sets[i] != sets[next->id] && (!isEdge(n_g, sets[i], sets[next->id]))) {
                insertEdge(n_g, sets[i], sets[next->id], next->weight);
            }
        }
    }

    free(visited);
    free(sets);

    return n_g;
}


float mbst(graph* g) {
    int i = 0;
    pointer next = NULL;

    float bottleneck = 0;

    float median = 0;
    graph* g_sub = NULL;
    graph* components = NULL;

    if (g->nEdges == 1) {
        
        //find the first and unique edge 
        for (i = 0; i < g->nNodes; i++) {
            for (next = g->edges[i]; next != NULL; next = next->next) {
                return next->weight;
            }
        }

    } else {

        median = getMedianOfEdges(g);
        g_sub = createSubGraph(g, median);
        components = connectedComponents(g, g_sub);

        //printf("subgraph:%d\n", g_sub->nNodes);
        //printGraph(g_sub);
        //printf("componentes:%d\n",components->nNodes);
        //printGraph(components);
        //printf("\n\n");

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

    return bottleneck;

}
