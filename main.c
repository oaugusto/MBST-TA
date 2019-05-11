#include <stdio.h>
#include <stdlib.h>

#include "include/types.h"
#include "include/graph.h"
#include "include/median.h"
#include "include/mbst.h"
#include "include/distance.h"
#include "include/mst.h"

typedef struct place {
    double latitude;
    double longitude;
} place; 

int main(int argc, char* argv[]) {

    int n = 0, i = 0, j = 0;
    double p1 = 0, p2 = 0;

    FILE *fp = NULL;
    place* cities = NULL; //keep cities latitude and longitute

    graph* g = NULL;

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
    
    g = makeGraph(n);

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            int dist = distanceEarthKm(cities[i].latitude, 
                        cities[i].longitude, cities[j].latitude, cities[j].longitude);
            insertEdge(g, i, j, dist);
        }
    }

    // printGraph(g);
    
    printf("bottleneck for Camerini algorthm: %d\n", mbst(g));
    printf("bottleneck for Prim algorithm: %d\n", mst_prim(g));

    removeGraph(g);

    free(cities);

    return 0;
}