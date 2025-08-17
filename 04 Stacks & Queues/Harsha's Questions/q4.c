// Q4. using 2 queues make a stack

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int capacity;
    int *array;
};

struct queue* createQueue(int capacity) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->array = (int*)malloc(capacity * sizeof(int));
    return q;
}

struct stack {
    struct queue* q1;
    struct queue* q2;
};

struct stack* createStack(int capacity) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->q1 = createQueue(capacity);
    s->q2 = createQueue(capacity);
    return s;
}

int isStackEmpty(struct stack* s) {
    return isEmpty(s->q1);
}

void push(struct stack* s, int item) {
    enqueue(s->q1, item);
}

int pop(struct stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1->rear > s->q1->front) {
        enqueue(s->q2, dequeue(s->q1));
    }
    int popped = dequeue(s->q1);
    // Swap the queues
    struct queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return popped;
}

int peek(struct stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1->rear > s->q1->front) {
        enqueue(s->q2, dequeue(s->q1));
    }
    int top = dequeue(s->q1);
    enqueue(s->q2, top);
    // Swap the queues
    struct queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return top;
}

void freeStack(struct stack* s) {
    freeQueue(s->q1);
    freeQueue(s->q2);
    free(s);
}

int main() {
    struct stack* myStack = createStack(5);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("Popped element is %d\n", pop(myStack));
    printf("Top element is %d\n", peek(myStack));

    freeStack(myStack);

    return 0;
}

