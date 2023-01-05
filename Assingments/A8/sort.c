#include <stdio.h>
#include <stdbool.h>


void sort(void *arr, int n, size_t elemsize,
bool (*compare)(const void *a, const void *b),
void (*swap)(void *a, void *b)){
    int a = 0;
    int b;
 
    while (a < n -1) {
    // Find min position
        int min = a ;
        b = a + 1;
        while ( b < n){
            if ( compare (((char *) arr) + b * elemsize, ((char *) arr) + min * elemsize) == 1) min = b ;
            b++;
        }
            // Swap ((char *) arr) + min * elemsize and ((char *) arr) + a * elemsize using swap function
        swap(((char *) arr) + min * elemsize , ((char *) arr) + a * elemsize);
        a++;  
    }
}

