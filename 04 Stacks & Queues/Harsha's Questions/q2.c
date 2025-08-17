// Q2. write a code for a circular queue that uses an array internally

#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int front;
    int rear;
    int capacity;
    int *array;
};

struct circularQueue* createQueue(int capacity) {
    struct circularQueue* q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->array = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isFull(struct circularQueue* q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int isEmpty(struct circularQueue* q) {
    return q->front == (q->rear + 1) % q->capacity;
}

void enqueue(struct circularQueue* q, int item) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
}

int dequeue(struct circularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    return item;
}

int peek(struct circularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->array[q->front];
}

void freeQueue(struct circularQueue* q) {
    free(q->array);
    free(q);
}

int main() {
    struct circularQueue* myQueue = createQueue(5);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Front element is %d\n", peek(myQueue));

    printf("Dequeued element is %d\n", dequeue(myQueue));

    printf("Front element after dequeue is %d\n", peek(myQueue));

    freeQueue(myQueue);

    return 0;
}
