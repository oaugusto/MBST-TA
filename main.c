#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "include/graph.h"
#include "include/median.h"
#include "include/mbst.h"
#include "include/distance.h"

int main(int argc, char* argv[]) {

    int graphSize = 5;
    //float median = 0;
    //graph* g_sub = NULL;
    graph* g = makeGraph(graphSize);

    insertEdge(g, 0, 1, 1);
    insertEdge(g, 1, 2, 2);
    insertEdge(g, 2, 3, 3);
    insertEdge(g, 3, 4, 5);
    insertEdge(g, 0, 2, 5);

    printGraph(g);

    printf("\nnumber of edges: %d\n", g->nEdges);
    
    printf("bottleneck:%f\n", mbst(g));
    //median = getMedianOfEdges(g);
    //g_sub = createSubGraph(g, median);
    
    //printf("subgraph:\n");
    //printGraph(g_sub);

    removeGraph(g);
    //removeGraph(g_sub);

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