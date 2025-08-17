// Q6. using only one underlying array make two stacks

// 	Stack1 grows from left to right (index 0 → n-1).
// 	Stack2 grows from right to left (index n-1 → 0).
// 	If top1 < top2 - 1, then there’s space to push.
// 	Otherwise, array is full.

// push1 inserts from left side.
// push2 inserts from right side.
// Both share the same array without overlapping.
// pop1 and pop2 handle deletion with underflow checks.


#include <stdio.h>
#include <stdlib.h>


struct TwoStacks {
    int *arr;
    int size;
    int top1, top2;
};

// Create two stacks in one array
struct TwoStacks* createTwoStacks(int n) {
    struct TwoStacks* ts = (struct TwoStacks*) malloc(sizeof(struct TwoStacks));
    ts->size = n;
    ts->arr = (int*) malloc(n * sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
    return ts;
}

// Push in Stack1
void push1(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top1++;
        ts->arr[ts->top1] = x;
    } else {
        printf("Stack Overflow in Stack1\n");
    }
}

// Push in Stack2
void push2(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top2--;
        ts->arr[ts->top2] = x;
    } else {
        printf("Stack Overflow in Stack2\n");
    }
}

// Pop from Stack1
int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int x = ts->arr[ts->top1];
        ts->top1--;
        return x;
    } else {
        printf("Stack Underflow in Stack1\n");
        return -1;
    }
}

// Pop from Stack2
int pop2(struct TwoStacks* ts) {
    if (ts->top2 < ts->size) {
        int x = ts->arr[ts->top2];
        ts->top2++;
        return x;
    } else {
        printf("Stack Underflow in Stack2\n");
        return -1;
    }
}

// Display both stacks
void display(struct TwoStacks* ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++)
        printf("%d ", ts->arr[i]);
    printf("\n");

    printf("Stack2: ");
    for (int i = ts->size - 1; i >= ts->top2; i--)
        printf("%d ", ts->arr[i]);
    printf("\n");
}

// Driver
int main() {
    int n = 10;
    struct TwoStacks* ts = createTwoStacks(n);

    push1(ts, 10);
    push1(ts, 20);
    push2(ts, 100);
    push2(ts, 200);
    display(ts);

    printf("Popped from Stack1: %d\n", pop1(ts));
    printf("Popped from Stack2: %d\n", pop2(ts));
    display(ts);

    return 0;
}
