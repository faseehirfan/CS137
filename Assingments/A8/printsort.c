#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printsorted(char* word, int len){
    //int newlen = 0;
    int max = 0;
    int *alphabet = calloc(123, sizeof(int));
    int index = 0;
    for (int i = 0; i < len; i++){
        index = word[i];
        if (97 <= index && index <= 122){
            //newlen++;
            alphabet[index]++;
        }
    }
    //find max value
    for (int i = 97; i < 123; i++){
        if (alphabet[i] > max ) max = alphabet[i];
    }
   
    for (; max > 0; max--){
        for (int i = 97; i < 123; i++){
            if (alphabet[i] == max){
                for (int j = 0; j < max; j++ ){
                    printf("%c", i);
                }
            } 
        }
    }
    printf("\n");
    free(alphabet);
}

//int main(void){
//printsorted("hello world!!!", strlen("hello world!!!"));
//printsorted("aaalllllbbdeeeh", strlen("eeelllllbbdaaah"));
//printsorted("hello_world!!!", strlen("hello_world!!!"));
//return 0;
//}