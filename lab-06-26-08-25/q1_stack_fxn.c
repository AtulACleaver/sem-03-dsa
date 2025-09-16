// WAP Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case. a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop

#include <stdio.h>
#include <stdlib.h>

int stack[100], top = -1;

void isEmpty() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

int isFull() {
    if (top == 99) {
        printf("Stack is full\n");
        return 1;
    }
    return 0;
}

void display() {
    if (isEmpty()) {
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int value) {
    if (isFull()) {
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto stack\n", value);
}

void pop() {
    if (isEmpty()) {
        return;
    }
    printf("Popped %d from stack\n", stack[top--]);
}


int main(){
    
    int choice_5339, value_5339;

    while (choice_5339 != 5) {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch (choice_5339) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value_5339);
                push(value_5339);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

