#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print(struct node *head) {
    struct node *p = head;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct node* removeElements(struct node* head, int val) {
    while (head != NULL && head->data == val) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == val) {
            struct node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    struct node *one, *two, *three, *head;
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

    printf("Before deletion:\n");
    print(head);

    head = removeElements(head, 2);

    printf("After deletion:\n");
    print(head);

    return 0;
}
