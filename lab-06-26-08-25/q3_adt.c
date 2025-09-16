// Design a Stack ADT, where you are doing normal PUSH( ), and POP( ) operations at regular intervals. Write a C program to return the highest number present in the stack in O(1) time. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
    int maxItems[MAX];
    int maxTop;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->maxTop = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
        if (s->maxTop == -1 || item > s->maxItems[s->maxTop]) {
            s->maxItems[++s->maxTop] = item;
        }
    }   
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        int item = s->items[s->top--];
        if (item == s->maxItems[s->maxTop]) {
            s->maxTop--;
        }
        return item;
    }
    return -1; // Stack is empty
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; // Stack is empty
}

int getMax(Stack *s) {
    if (!isEmpty(s)) {
        return s->maxItems[s->maxTop];
    }
    return -1; // Stack is empty
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 10);
    push(&s, 3);

    printf("Max: %d\n", getMax(&s));

    pop(&s);
    printf("Max: %d\n", getMax(&s));

    return 0;
}

// Example output
// input: push(5), push(10), push(3)
// output: Max: 10