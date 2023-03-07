#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void stars (long int  n){
    if (n != 0){
        stars(n / 10);
        if (n / 10 % 10 == n % 10){
            printf("*%ld", n % 10);
        } else {
            printf("%ld", n % 10);
        }
    }
}

