#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*x,*y,*z,*head;

void print(struct node *head){
    struct node *p = head;
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main(){
    x = (struct node*)malloc(sizeof(struct node));
    y = (struct node*)malloc(sizeof(struct node));
    z = (struct node*)malloc(sizeof(struct node));
    head = (struct node*)malloc(sizeof(struct node));
    
    x->data = 1;
    x->next = y;
    
    y->data = 2;
    y->next = z;
    
    z->data = 3;
    z->next = NULL;
    
    head = x;
    
    print(head);
}
