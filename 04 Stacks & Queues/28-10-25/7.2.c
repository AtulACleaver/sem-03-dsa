// 7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,  IsEmpty, Traverse using single linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct node {
    int data;
    struct node* next;
};

// Define the structure for the queue
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create a new queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    return q->front == NULL;
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1; // Queue is full
    }
    free(temp);
    return 0; // Queue is not full
}

// Function to enqueue an element to the queue
void enqueue(struct queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("%d enqueued to queue\n", value);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d enqueued to queue\n", value);
}
// Function to dequeue an element from the queue
int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Indicate queue is empty
    }
    struct node* temp = q->front;
    int dequeuedValue = q->front->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n", dequeuedValue);
    return dequeuedValue;
}

// Function to traverse and display the queue elements
void traverse(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}   

// Main function to drive the menu
int main() {
    struct queue* q = createQueue();
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");      

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:     
                dequeue(q);
                break;
            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:     
                traverse(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}