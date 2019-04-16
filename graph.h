#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge* pointer;

typedef struct edge {
    int id;
    int weight;
    pointer next;
} edge;

typedef pointer* graph;

pointer* makeGraph(int size);

void insertEdge(graph g, int a, int b, int w);

//void removeEdge(graph g, int a, int b);

void printGraph(graph g, int size);

void removeGraph(graph g, int size);

#endif