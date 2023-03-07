#include <stdio.h>
int main (void){
    int num = 0;
    int denom = 0;
    int fraction = 0;
    int remainder = 0;

    scanf("%d", &num);

    scanf("%d", &denom);

    fraction = num / denom;
    remainder = num % denom;

    if(remainder > 0){
        fraction ++;
    }
    if (remainder < 0){
        fraction --;
    }
   
   printf("%d\n", fraction);
return 0;
}