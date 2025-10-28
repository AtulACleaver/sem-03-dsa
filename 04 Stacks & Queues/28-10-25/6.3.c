// 6.3 Write a program to convert infix expression to postfix expression using stack.

#include <stdio.h>
#include <stdlib.h>

int arr[100];
int top = -1;

void push(int x) {
    arr[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return arr[top--];
}

int isEmpty() {
    return top == -1;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return arr[top];
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch; // Add operand to postfix expression
        } else if (ch == '(') {
            push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop(); // Pop until '(' is found
            }
            pop(); // Remove '(' from stack
        } else { // Operator
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop(); // Pop higher or equal precedence operators
            }
            push(ch); // Push current operator onto stack
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop(); // Pop all remaining operators
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}