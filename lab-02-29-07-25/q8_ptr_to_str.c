// Return a pointer to a structure from the function

#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

struct point *fxn (int a, int b){
    struct point *ptr = (struct point *)malloc(sizeof(struct point));

    ptr->x = a;
    ptr->y = b;

    return ptr;
}

void display(struct point *p){
    printf("Point: (%d, %d)\n", p->x, p->y);
}

int main() {
    struct point *p1 = fxn(10, 20);
    struct point *p2 = fxn(30, 40);

    display(p1);
    display(p2);

    free(p1);
    free(p2);

    return 0;
}