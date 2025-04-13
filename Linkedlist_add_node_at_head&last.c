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


struct node *insertnodeathead(struct node *head){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = 0;
    p->next = head;
    head = p;
    return head;
}

struct node *insertnodeatlast(struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 4;
    temp->next = NULL;
    if(head == NULL){
        return temp;
    }
    struct node* p = head;
    while(p->next){
        p=p->next;
    }
    p->next = temp;
    return head;
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
    printf("Linked List:\n");
    print(head);

    head = insertnodeathead(head);
    printf("After adding a node at head, linked list:\n");
    print(head);
    
    head = insertnodeatlast(head);
    printf("After adding a node at last, linked list:\n");
    print(head);
    
}
