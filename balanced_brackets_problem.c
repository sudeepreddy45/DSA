#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100

char s[n];
int top = -1;

void push(char c){
    if(top == n - 1){
        printf("Stack is Full\n");
    } else {
        s[++top] = c;
    }
}

char pop(){
    if(top == -1){
        return '\0';
    } else {
        return s[top--];
    }
}

int isMatching(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr){
    int l = strlen(expr);
    for(int i = 0; i < l; i++){
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatching(topChar, ch)) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main(){
    char expr[n];
    printf("Enter expression: ");
    scanf("%s", expr);
    
    if (isBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
