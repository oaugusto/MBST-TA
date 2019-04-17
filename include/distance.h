#ifndef DISTANCE_H
#define DISTANCE_H

#define earthRadiusKm 6371.0

double deg2rad(double deg);

int distanceEarthKm(double lat1d, double lon1d, double lat2d, double lon2d);

#endif