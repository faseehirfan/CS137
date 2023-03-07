#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool divide(int a, int b){
    // base cases
    if (b == 0){
        return true;
    }
    if(a > b){
        return false;
    }
    if (a < 0){
        a = -a; 
    }
    if (b < 0){
        b = -b;
    }

    return divide( a, b - a);                              
}


int IntegerDivision(int a, int b){
    if (a < b){
        return 0;
    }

    return IntegerDivision(a - b, b) + 1; 
}
