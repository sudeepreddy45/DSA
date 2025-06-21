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
    if(root == NULL) return createnode(val);
    if(val<root->data) 
        root->left=insert(root->left,val);
    else
        root->right = insert(root->right,val);
        return root;
}
struct node *search(struct node *root,int key){
    if(root == NULL) return 0;
    if(root ->data == key) return root;
    if(key<root->data) 
        return search(root->left,key);
    else
        return search(root->right,key);
}
int main(){
    int a[] = {20,30,50,10,15,5,25,35,55};
    int n = sizeof(a)/sizeof(a[0]);
    struct node *root = NULL;
    for(int i=0;i<n;i++){
        root = insert(root,a[i]);
    }
    int key = 18; 
    if(search(root,key)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}
