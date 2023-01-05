#include <assert.h>
#include <stdio.h>

typedef struct Point{
int x;
int y;
} point;
typedef struct Rectangle {
point bottomLeft; // represents the bottom left corner of the rectangle
int width;
int height;
} rectangle;

int min(int a,int b){
    int min = a;
    if(min > b)
    min = b;
    return min;
}
  
int max(int a,int b){
  int max = a;
  if(max < b)
    max = b;
  return max;
}

rectangle intersection(rectangle rects[], int n){
    int bottomleftX = rects[0].bottomLeft.x;
    int bottomleftY = rects[0].bottomLeft.y;
    int width = rects[0].width;
    int height = rects[0].height;

    for (int i = 1; i < n; i++){
        bottomleftX = max(bottomleftX, rects[i].bottomLeft.x);
    
        bottomleftY = max(bottomleftY , rects[i].bottomLeft.y);

        width = min (width , rects[i].width);

        height = min (height , rects[i].height);
        }

    for (int j = 0; j < n; j++) {
            if(rects[j].bottomLeft.x + rects[j].width < bottomleftX || rects[j].bottomLeft.y + rects[j].height < bottomleftY){
            rectangle zeroAns = {{0, 0}, 0, 0};
            return zeroAns;
            }
    }
    
    rectangle newRec = {{bottomleftX,bottomleftY}, width, height};
    return newRec;
     
}
