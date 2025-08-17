// Q3. using 2 stacks make a queue

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int capacity;
    int *array;
};

struct stack* createStack(int capacity) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int*)malloc(capacity * sizeof(int));
    return s;
}

struct queue {
    struct stack* s1;
    struct stack* s2;
};

struct queue* createQueue(int capacity) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->s1 = createStack(capacity);
    q->s2 = createStack(capacity);
    return q;
}

int isQueueEmpty(struct queue* q) {
    return isEmpty(q->s1) && isEmpty(q->s2);
}

void enqueue(struct queue* q, int item) {
    push(q->s1, item);
}

int dequeue(struct queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            push(q->s2, pop(q->s1));
        }
    }
    return pop(q->s2);
}

void freeQueue(struct queue* q) {
    freeStack(q->s1);
    freeStack(q->s2);
    free(q);
}

int main() {
    struct queue* myQueue = createQueue(5);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Dequeued element is %d\n", dequeue(myQueue));

    freeQueue(myQueue);

    return 0;
}
