#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

 double trapezoidal(double (*f) (double), double a, double b, double
 epsilon, int n)
 {
    double area1 = 0; // intializing area variables that we will calculate if the difference
    double area2 = 0;  // is less than episilon.

    double length1 = (b-a) / n; //inital trapezoids
    double length2 = (b-a) / (2*n); // double trapezoids

    double x1 = 0; double x2 = 0;

    // for loop for the previous area
    for (int i = 1; i <= n; i++){
        x1 = f(a + length1 * i);
        x2 = f(a + length1 * (i -1));
        area1 += 0.5*(x1 + x2) * length1 ;
    }

    x1 = 0 ; x2 = 0; // resetting x1 and x2
     // for loop for the new area
    for (int i = 1; i <= (2*n); i++){
        x1 = f(a + length2 * i);
        x2 = f(a + length2 * (i -1));
        area2 += 0.5*(x1 + x2) * (length2);
    }

    // checking if the difference is less than or equal to epsiolon
    if (fabs(area1-area2) <= epsilon){
        return area2;
    }
    // if its not, try again with double the amount of trapezoids. 
    return trapezoidal(f,a,b,epsilon,2*n);
 }

