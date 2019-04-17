#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "include/graph.h"
#include "include/median.h"
#include "include/mbst.h"
#include "include/distance.h"

int main(int argc, char* argv[]) {

    int graphSize = 5;
    graph* g = makeGraph(graphSize);

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
    
    printf("bottleneck:%f\n", mbst(g));
    
    removeGraph(g);

    return 0;
}

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