#include <assert.h>
#include <stdio.h>
#include "event.h"


int combineint (int hour, int min){
    int newint = hour*100 + min;
    return newint;
}
 
int freetime (struct event schedule[], int n, int hour, int min){
    int start , end, check = 0;
    for (int i = n-1 ; i >=0 ; i --){
        start = combineint(schedule[i].start.hour, schedule[i].start.minute);
        end = combineint(schedule[i].end.hour, schedule[i].end.minute);
        check = combineint(hour, min);
        if (start <= check && check < end) return 0;
    }
    return 1;
}