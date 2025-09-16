// Implementation of Queue using arrays

#include <stdio.h>
#include <stdlib.h>


int que_5339[100];
int front_5339 = -1;
int rear_5339 = -1;

int isEmpty(){
    if(front_5339 == -1 && rear_5339 == -1){
        return 0; //  it is empty
    }

    return 1; // it is not empty
}

int isFull(int size_5339){
    if(rear_5339 == size_5339-1){
        return 0; // it is full
    }

    return 1; // it is not full
}

void enqueue(int size_5339, int value_5339){
    if(isFull(size_5339) == 0){
        printf("Queue is full\n");
        return;
    }

    if(front_5339 == -1 && rear_5339 == -1){
        front_5339 = 0;
        rear_5339 = 0;
    } else {
        rear_5339++;
    }

    que_5339[rear_5339] = value_5339;
    printf("%d enqueued to queue\n", value_5339);
}

void dequeue(){
    if(isEmpty() == 0){
        printf("Queue is empty!");
        return;
    }
    else if(front_5339 == rear_5339){
        front_5339 = -1;
        rear_5339 = -1;
    } else {
        front_5339++;
    }
}

void display(){
    if(isEmpty() == 0){
        printf("List is empty!!");
        return;
    }
    else{
        for (int i = front_5339; i <= rear_5339; i++)
        {
            printf("%d, ", que_5339[i]);
        }
    }
}

int main(){
    int size_5339 = 5;

    // Menu
    int choice_5339, value_5339;

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch(choice_5339){
            case 1:
                printf("Enter value to be enqueued: ");
                scanf("%d", &value_5339);
                enqueue(size_5339, value_5339);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}