#ifndef MBST_H
#define MBST_H

#include "graph.h"
#include "median.h"

float getMedianOfEdges(graph* g);

graph* createSubGraph(graph* g, float median);

void dfsGroupNodes(int node, int color, int* visited, int* sets, graph* g);

graph* connectedComponents(graph* g, graph* g_sub);

W_t mbst(graph* g);

#endif
