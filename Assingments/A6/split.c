#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int ** split(int a[], int n, int p, int *len1, int *len2){
    int lessorequal = 0; int greater = 0;

    for (int i = 0; i < n ; i++){
        if (a[i] <= p) lessorequal += 1;
        else greater += 1;
    }

    *len1 = lessorequal;
    *len2 = greater;

    int *lessarray = malloc(lessorequal * sizeof(int));
    int *greaterarray = malloc(greater * sizeof(int));

    int counter = 0;
    int counter2 = 0;

    for ( int i = 0; i < n; i++){
        if (a[i] <= p) {
            lessarray[counter] = a[i]; 
            counter+= 1;
        }
        else{ 
            greaterarray[counter2] = a[i];
            counter2+= 1;
        }
    }
    
    int **solution = malloc(sizeof(lessarray) + sizeof(greaterarray));
    solution[0] = lessarray;
    solution[1] = greaterarray;
    free(lessarray);
    free(greaterarray);
    return solution;   
}
