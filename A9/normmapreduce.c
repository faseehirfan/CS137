#include <stdio.h>
#include <math.h>
#include <assert.h>

 typedef struct Vector {
 double x, y, z;
 } Vector;

 void EuclideanNorm(void *src, void *dest){
    double square = ((*(Vector*)src).x) * ((*(Vector*)src).x) + ((*(Vector*)src).y) * ((*(Vector*)src).y) + ((*(Vector*)src).z) * ((*(Vector*)src).z);
    *(double *)dest = sqrt(square);
 }

 void sum(void *src, void *dest) {
    *(double *)dest = *(double *)dest + *(double *)src;
 }
