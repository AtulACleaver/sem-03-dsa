// 6.1 Write a menu driven program to create a stack using array and perform the following operation using function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include <stdio.h>

// Fixed-size array implementation of a stack
int arr[100];     // storage for stack elements
int top = -1;     // index of top element; -1 means stack is empty
int size = 100;   // maximum capacity of the stack

// Return 1 if stack is full, 0 otherwise
int isFull() {
    return top == size - 1;
}

// Return 1 if stack is empty, 0 otherwise
int isEmpty() {
    return top == -1;
}

// Push an item on to the stack.
// If the stack is full, print an error and do not modify the stack.
void push(int item) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    // increment top and place the item at new top
    arr[++top] = item;
}

// Pop an item from the stack and return it.
// If the stack is empty, print an error and return -1 as sentinel.
int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    // return the item at top and then decrement top
    return arr[top--];
}

// Display stack elements from top to bottom.
// If empty, print a message.
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    // print from top index down to 0 so top is shown first
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    // Infinite menu loop; user chooses operations until Exit selected.
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");                      // push an integer on stack
        printf("2. Pop\n");                       // pop and print top element
        printf("3. Check if stack is empty\n");   // check empty status
        printf("4. Check if stack is full\n");    // check full status
        printf("5. Display stack elements\n");    // display all elements
        printf("6. Exit\n");                      // terminate program
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // read value and push it on stack
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                // pop top element and print it if successful
                item = pop();
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                // report whether stack is empty
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 4:
                // report whether stack is full
                if (isFull()) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 5:
                // show current contents of the stack
                display();
                break;
            case 6:
                // exit program cleanly
                return 0;
            default:
                // invalid menu selection
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}