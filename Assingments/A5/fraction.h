#ifndef FRACTION_H
#define FRACTION_H



struct fraction {
    int numerator;
    int denominator;

};

struct fraction fractionCreate(int numerator, int denominator);

int get_numerator(struct fraction a); //returns the numerator of the fraction a.

int get_denominator(struct fraction a); //returns the denominator of the fraction a.

struct fraction fractionAdd(struct fraction a, struct fraction b);
//returns a + b (reduced fraction).

struct fraction fractionSubtract(struct fraction a, struct fraction b);
//returns a – b (reduced fraction).

struct fraction fractionMultiply(struct fraction a, struct fraction b);
//returns a * b (reduced fraction).

struct fraction fractionDivide(struct fraction a, struct fraction b);
//returns a / b (reduced fraction)



#endif
