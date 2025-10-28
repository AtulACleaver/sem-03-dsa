// 6.2 Write a menu-driven program to create a stack using linked list and perform the following operation using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack
struct node {
    int data;
    struct node* next;
};

struct node *top = NULL; // Initialize top of stack

// Function to push an element onto the stack
void push(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Indicate stack is empty
    }
    struct node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", poppedValue);
    return poppedValue;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to display the stack elements
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Main function to drive the menu
int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);   
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}  