#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50

char stack[N], infix[N], postfix[N];
int top = -1;

void push(char);
void intopost();
int precedence(char);
int isempty();
char pop();
void print();

int main() {
    printf("\nEnter the infix expression: ");
    gets(infix);
    intopost();
    print(); 
    return 0;
}

void intopost() {
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
        case '(':
            push(symbol);
            break;
        case ')':
            while((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isempty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while (!isempty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

void push(char c) {
    if (top == N - 1) {
        printf("\nStack Overflow ");
    } else
        top++;
    stack[top] = c;
}

int precedence(char symbol) {
    switch (symbol) {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
    }
}

int isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

char pop() {
    char c;
    if (top == -1)
        printf("\nStack Underflow ");
    else
        top--;
    c = stack[top + 1];
    return c;
}

void print() {
    int i = 0;
    printf("\nThe postfix expression is: ");
    while (postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

