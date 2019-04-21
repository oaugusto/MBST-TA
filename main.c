#include <stdio.h>
#include <stdlib.h>

#include "include/graph.h"
#include "include/median.h"
#include "include/mbst.h"
#include "include/distance.h"

typedef struct place {
    double latitude;
    double longitude;
} place; 

int main(int argc, char* argv[]) {

    int n, i, j;
    double p1, p2;

    FILE *fp;
    place* cities; //keep cities latitude and longitute

    if (argc < 2) {
        printf("erro: missing parameters\n");
        return 0;
    }

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &n);

    cities = (place*)malloc(n * sizeof(place));

    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf %lf", &(cities[i].latitude), &(cities[i].longitude));
    }
    
    graph* g = makeGraph(n);

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            insertEdge(g, i, j, distanceEarthKm(cities[i].latitude, 
                        cities[i].longitude, cities[j].latitude, cities[j].longitude));
        }
    }
    
    // printGraph(g);
    
    printf("%d\n", (int) mbst(g));
   
    removeGraph(g);

    free(cities);

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
