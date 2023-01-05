#include <stdio.h>
#include <assert.h>
#include "functions.h"

int powers_function (int number, int power){
    int answer = 1;
    for (int i = 1; i <= power; i++){
        answer = answer * number;
    }
    return answer;
}
int isSophieGermainPrime(int p){
    for (int i = 2; i <= p/2; i++){
        if (p % i == 0){
        return 0;
        }
     }

    p = 2*p + 1;

    for (int i = 2; i <= p/2; i++){
        if (p % i == 0){
        return 0;
        }
    }
    return 1;
}

int base2nat (int bs, int num){
    int nat = 0;
    int power= 0;
    while (num > 0){
        nat += (num%10) * powers_function(bs,power);
        num/= 10;
        power++;
    }
    return nat;
    }
   

int nat2base (int bs, int num){
    int power = 9;
    int base = 0;
    while (power>= 0){
        if (num/powers_function(bs, power) > 0){
            base += num / powers_function(bs, power) * powers_function(10, power);
            num %= powers_function(bs, power);
        }
        power--;
    }
    return base;
}