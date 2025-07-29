// Passing member of the structure as an argument to a function

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
};

void display(char [], int);

int main(){
    struct Student S1;
    printf("Enter Name ");
    scanf("%[^\n]s", S1.name);
    printf("Enter roll: ");
    scanf("%d", &S1.roll);

    display(S1.name, S1.roll);

    return 0;
}

void display(char a[], int b){
    printf("Name: %s", a);
    printf("\nRoll no. %d", b);
}