#include <stdio.h>
#include <string.h>
#include <assert.h>



void reverseConcatenate (void *lhs, void *rhs){
    strcat((char *) rhs, *(char **) lhs);
}

void concatenate (void *lhs, void *rhs){
    char result[1000] = {"\0"}; //initializing an array of max size 1000

    // copying lhs into result, then concatenating rhs with lhs, then copying result into rhs. 
    strcpy((char *)result, *(char **) lhs);
    strcat((char *)result, (char *) rhs);
    strcpy((char *) rhs, (char *)result);
}