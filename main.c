#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "include/graph.h"
#include "include/median.h"
#include "include/mbst.h"
#include "include/distance.h"

int main(int argc, char* argv[]) {

    int graphSize = 7;
    
    graph* g = makeGraph(graphSize);

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

    printGraph(g);
    
    printf("\nbottleneck:%f\n", mbst(g));
   
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

    insertEdge(g, 0, 1, 1);
    insertEdge(g, 1, 2, 2);
    insertEdge(g, 2, 3, 3);
    insertEdge(g, 3, 4, 5);
    insertEdge(g, 0, 2, 5);
*/