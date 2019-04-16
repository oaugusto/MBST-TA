#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph makeGraph(int size) {
    int i = 0;

    if (size > 0) {
        graph g = (pointer*)malloc(size * sizeof(pointer));
        
        for (i = 0; i < size; i++) {
            g[i] = NULL;
        }

        return g;
    
    } else {

        return NULL;
    
    }
}

void insertEdge(graph g, int a, int b, int w) {
    if (a < 0 || b < 0) {
        return;
    }

    pointer e = (pointer)malloc(sizeof(edge));
    e->id = b;
    e->weight = w;
    e->next = g[a];
    g[a] = e;

}

void printGraph(graph g, int size) {
    int i = 0;
    pointer next = NULL;

    for (i = 0; i < size; i++) {

        printf("node %d:", i);

        for (next = g[i]; next != NULL; next = next->next) {
            printf(" %d", next->id);
        }

        printf("\n");
    }

}

void removeGraph(graph g, int size) {
    int i = 0;
    pointer next = NULL;
    pointer tmp = NULL;

    for (i = 0; i < size; i++) {

        while (next != NULL) {
            tmp = next;
            next = next->next;
            free(tmp);
        }

    }
}