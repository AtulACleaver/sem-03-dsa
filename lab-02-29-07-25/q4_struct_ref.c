// Pass structure by reference in C

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    char branch[30];
};

void display(struct Student *s);

int main(){
    struct Student S1;
    printf("Enter Name: ");
    scanf("%[^\n]s", S1.name);
    printf("Enter Roll: ");
    scanf("%d", &S1.roll);
    printf("Enter Branch: ");
    scanf("%s", S1.branch);

    display(&S1);

    return 0;
}

void display(struct Student *s){
    printf("Name: %s\n", s->name);
    printf("Roll: %d\n", s->roll);
    printf("Branch: %s\n", s->branch);
}