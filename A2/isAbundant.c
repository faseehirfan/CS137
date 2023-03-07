#include <stdio.h>
int main (void){
    int n = 0;
    int sum_Factors = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n/2; i++){
        if (n % i == 0){
            sum_Factors += i;
        }
    }
    
    if (n < sum_Factors){
        printf("Abundant\n");
    }
    else if (n > sum_Factors){
        printf("Deficient\n");
    }
    else {
        printf("Perfect\n");
    }
    return 0;
}