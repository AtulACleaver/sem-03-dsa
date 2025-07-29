// Passing struct variable as a reference

#include <stdio.h>

struct Point {
    int x;
    int y;
};

void display(struct Point *p) {
    printf("Point: (%d, %d)\n", p->x, p->y);
}

int main() {
    struct Point p1 = {10, 20};
    struct Point p2 = {30, 40};

    display(&p1);
    display(&p2);

    return 0;
}
