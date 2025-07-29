// Array of structures as fun arguments

#include <stdio.h>

struct student{
    char name[50];
    int roll;
};

void display(struct student st[]);

int main(){
    struct student stu[3] = {
        {"Atul", 1},
        {"Harsha", 2},
        {"SSP", 3}
    };
    display(stu);
    return 0;
}

void display(struct student st[]){
    for(int i=0; i<3; i++){
        printf("Name: %s\n", st[i].name);
        printf("Roll: %d\n", st[i].roll);
    }
}