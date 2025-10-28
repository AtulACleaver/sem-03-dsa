// 7.3 Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.

#include <stdio.h>


int queue[100];
int front = -1;
int rear = -1;
int size = sizeof(queue)/sizeof(queue[0]);

int isFull() {
    if ((rear + 1) % size == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0; // Initialize front on first enqueue
    }
    rear = (rear + 1) % size;
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}       

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1; // Indicate queue is empty
    }
    int dequeuedValue = queue[front];
    if (front == rear) { // Queue has only one element
        front = rear = -1; // Reset queue after dequeue
    } else {
        front = (front + 1) % size;
    }
    printf("%d dequeued from queue\n", dequeuedValue);
    return dequeuedValue;
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}   