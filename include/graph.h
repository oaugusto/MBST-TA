#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge* pointer;

typedef struct edge {
    int id;
    float weight;
    pointer next;
} edge;

typedef struct graph {
    int nNodes;
    int nEdges;
    pointer* edges; 
} graph;

graph* makeGraph(int size);

int isEdge(graph* g, int a, int b);

void insertEdge(graph* g, int a, int b, float w);

//void removeEdge(graph* g, int a, int b);

void printGraph(graph* g);

void removeGraph(graph* g);

#endif
