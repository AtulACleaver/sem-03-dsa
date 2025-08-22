// Prefix Notation using stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int i, j = 0;
    char temp[MAX];
    int len = strlen(infix);

    // Reverse the infix expression
    for (i = 0; i < len; i++) {
        temp[i] = infix[len - 1 - i];
    }
    temp[len] = '\0';

    // Convert to postfix
    for (i = 0; i < len; i++) {
        char c = temp[i];
        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            pop();  // Remove ')'
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) > precedence(c)) {
                prefix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    // Reverse the prefix expression
    for (i = 0; i < j; i++) {
        temp[i] = prefix[j - 1 - i];
    }
    temp[j] = '\0';
    strcpy(prefix, temp);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
