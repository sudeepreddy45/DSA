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

void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


struct node **createqueue(int *front,int *rear){
    struct node **queue = (struct node**)malloc(sizeof(struct node*)*100);
    *front = *rear = 0;
    return queue;
}
void enqueue(struct node** queue, int* rear, struct node* node) {
    queue[(*rear)++] = node;
}

struct node* dequeue(struct node** queue, int* front) {
    return queue[(*front)++];
}
void levelorder(struct node *root){
    if (root == NULL) return;

    int front, rear;
    struct node** queue = createqueue(&front, &rear);
    enqueue(queue, &rear, root);
    while (front < rear) {
        struct node* temp = dequeue(queue, &front);
        printf("%d ", temp->data);

        if (temp->left) enqueue(queue, &rear, temp->left);
        if (temp->right) enqueue(queue, &rear, temp->right);
    }
    
}


int main(){
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);
    printf("inorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);
    printf("\nLevel order traversal of a tree: ");
    levelorder(root);
}
