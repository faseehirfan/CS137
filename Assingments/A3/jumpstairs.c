#include <stdio.h>
#include <assert.h>
#include <stdbool.h>   

int jump_stair_v1(int n){
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }

    return jump_stair_v1(n-1) + jump_stair_v1(n -2);
}

int jump_stair_v2(int n){
    if (n == 5){
        return 2;
    }
    if (0 < n < 6 && n % 2 == 0){
        return 2;
    }
    if (n < 6){
        return 1;
    }

    return jump_stair_v2(n-3) + jump_stair_v2(n-6);

}

int jump_stair_v3(int n){
    if (n == 6 || n == 9){
        return 1;  
    }
    if (0 < n < 9){
        return 0;
    }
   

    return jump_stair_v3(n -6) + jump_stair_v3(n -9);
}
