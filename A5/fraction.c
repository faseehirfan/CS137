#include <stdio.h>
#include <assert.h>
#include "fraction.h"

struct fraction checkNegative (struct fraction a){
    if (a.numerator < 0){
        a.numerator *= -1;
        a.denominator *= -1;
    }
    
    return a;
}

int gcd ( int a , int b ){
if ( b ==0)
return a ;
return gcd (b , a % b );
}

struct fraction fractionCreate(int numerator, int denominator){
    struct fraction newfraction = {numerator / gcd (numerator, denominator), denominator / gcd (numerator, denominator)};
    return  checkNegative(newfraction);
}

int get_numerator(struct fraction a){
    return a.numerator;
}

int get_denominator(struct fraction a){
    return a.denominator;
}

struct fraction fractionAdd(struct fraction a, struct fraction b){ //returns a + b (reduced fraction).
    struct fraction newfraction = {(a.numerator*b.denominator + a.denominator*b.numerator) , (a.denominator * b.denominator) };
    int multiple = gcd(newfraction.numerator, newfraction.denominator);
    
    newfraction.numerator = newfraction.numerator / multiple;

    newfraction.denominator = newfraction.denominator / multiple;
    return checkNegative(newfraction);
}

struct fraction fractionSubtract(struct fraction a, struct fraction b){//returns a – b (reduced fraction).
    struct fraction newfraction = {(a.numerator*b.denominator - a.denominator*b.numerator) , (a.denominator * b.denominator) };
    int multiple = gcd(newfraction.numerator, newfraction.denominator);
    
    newfraction.numerator = newfraction.numerator / multiple;

    newfraction.denominator = newfraction.denominator / multiple;
    return checkNegative(newfraction);
}

struct fraction fractionMultiply(struct fraction a, struct fraction b){ //returns a * b (reduced fraction).
    struct fraction newfraction = {(a.numerator*b.numerator) , (a.denominator * b.denominator) };
    int multiple = gcd(newfraction.numerator, newfraction.denominator);
    
    newfraction.numerator = newfraction.numerator / multiple;

    newfraction.denominator = newfraction.denominator / multiple;

    
    return checkNegative(newfraction);
}

struct fraction fractionDivide(struct fraction a, struct fraction b) { //returns a / b (reduced fraction)
    struct fraction newfraction = {(a.numerator*b.denominator) , (a.denominator * b.numerator) };
    int multiple = gcd(newfraction.numerator, newfraction.denominator);
    
    newfraction.numerator = newfraction.numerator / multiple;

    newfraction.denominator = newfraction.denominator / multiple;
    return checkNegative(newfraction);
}
