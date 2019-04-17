#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "median.h"
#include "mbst.h"

int main(int argc, char* argv[]) {

    int n = 5;
    float median = 0;
    graph* g_sub = NULL;
    graph* com = NULL;

    graph* g = makeGraph(n);

    insertEdge(g, 0, 1, 1);
    insertEdge(g, 1, 0, 1);
    insertEdge(g, 1, 2, 2);
    insertEdge(g, 2, 1, 2);
    insertEdge(g, 2, 3, 3);
    insertEdge(g, 3, 2, 3);
    insertEdge(g, 3, 4, 4);
    insertEdge(g, 4, 3, 4);

    printGraph(g);

    printf("%d\n", g->nEdges);

    /*
    median = getMedianOfEdges(g);
    printf("median:%f\n", median);

    printf("subgraph:\n");
    g_sub = createSubGraph(g, median);
    printGraph(g_sub);

    printf("connected:\n");
    com = connectedComponents(g, g_sub);
    printGraph(com);
    */
    
    printf("bottleneck:%f\n", mbst(g));
    
    removeGraph(g);

    return 0;
}
