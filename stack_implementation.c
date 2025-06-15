#include<stdio.h>
#include<stdlib.h>

void push(int stack[], int *top, int n, int element){
    if (*top >= n - 1) {
        printf("Stack is full\n");
    } else {
        (*top)++;
        stack[*top] = element;
    }
}

void pop(int stack[],int *top,int n){
    if(*top <= -1){
        printf("stack is empty");
    }
    else{
        (*top)--;
    }
}

int main(){
    int n;
    printf("size: ");
    scanf("%d", &n);

    int stack[n];
    int top = -1;

    push(stack, &top, n, 10);
    push(stack, &top, n, 20);
    push(stack, &top, n, 30);
    push(stack, &top, n, 40);
    push(stack, &top, n, 50);

    printf("Stack elements:\n");
    for(int i = top; i >-1; i--){
        printf("%d\n", stack[i]);
    }
    
    pop(stack, &top,n);
    
    printf("Stack elements:\n");
    for(int i = top; i >-1; i--){
        printf("%d\n", stack[i]);
    }
    
    return 0;
}
