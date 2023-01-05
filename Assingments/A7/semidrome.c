#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

bool palindrome_check ( char *s, int leftbound, int rightbound){
    if (leftbound == rightbound || strlen(s) == 0){
        return false;
    }
    while (leftbound < rightbound){
        if (s[leftbound] != s[rightbound]){
            return false;
        }
        leftbound++;
        rightbound--;
    }
    return true;
}

bool is_helper(char *s , int leftbound, int rightbound){
    if (strlen(s) == 0){
        return false;
    }
    
    if (leftbound >= strlen(s)){
        return true;
    }
    for (; rightbound < strlen(s); rightbound++){
        if (palindrome_check(s, leftbound, rightbound)){
            if(is_helper(s, rightbound + 1, rightbound + 2)){
                return true;
            }
        }
    }

    return false;
}

bool is_semidrome(char *s){
    int leftbound = 0;
    int rightbound = 1;
    
    is_helper(s, leftbound, rightbound);
}
