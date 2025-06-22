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
struct node *insert(struct node *root,int val){
    if(root==NULL) return createnode(val);
    if(val<root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);
    return root;
}
int minimum(struct node *root){
    while(root != NULL && root->left != NULL)
        root = root->left;
    return root->data;
}
int maximum(struct node *root){
    while(root != NULL && root->right != NULL)
        root = root->right;
    return root->data;
}
int main(){
    int a[] = {10,20,50,5,15,35,25,30};
    int n = sizeof(a)/sizeof(a[0]);
    struct node *root = NULL;
    for(int i=0;i<n;i++){
        root = insert(root,a[i]);
    }
    int x = minimum(root);
    int y = maximum(root);
    
    printf("Minimum node in BST: %d\n",x);
    printf("Maximum node in BST: %d",y);
}
