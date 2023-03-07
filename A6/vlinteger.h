#ifndef VLINTEGER_H
#define VLINTEGER_H


struct linteger {
int length;
int *arr; // array of digits to represent a very long positive integer, most left digit is in index 0.
};
struct linteger *vlintegerCreate(void);
// free the memory
void vlintegerDestroy(struct linteger *v);
// reads digits of a very long integer and stores them in t1.
void vlintegerRead(struct linteger *t1);
//prints the length then prints the digits with no spaces in between ended by \n.
//check the exact format and the additional text printed in the sample executions
void vlintegerPrint(struct linteger *t1);
// returns the addition of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2);
// returns the multiplication of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2);

#endif