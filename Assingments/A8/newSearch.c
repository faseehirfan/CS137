#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int searcher(int arr[], int len, int x, int BB, int BA){
    int Pos = 0;
    
    if (x < arr[BB] || x > arr[BA] || BB > BA){
        printf("%d not in the range between %d and %d\n", x, arr[BB], arr[BA]);
        return -1;
    }

    if (len == 1){
        if (x == arr[0]) return 0;
        else {
            printf("%d not in the range between %d and %d\n", x, arr[BB], arr[BA]);
            return -1;}
    }
    Pos =  BB + (((double)(BA - BB) / (arr[BA] - arr[BB]))
                 * (x - arr[BB]));

    if (arr[Pos] == x){
        return Pos;
    }

    if (arr[Pos] < x){
        printf("move to search in the range between %d and %d\n" , arr[Pos + 1], arr[BA]);
        return searcher(arr, len, x, Pos+1, BA);
    }
    if (arr[Pos] > x){
        printf("move to search in the range between %d and %d\n", arr[BB], arr[Pos - 1]);
        return searcher(arr, len, x, BB, Pos-1);
    }
}

bool newSearch(int arr[], int len, int x){
    int BB = 0;
    int BA = len - 1;
    printf("start with the range %d to %d\n" , arr[BB], arr[BA]);
    int find = searcher(arr, len, x, BB, BA);
    if (find == -1){
        //printf("%d not in the range between %d and %d\n", x, arr[BB], arr[BA]);
        return false;
    } else {
        printf("%d was found in position %d\n", x, find);
        return true;
    }


}


