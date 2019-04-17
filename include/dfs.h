#ifndef DFS_H
#define DFS_H

#include "graph.h"

void dfs(int node, int* visited, graph* g);

int isConnectDFS(graph* g);

#endif