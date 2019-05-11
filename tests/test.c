#include <stdio.h>

#include "../include/graph.h"

int main(int argc, char **argv) {
 
    float median = -1;
    int g_size = 5;

    graph *g = makeGraph(g_size);
    graph *g_sub = NULL;
    graph *com = NULL;

    insertEdge(g, 0, 1, 1);
    insertEdge(g, 1, 2, 2);
    insertEdge(g, 2, 3, 3);
    insertEdge(g, 3, 4, 5);
    insertEdge(g, 0, 2, 5);

    median = getMedianOfEdges(g);
    printf("median:%f\n", median);

    printf("subgraph:\n");
    g_sub = createSubGraph(g, median);
    printGraph(g_sub);

    printf("connected:\n");
    com = connectedComponents(g, g_sub);
    printGraph(com);

/* 
    insertEdge(g, 0, 1, 10);
    insertEdge(g, 1, 2, 10);
    insertEdge(g, 2, 3, 10);
    insertEdge(g, 3, 4, 10);
    insertEdge(g, 0, 2, 10);

    //0a 1b 2c 3d 4e 5f 6g wikipedia graph
    insertEdge(g, 0, 1, 7);//ab
    insertEdge(g, 0, 3, 5);//ad
    insertEdge(g, 3, 1, 9);//db
    insertEdge(g, 1, 2, 8);//bc
    insertEdge(g, 1, 4, 7);//be
    insertEdge(g, 2, 4, 5);//ce
    insertEdge(g, 3, 4, 15);//de
    insertEdge(g, 3, 5, 6);//df
    insertEdge(g, 4, 5, 8);//ef
    insertEdge(g, 4, 6, 7);//eg
    insertEdge(g, 5, 6, 11);//fg
 */
    return 0;
}