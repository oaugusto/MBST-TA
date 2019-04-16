#ifndef DFS_H
#define DFS_H

void dfs(int node, int* visited, graph g, int size);

int isConnectDFS(graph g, int size);

graph connectedComponets(graph g, int size);

#endif