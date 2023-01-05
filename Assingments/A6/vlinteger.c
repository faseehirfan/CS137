#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vlinteger.h"

int lengthof(long int n){
    int length = 0;
    while (n!=0){
        n /= 10;
        length++;
    }
    return length;
}
//Implement all the functions above in the file vlinteger.c
//The function vlintegerCreate is implemented for you.
struct linteger *vlintegerCreate(void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0; // no values in t1.
    return t1;
    }

void vlintegerDestroy(struct linteger *v){
    free(v->arr);
    free(v);
}

void vlintegerRead(struct linteger *t1){
    t1->length = 0;
    int userInput;
    int number = 0;
    
    while (scanf("%d", &userInput) != 0){
        number *= 10;
        number = number + userInput;
        t1->length++;
    }

    t1->arr = realloc(t1->arr, t1->length * sizeof (int));

    for (int i = t1->length - 1; i >= 0; i--){
        t1->arr[i] = number%10;
        number /= 10;
    }
}

void vlintegerPrint(struct linteger *t1){
    printf("length=%d\n", t1->length);
    for (int i = 0; i < t1->length; i++){
        printf("%d", t1->arr[i]);
    }
    printf("\n");
}

struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){
    struct linteger *tSum = malloc(sizeof(struct linteger));
    tSum->arr = NULL;
    
    int remainder = 0;
    int maxLen = (t1->length >= t2->length) ? t1->length : t2->length;
    int trueT1Len = t1->length - 1;
    int trueT2Len = t2->length - 1;
    int maxLenIndex = maxLen - 1;

    tSum->arr = realloc(tSum->arr, maxLen * sizeof(int));
    tSum->length = 0;

    for(int i = 0; i < maxLen; i++){
        int sone = 0; int stwo = 0;
        if(i + 1 <= t1->length){
            sone = t1->arr[trueT1Len - i];
        }
        if(i + 1 <= t2->length){
            stwo = t2->arr[trueT2Len - i];
        }
        
        int sum = sone + stwo;
        
        sum += remainder;

        int digit = sum % 10;
        remainder = sum/10;

        tSum->arr[maxLenIndex - i] =  digit;

        if(i == maxLen && remainder > 0){
            maxLen += 1;
            tSum->arr = realloc(tSum->arr, maxLen * sizeof(int));

            int d = maxLenIndex - 1;
            while(d >= 0){
                tSum->arr[d + 1] = tSum->arr[d];
                d--;
            }
            tSum->arr[0] = remainder;
        }
    }
    tSum->length = maxLen;

    return tSum;
};

void swap(struct linteger *a, struct linteger *b){
    struct linteger currentProd = *a;
    *a = *b;
    *b = currentProd;
}
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    int remainder = 0;
    struct linteger *ans = malloc(sizeof(struct linteger));
    struct linteger *currentProd = malloc(sizeof(struct linteger));
    ans->arr = NULL;
    currentProd->arr = NULL;
    ans->length = 0;
    int maxLen = (t1->length >= t2->length) ? t1->length : t2->length;
    ans->arr = realloc(ans->arr, maxLen * sizeof(int));

    if(t1->length >= t2->length){
        swap(t1, t2);
    }
    for(int i = t1->length - 1; i >= 0; i--){
        currentProd->arr = realloc(currentProd->arr, maxLen * sizeof(int));
        currentProd->length = maxLen;
        for(int ind = 0; ind < maxLen; ind++){
            if(currentProd->arr[ind] > 0){
                currentProd->arr[ind] = 0;
            }
        }
        
        int i2 = t2->length - 1;
        while(i2 >= 0){
            int prod = (t1->arr[i] * t2->arr[i2]) + remainder;
            remainder = prod / 10;
            currentProd->arr[i2] = prod % 10;
            
            if(i2 == 0 && remainder > 0){
                currentProd->arr = realloc(currentProd->arr, (maxLen + 1) * sizeof(int));
                int d = maxLen - 1;
                while(d >= 0){
                    currentProd->arr[d+1] = currentProd->arr[d];
                    d--;
                }
                currentProd->length += 1;
                currentProd->arr[0] = remainder;
            }
            i2--;
        }

        maxLen += 1;
        remainder = 0;

        struct linteger *deleteLater = ans;
        ans = vlintegerAdd(ans, currentProd);
        vlintegerDestroy(deleteLater);
    }

    vlintegerDestroy(currentProd);

    return ans;
}
