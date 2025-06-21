#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}


int size(struct node *root){
    if(root == NULL) return 0;
    return 1+size(root->left)+size(root->right);
}


int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct node *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}


int leafnodes(struct node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return leafnodes(root->left) + leafnodes(root->right);
}


int nonleafnodes(struct node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    return 1 + nonleafnodes(root->right) + nonleafnodes(root->left);
}


int fullnodes(struct node *root){
    if(root == NULL) return 0;
    if(root->right != NULL && root->left != NULL) return 1 + fullnodes(root->left) + fullnodes(root->right);
    return fullnodes(root->left) + fullnodes(root->right);
}


int identical(struct node *root,struct node *root2){
    if(root == NULL && root2 == NULL) return 1;
    if(root == NULL || root2 == NULL) return 0;
    if (root->data != root2->data) return 0;
    return identical(root->left,root2->left) && identical(root->right,root2->right);
}


int main(){
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);



    struct node *root2 = createnode(1);
    root2->left = createnode(2);
    root2->right = createnode(3);
    root2->left->left = createnode(4);
    root2->left->right = createnode(5);
    root2->right->left = createnode(6);
    root2->right->right = createnode(7);


    printf("size of tree: %d\n",size(root));
    printf("height of tree: %d\n",height(root));
    printf("number of leaf nodes: %d\n",leafnodes(root));
    printf("number of non-leaf nodes: %d\n",nonleafnodes(root));
    printf("number of full nodes: %d\n",fullnodes(root));
    printf("above trees are identical or not: ");
    if(identical(root,root2)) printf("YES");
    else printf("NO");
}
