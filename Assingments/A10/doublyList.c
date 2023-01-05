#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef struct dlnode {
int data;
struct dlnode *next;
struct dlnode *prev;
} dlnode;
typedef struct ndlst {
dlnode *head; //points to the first element; otherwise, NULL
dlnode *tail; //points to the last element; otherwise, NULL
int len; // number of elements in the list
} ndlst;

ndlst *dlistCreate(void){
ndlst *ret = malloc(sizeof(ndlst));
ret->head = NULL;
ret->tail = NULL;
ret->len = 0;
return ret;
}

void dlistDestroy(ndlst *lst){ 
    if (lst->head == NULL){
        lst->head = NULL;
        lst->tail = NULL;
        free (lst);
        return;
    }
    else{
        dlnode *temp = lst->head;
        while (temp != NULL){
            dlnode *next = temp->next;
            temp->next= NULL;
            temp->prev = NULL;
            free (temp->next);
            free(temp->prev);
            free(temp);
            temp = next;
            
         }
        lst->head = NULL;
        lst->tail = NULL;
        free (lst);
    }
}
//returns the number of elements in the list
int dlistLength(ndlst *lst){ 
    return lst->len;
}

//Pre: lst is a valid list with a length of at least n where n>=1
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n){
    dlnode *temp = lst->head;
    dlnode *temp2 = NULL;
    if (n ==1 && lst->len == 1){
        free(temp);
        free(lst);
        return;
    }
    if (n == 1){
        lst->head = lst->head->next;
        lst->head->prev = NULL;
        free(temp);
        lst->len --;
        return;
    } else{
        while (n > 1){
            temp = temp->next;
            n--;
        }
        if (temp->next == NULL){
            lst->tail = temp->prev;
            lst->tail->next = NULL;
            free (temp);
            lst->len --;
            return;
        } else{
            temp2 = temp->prev;
            temp2->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            lst->len --;
            return;
        }
    }
}


void addToEmpty (ndlst *lst, int elem){
    dlnode *temp = malloc(sizeof(dlnode));
    temp->prev = NULL;
    temp->data = elem;
    temp->next = NULL;
    lst->head = temp;
    lst->tail = temp;
    lst->len ++;
    return;
}
// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem){
    if (lst->len == 0){
        addToEmpty(lst, elem);
        return;
    }
    dlnode *temp = malloc(sizeof(dlnode));
    temp->prev = NULL;
    temp->data = elem;
    temp->next = NULL;
    temp->next = lst->head;
    lst->head->prev = temp;

    lst->head = temp;
    lst->len ++;
    return;
}
// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem){ 
    if (lst->len == 0){
        addToEmpty(lst, elem);
        return;
    }
    dlnode *temp = malloc(sizeof(dlnode));
    dlnode *traverse;
    traverse = lst->head;

    temp->prev = NULL;
    temp->data = elem;
    temp->next = NULL;

    while(traverse->next!= NULL){
        traverse = traverse->next;
    }

    traverse->next = temp;
    temp->prev = traverse;
    lst->tail = temp;
    lst->len ++;
    return;
}
// lst is a valid list, to be sorted in ascending order
void dlistSort(ndlst *lst){ 
    int n = lst->len;
    int *array = malloc(n*sizeof(int));
    dlnode *temp = lst->head; 
    for (int i = 0; i < n; i++){
        array[i] = temp->data;
        temp = temp->next;
        
    }
    
    for ( int i = 0; i < n - 1 ; i ++) {
        // Find min position
        int min = i ;
        for ( int j = i + 1; j < n ; j ++)
        if ( array [ j ] < array [ min ]) min = j ;
        // Swap
        int temp = array [ min ];
        array [ min ] = array [ i ];
        array [ i ] = temp ;
    }
    temp = lst->head;
    for (int i = 0; i < n; i++){
        temp->data = array[i];
        temp = temp->next;
    }
    free(array);
}
// rotate the list n times to the left, assume lst not empty
void dlistRotateLeft(ndlst *lst, int n){
    dlnode *temp;
    dlnode *temp2;
    for (int i = 0; i < n; i++){
        temp = lst->head; 
        temp2 = lst->tail; 

        lst->head = temp->next;
        lst->tail = temp;

        temp->prev = temp2;
        temp2->next = temp;
        temp->next->prev = NULL;
        temp->next = NULL;
    }
}
// rotate the list n times to the right, assume lst not empty
void dlistRotateRight(ndlst *lst, int n){
    for (int i = 0; i < n; i++){
        dlnode *temp = lst->head; 
        dlnode *temp2 = lst->tail; 

        lst->head = temp2;
        lst->tail = temp2->prev;

        temp2->prev->next = NULL;
        temp2->next = temp;
        temp2->prev = NULL;
    }
}


void dlistPrint(ndlst *lst) // I am using this function to print
// results but don't submit this function
{
dlnode *node = lst->head;
for (; node; node = node->next)
printf("%d ",node->data);
printf("\n");
}

 void dlistPrintReverse(ndlst *lst) // I am using this function to
 // print results but don't submit this function
 {
 dlnode *node = lst->tail;
 for (; node; node = node->prev)
 printf("%d ",node->data);
 printf("\n");
 }


 int main(void)
 {
 ndlst *lst1 = dlistCreate();
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 0);
 dlistAddToEnd(lst1, 10);
 dlistAddToFront(lst1, -20);

 dlistAddToFront(lst1, 0);
 dlistAddToEnd(lst1, 9);
 dlistAddToFront(lst1, -9);
 dlistAddToFront(lst1, 7);
 dlistAddToEnd(lst1, 40);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 7);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistRemoveElem(lst1, 5);
 dlistRemoveElem(lst1, 1);
 dlistRemoveElem(lst1, 5);
 dlistAddToEnd(lst1, 100);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 5);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistSort(lst1);
 dlistPrint(lst1);
 dlistRotateLeft(lst1, 2);
 dlistPrint(lst1);
 dlistRotateRight(lst1, 3);
 dlistPrint(lst1);  
 dlistDestroy(lst1);
 return 0;
 }
