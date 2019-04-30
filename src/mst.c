#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"
#include "../include/mst.h"

float mst_prim(graph *g) {
    int i = 0, j = 0, counter = 0, min_value = 0, min_index = 0;
    pointer next = NULL;
    int *parent = NULL;
    int *key = NULL;
    int *removed = NULL;

    int max = 0;


    parent = (int*)malloc(g->nNodes * sizeof(int));
    key = (int*)malloc(g->nNodes * sizeof(int));
    removed = (int*)malloc(g->nNodes * sizeof(int));

    for (i = 0; i < g->nNodes; i++) {
        parent[i] = -1;
        key[i] = INF;
        removed[i] = 0;
    } 

    key[0] = 0;

    while (counter != g->nNodes) {

        counter++;

        min_index = -1;
        min_value = INF;
        //remove min value in Q
        for (j = 0; j < g->nNodes; j++) {
            if (removed[j] != 1 && key[j] < min_value) {
                min_value = key[j];
                min_index = j;
            }
        }

        removed[min_index] = 1;

        for (next = g->edges[min_index]; next != NULL; next = next->next) {
            if (removed[next->id] != 1 && (next->weight < key[next->id])) {
                parent[next->id] = min_index;
                key[next->id] = next->weight;
            }
        }
    }


    for (i = 1; i < g->nNodes; i++) {
        if (max < key[i]) {
            max = key[i];
        }
    }

    return max;
}