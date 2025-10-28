// 8.1 Write a menu driven program to implement Deques (both Input-restricted and output-restricted) and perform operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

#include <stdio.h>
int deque[100];
int front = -1;
int rear = -1;
int size = sizeof(deque)/sizeof(deque[0]);  

int isFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("%d enqueued at front\n", value);
}

void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("%d enqueued at rear\n", value);
}
int dequeueFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }
    int dequeuedValue = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("%d dequeued from front\n", dequeuedValue);
    return dequeuedValue;
}

int dequeueRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }
    int dequeuedValue = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
    printf("%d dequeued from rear\n", dequeuedValue);
    return dequeuedValue;
}

int peekFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

int peekRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. IsEmpty\n");
        printf("8. IsFull\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);   
        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                value = peekFront();
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 6:
                value = peekRear();
                if (value != -1) {
                    printf("Rear element: %d\n", value);
                }
                break;
            case 7:
                if (isEmpty()) {
                    printf("Deque is empty\n");
                } else {
                    printf("Deque is not empty\n");
                }
                break;
            case 8:
                if (isFull()) {
                    printf("Deque is full\n");
                } else {
                    printf("Deque is not full\n");
                }
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}