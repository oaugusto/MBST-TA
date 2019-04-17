#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graph.h"
#include "dfs.h"
#include "median.h"

#define earthRadiusKm 6371.0

double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

int distanceEarthKm(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lat2r, lon1r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r-lat1r)/2);
    v = sin((lon2r-lon1r)/2);
    return (int) 2.0 * earthRadiusKm * asin(sqrt(u*u+cos(lat1r)*cos(lat2r)*v*v));
}

int main(int argc, char* argv[]) {
    int n, i, j;
    double p1, p2;

    FILE *fp;
    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &n);

    double cities[n][2];
    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf %lf", &cities[i][0], &cities[i][1]);
    }

    graph* g = makeGraph(n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                insertEdge(g, i, j, distanceEarthKm(cities[i][0], cities[i][1], cities[j][0], cities[j][1]));
            }
        }
    }

    printGraph(g, n);

    //printf("%d\n", isConnectDFS(g, n));
    
    removeGraph(g);

    return 0;
}
