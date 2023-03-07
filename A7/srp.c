#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



int shortestRepeatingPrefix(char s[]){
    int len = strlen(s);
    int index = 0;
    for (int i = 1; i <= len/2; i++){
        index = 0;
        if (len % i == 0){
            while (index < len){
                if (s[index % i] != s[index]){
                    break;
                }
                index++;
            }
            if (index == len){
                return i;
            }

            
        }
    }
    return strlen(s);
}
