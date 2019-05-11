#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "../include/types.h"
#include "../include/mbst.h"
#include "../include/median.h"

//O(E)
float getMedianOfEdges(graph* g) {
    V_t i = 0, j = 0;
    pointer next = NULL;

    float median = 0;
    float* weights = (float*)malloc(g->nEdges * sizeof(float));

    //for each edge that has weight less or equal than media add
    //and considering only one edge (i < j)
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            if (i < next->id) {
                weights[j] = (float)next->weight;
                j++;
            }
        }
    }

    median = medianFind(weights, g->nEdges);
    free(weights);

    return  median;
}

//O(E)
graph* createSubGraph(graph* g, float median) {
    V_t i = 0;
    pointer next = NULL;

    graph* g_sub = makeGraph(g->nNodes);

    //for each edge that has weight less than median add
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            //the edge doesn't exist and the weight is not greater than median
            if ((i < next->id) && (float)(next->weight) < median) {
                insertEdge(g_sub, i, next->id, next->weight);
            }
        }
    }

    //for each edge that has weight equal to median add
    for (i = 0; i < g->nNodes; i++) {
        for (next = g->edges[i]; next != NULL; next = next->next) {
            //the edge doesn't exist and the weight is not greater than median
            if ((i < next->id) && (float)(next->weight) == median) {
                if (g_sub->nEdges >= (g->nEdges/2)) return g_sub;
                insertEdge(g_sub, i, next->id, next->weight);
            }
        }
    }

    return g_sub;

}

//O(E)
void dfsGroupNodes(V_t node, int color, int* visited, int* sets, graph* g) {
    pointer next = NULL;

    visited[node] = 1;
    sets[node] = color;

    //for each edge leaving the node 
    for (next = g->edges[node]; next != NULL; next = next->next) {
        //if visited for the first time
        if (visited[next->id] == 0) {
            dfsGroupNodes(next->id, color, visited, sets, g);
        }
    }
}

//O(V + E)
//generate a graph with each vertex is a connected component
graph* connectedComponents(graph* g, graph* g_sub) {
    V_t i = 0;
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
            if ((i < next->id) && sets[i] != sets[next->id]) {
                insertEdge(n_g, sets[i], sets[next->id], next->weight);
            }
        }
    }

    free(visited);
    free(sets);

    return n_g;
}

//O(E)
W_t mbst(graph* g) {
    
    W_t bottleneck = 0;

    float median = 0;
    graph* g_sub = NULL;
    graph* components = NULL;

    if (g->nEdges == 1) {        
        pointer vertex = g->edges[0];
        return vertex->weight;
    } else {

        median = getMedianOfEdges(g);
        g_sub = createSubGraph(g, median);
        components = connectedComponents(g, g_sub);

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