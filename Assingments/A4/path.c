#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int function_helper (int m, int n, int a [m][n], int x, int y){ // int x tracks the row, int y tracks the coluomns.
    if (m - x == 0 || n - 1 == 0){
        return false;
    }
    if (a[(m-1) - x][(n-1) - y] == 0){
        return false;
    }
    if (x == m-1 && y == n -1){
        return true;
    }

        if (function_helper(m, n, a, x+1, y)){
            return true;
        }
    
        if (function_helper(m, n, a, x, y+1)){
            return true;
        }

        return false;

}

int monotonePath(int m, int n, int a[m][n]){
    int x = 0;
    int y = 0;
    return function_helper(m, n, a, x, y);
}

