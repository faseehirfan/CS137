#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


char* merge (char* s1, char* s2){
    int spaces1 = 0;
    int spaces2 = 0;
    int spaces = 1;
    int rep = 0;
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    //checking len of s1
    for (int j = 0; j < strlen(s1); j++){
        if (s1[j] == ' '){
            spaces1++;
            spaces++;
        }
    }
    //checking len of s2
    for (int k = 0; k < strlen(s2); k++){
        if (s2[k] == ' '){
            spaces2++;
            spaces++;
        }
    }
    // checking which one has less words, then we can add the space to the end of the one with less words. 
    if (strlen(s2) <= strlen(s1)){
        char *news = (char*) calloc ((strlen(s2) + 2) , sizeof(char));
        for (int i = 0; i < strlen(s2); i++){
            news[i] = s2[i];
        }
        news[strlen(s2)] = ' ';
        news[strlen(s2) + 1] = '\0';
        
// NEXT
        char *newstring = (char*) calloc ((strlen(s1) + strlen(news) + 1) , sizeof(char));

        while (rep <= spaces + 1){
            if (i1 == strlen(s1)){
                break;
            }
            while (i1 < strlen(s1)){
                if (s1[i1] != ' '){
                    newstring[i] = s1[i1];
                    i++;
                    i1++; 
                }
                if (s1[i1] == ' '){
                    newstring[i] = ' '; 
                    i++; 
                    i1++;
                    rep++;
                    break;
                }
            }
    
            while (i2 < strlen(s2)){
                if (news[i2] != ' '){
                    newstring[i] = news[i2];
                    i++;
                    i2++;
                }
           
                if (news[i2] == ' '){
                    newstring[i] = ' ';
                    i++;
                    i2++;
                    rep++;
                    break;
                }
            }
        }
        newstring[i]= '\0';
        free(news);   
        return newstring;

    } else {
        char *news = (char*) calloc ((strlen(s1) + 2) , sizeof(char));
        for (int i = 0; i < strlen(s1); i++){
            news[i] = s1[i];
        }
        news[strlen(s1)] = ' ';
        news[strlen(s1) + 1] = '\0';

        // NEXT
        char *newstring = (char*) calloc ((strlen(news) + strlen(s2) + 1) , sizeof(char));

        while (rep <= spaces + 1){
            if (i2 == strlen(s2)){
                break;
            }
            while (i1 < strlen(news)){
                if (news[i1] != ' '){
                    newstring[i] = news[i1];
                    i++;
                    i1++; 
                }
                if (news[i1] == ' '){
                    newstring[i] = ' '; 
                    i++; 
                    i1++;
                    rep++;
                    break;
                }
            }
    
            while (i2 < strlen(s2)){
                if (s2[i2] != ' '){
                    newstring[i] = s2[i2];
                    i++;
                    i2++;
                }
           
                if (s2[i2] == ' '){
                    newstring[i] = ' ';
                    i++;
                    i2++;
                    rep++;
                    break;
                }
            }
        }
        free(news);
           newstring[i]= '\0';
        return newstring;
    }

}

int main (void){
    char a[] = "hi is test";
    char b[] = "this a case";
    char *c = merge(a,b);
    printf("%s", c);
}
