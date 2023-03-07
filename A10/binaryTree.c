#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct bstnode {
int item;
struct bstnode *left;
struct bstnode *right;
};
struct bst {
struct bstnode *root;
int count; // number of integers in the tree
};

struct bst *bst_create(void)
{
struct bst *t = malloc(sizeof(struct bst));
t->root = NULL;
t->count = 0;
return t;
}

void destroy(struct bstnode *node)
{
if (node != NULL)
{
destroy(node->left);
destroy(node->right);
free(node);
}
}
void bst_destroy(struct bst *t)
{
destroy(t->root);
free(t);
}
// prints the integers in ascending order ending with \n character. There is a space after each printed
//number, Including the last one and before the \n. If the tree is empty, the function prints nothing.
void print(struct bstnode *node)
{
if (node)
{
print(node->left);
printf("%d ", node->item);
print(node->right);
}
}
void bst_print(struct bst *t)
{
if (t->root)
{
print(t->root);
printf("\n");
}
}

struct bstnode *newnode (int data){
    struct bstnode *new = malloc (sizeof(struct bstnode));
    new->item = data;
    new->left = new->right = NULL;
    return new;   
}

struct bstnode *insert (int num, struct bstnode *node, struct bst *t){
    if(node==NULL) {
        
        struct bstnode* new = newnode(num);
        if(t->count == 0){
            t->root = new;
            t->count = 1;
        }
        else{
            t->count += 1;
        }
        
        return new;
    }
    else if(num == node->item){
        return node;
    }
    else if(num > node->item)
        node->right = insert(num, node->right, t);
    else 
        node->left = insert(num, node->left, t);
    return node;

}

// if num exists, don't add it, otherwise add it as a leaf. The result must be a BST tree
void bst_insert(int num, struct bst *t) { 
    insert (num, t->root, t);
}

// returns the minimal value in non empty BST tree.
int bst_min(struct bst *t){ 
    struct bstnode* temp = t->root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return (temp->item);

}
// returns the maximal value in non empty BST tree.
int bst_max(struct bst *t){ 
    struct bstnode* temp = t->root;
    while (temp->right != NULL)
        temp = temp->right;
    return (temp->item);
}
// returns 1 if val in t, 0 otherwise
int search (struct bst *t, struct bstnode *node, int val){
    struct bstnode *temp = t->root;
    while (temp != NULL){
        if (val > temp->item){
            temp = temp->right;
        } else if (val < temp->item){
            temp = temp->left;
        }
        else return 1;
    }
    return 0;
}
int bst_search(struct bst *t, int val) { 
    return search (t, t->root, val);
    
}
// returns the height of t. the height of the BST tree in the example above is 3. BST with one node has a
//height of 0. BST with no nodes has a height of -1.
int height (struct bst *t, struct bstnode *node){
    if(t->root == NULL){
        return -1;
    }
    int left = height(t, node->left);
    int right = height(t, node->right);
    if (left >= right){
        return left + 1;
    } else{
        return right + 1;
    }
}
int bst_height(struct bst *t){ 
    return height (t, t->root);
    
}

int main(void)
{
struct bst *tree = bst_create();
bst_insert(100, tree);
bst_insert(150, tree);
bst_insert(78, tree);
bst_insert(88, tree);
assert(bst_min(tree)==78);
assert(bst_max(tree)==150);
 bst_print(tree);
 bst_insert(-130, tree);
 assert(tree->count==5);
 bst_insert(-130, tree);
 assert(tree->count == 5);
 bst_print(tree);
 assert(bst_search(tree, 100));
 assert(!bst_search(tree, 90));
 assert(bst_height(tree)==2);
 bst_destroy(tree);
 }
 