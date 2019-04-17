#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"

graph* makeGraph(int size) {
    int i = 0;

    if (size < 0) {
        return NULL;
    }

    //graph struct
    graph* g = (graph*)malloc(sizeof(graph));
    
    g->nNodes = size;
    g->nEdges = 0;

    //adjacent list of edges
    g->edges = (pointer*)malloc(size * sizeof(pointer));

    for (i = 0; i < size; i++) {
        g->edges[i] = NULL;
    }

    return g;
}

void insertEdge(graph* g, int a, int b, float w) {

    if (a < 0 || b < 0) {
	    printf("erro\n");
        return;
    }

    pointer e = (pointer)malloc(sizeof(edge));
    e->id = b;
    e->weight = w;
    e->next = g->edges[a];
    g->edges[a] = e;

    g->nEdges++;

}

void printGraph(graph* g) {
    int i = 0;
    pointer next = NULL;

    for (i = 0; i < g->nNodes; i++) {

        printf("node %d:", i);

        for (next = g->edges[i]; next != NULL; next = next->next) {
            printf(" %d", next->id);
        }

        printf("\n");
    }

}

void removeGraph(graph* g) {
    int i = 0;
    pointer next = NULL;
    pointer tmp = NULL;

    for (i = 0; i < g->nNodes; i++) {

        next = g->edges[i];

        while (next != NULL) {
            tmp = next;
            next = next->next;
            free(tmp);
        }

    }

    free(g);
}
