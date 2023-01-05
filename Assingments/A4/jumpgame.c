#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool canComplete(int i, int arr[], int len){
    if (i == (len -1 ) ){
        return true;
    }
    if (i > len -1){
        return false;
    }
    
    if (arr[i] == 0){
        return false;
    }

    for (int j = arr[i]; j > 0; j--){
        
        if (canComplete((i + j), arr, len)){
            return true;
        }  
    }

    return false;
    
}
