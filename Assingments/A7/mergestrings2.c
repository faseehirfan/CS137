#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


char* merge (char* s1, char* s2){
    int spaces = 1;
    int rep = 0;
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    //checking len of s1
    for (int i = 0; i < strlen(s1); i++){
        if (s1[i] == ' '){
            spaces++;
        }
    }
    //checking len of s2
    for (int i = 0; i < strlen(s2); i++){
        if (s2[i] == ' '){
            spaces++;
        }
    }

    char *newstring = (char*) malloc ((strlen(s1) + strlen(s2) + 2) * sizeof(char));

    while (rep < spaces){
        if(i1>= strlen(s1)){
            newstring[i] = ' ';
            i++;
        }
        if (i2 >= strlen(s2)){
            newstring[i] = ' ';
            i++;
        }
        while (i1 < strlen(s1)){
            if (s1[i1] != ' '){
                newstring[i] = s1[i1];
                printf("%c" , newstring[i]);
                i++;
                i1++; 
                if(i1>= strlen(s1)){
                    newstring[i] = ' ';
                     i++;
                  }
            }
            if (s1[i1] == ' '){
                newstring[i] = ' '; 
                printf("%c" , newstring[i]);
                i++; 
                i1++;
                rep++;
                break;
            }
        }
    
        while (i2 < strlen(s2)){
            if (s2[i2] != ' '){
                newstring[i] = s2[i2];
                printf("%c" , newstring[i]);
                i++;
                i2++;
                if (i2 >= strlen(s2)){
                     newstring[i] = ' ';
                     i++;
                 }
            }
           
            if (s2[i2] == ' '){
                newstring[i] = ' ';
                printf("%c" , newstring[i]);
                i++;
                i2++;
                rep++;
                break;
            }
        }
    }
    printf("\n");
           
    return newstring;
}
int main(void){
    char s1[] = "The brown jumps the dog";
    char s2[] = "quick fox over lazy";

    char *s = merge(s1, s2);
    assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
    free(s);
    char s3[] = "the brown";
    char s4[] = "quick fox is sleeping today";
    s = merge(s3,s4);
    assert(!strcmp(s, "the quick brown fox is sleeping today"));
    free(s);
    char* s5 = "happy to you";
    char* s6 = "birthday";
    s = merge(s5,s6);
    assert(!strcmp(s, "happy birthday to you"));
    free(s);
    return 0;
}