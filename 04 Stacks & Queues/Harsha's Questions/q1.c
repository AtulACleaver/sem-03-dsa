// Q1. write code for a stack that uses and array internally

#include <stdio.h>
#include <stdlib.h>

struct stack{
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

int isFull(struct stack* s) {
    return s->top == s->capacity - 1;
}

int isEmpty(struct stack* s) {
    return s->top == -1;
}

void push(struct stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }

    s->array[++(s->top)] = item; // Increment top and then assign item
}

int pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->array[s->top--];
}

int peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->array[s->top];
}

void freeStack(struct stack* s) {
    free(s->array);
    free(s);
}


int main(){
    struct stack* myStack = createStack(5);
    
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    
    printf("Top element is %d\n", peek(myStack));
    
    printf("Popped element is %d\n", pop(myStack));
    
    printf("Top element after pop is %d\n", peek(myStack));
    
    freeStack(myStack);
    
    return 0;
}
