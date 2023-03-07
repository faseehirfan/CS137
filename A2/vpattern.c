#include <stdio.h>

int main(void){
    int n;

    scanf("%d" , &n);

    int columns = n * 2;

        for (int i = 1; i <= n; i++){
            
            for (int output = 1; output <= i; output++){
                printf("%d", output);
            }

            for (int spaces = 0; spaces <= columns - (2*i) - 1; spaces++){
            printf(" ");
            }

            for (int reverse_output = i; reverse_output >= 1; reverse_output--){
                printf("%d", reverse_output);   
            }
            printf("\n");
        }
    }    