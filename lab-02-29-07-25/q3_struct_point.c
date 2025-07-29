// return structure from a pointer

#include <stdio.h>

struct Person{
    char name[30];
    int age;
};

struct Person Employees();

int main(){
    struct Person pe = Employees();
    printf("Name = %s", pe.name);
    printf("Age = %d", pe.age);
    return 0;
}

struct Person Employees(){
    struct Person p;
    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    return p;
}