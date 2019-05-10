#include <stdio.h>
#include "../include/median.h"

float medianFind(float* x, int n) {
    float temp;
    int i, j;

    float median = -1;

    // the following two loops sort the array x in ascending order
    for(i=0; i< n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    median = (n % 2 == 0) ? ((x[n/2] + x[n/2 - 1]) / 2.0): x[n/2];

    for (i = 0; i < n; i++) {
        printf("%.0f ", x[i]);
    }
    printf("\nMedian: %.0f\n\n", median);

    return median;
}