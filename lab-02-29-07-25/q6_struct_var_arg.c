// Structure variable as argument in C

#include <stdio.h>
struct point {
    int x;
    int y;
};

void display(struct point p){
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}

int main(){
    struct point p1;
    printf("Enter x coordinate: ");
    scanf("%d", &p1.x);
    printf("Enter y coordinate: ");
    scanf("%d", &p1.y);

    display(p1);

    return 0;
}