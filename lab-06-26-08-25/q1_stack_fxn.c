// WAP Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case. a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop

#include <stdio.h>
#include <stdlib.h>

int stack[100], top = -1;

int isEmpty(int stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
        return 1;
    }
    return 0;
}

int isFull(int stack[]) {
    if (top == 99) {
        printf("Stack is full\n");
        return 1;
    }
    return 0;
}

void display(int stack[]) {
    if (isEmpty(stack)) {
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int stack[], int value) {
    if (isFull(stack)) {
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto stack\n", value);
}

void pop(int stack[]) {
    if (isEmpty(stack)) {
        return;
    }
    printf("Popped %d from stack\n", stack[top--]);
}


int main(){
    
}

