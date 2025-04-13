#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*one,*two,*three,*head;

void print(struct node *head){
    struct node *p = head;
    
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}

void reverse(struct node *head){
    if(head){
        reverse(head->next);
        printf("%d\n",head->data);
    }
}

int main(){
    head = (struct node*)malloc(sizeof(struct node));
    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    
    one->data = 1;
    one->next = two;
    
    two->data = 2;
    two->next = three;
    
    three->data = 3;
    three->next = NULL;
    
    head = one;
    printf("Printing a data\n");
    print(head);
    printf("Reverse a linked list\n");
    reverse(head);
}
