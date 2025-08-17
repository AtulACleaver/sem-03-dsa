// write a code to implement a double ended queue where enqueue/ dequeue can happen from both ends use and array internally

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int capacity;
    int *array;
};

// Function to create a deque
struct queue* createDeque(int capacity) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = 0;
    q->array = (int*)malloc(capacity * sizeof(int));
    return q;
}

// Check if deque is full
int isFull(struct queue* q) {
    return ((q->front == 0 && q->rear == q->capacity - 1) ||
            (q->front == q->rear + 1));
}

// Check if deque is empty
int isEmpty(struct queue* q) {
    return (q->front == -1);
}

// Insert at front
void enqueueFront(struct queue* q, int key) {
    if (isFull(q)) {
        printf("Overflow: Cannot insert %d\n", key);
        return;
    }

    // First element insertion
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    }
    else if (q->front == 0)
        q->front = q->capacity - 1;
    else
        q->front--;

    q->array[q->front] = key;
}

// Insert at rear
void enqueueRear(struct queue* q, int key) {
    if (isFull(q)) {
        printf("Overflow: Cannot insert %d\n", key);
        return;
    }

    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    }
    else if (q->rear == q->capacity - 1)
        q->rear = 0;
    else
        q->rear++;

    q->array[q->rear] = key;
}

// Delete from front
void dequeueFront(struct queue* q) {
    if (isEmpty(q)) {
        printf("Underflow: Deque is empty\n");
        return;
    }

    printf("Removed from front: %d\n", q->array[q->front]);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front == q->capacity - 1)
        q->front = 0;
    else
        q->front++;
}

// Delete from rear
void dequeueRear(struct queue* q) {
    if (isEmpty(q)) {
        printf("Underflow: Deque is empty\n");
        return;
    }

    printf("Removed from rear: %d\n", q->array[q->rear]);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->rear == 0)
        q->rear = q->capacity - 1;
    else
        q->rear--;
}

// Display deque
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->array[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

// Driver
int main() {
    int capacity = 5;
    struct queue* dq = createDeque(capacity);

    enqueueRear(dq, 10);
    enqueueRear(dq, 20);
    enqueueFront(dq, 5);
    enqueueFront(dq, 1);
    display(dq);

    dequeueFront(dq);
    display(dq);

    dequeueRear(dq);
    display(dq);

    enqueueRear(dq, 30);
    enqueueFront(dq, 40);
    display(dq);

    return 0;
}
