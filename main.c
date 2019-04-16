#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "dfs.h"
#include "median.h"

int main(int argc, char* argv[]) {

    int n = 5;
    graph g = makeGraph(n);

    //insertEdge(g, 0, 1, 10);
    //insertEdge(g, 1, 2, 10);
    //insertEdge(g, 3, 4, 10);

    //printGraph(g, n);

    //printf("%d\n", isConnectDFS(g, n));
    
    removeGraph(g, n);

    return 0;
}