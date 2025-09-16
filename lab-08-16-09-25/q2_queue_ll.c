// Implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

struct que{
    int data_5339;
    struct que *link;
};

struct que *front_5339 = NULL;
struct que *rear_5339 = NULL;

int isEmpty(){
    if(front_5339 == NULL && rear_5339 == NULL){
        return 1;
    }
    return 0; // it is not empty
}

void enqueue(int value_5339){
    struct que *newNode_5339 = (struct que*)malloc(sizeof(struct que));
    if(newNode_5339 == NULL){
        printf("Memory not allocated!!\n");
        return;
    }

    newNode_5339->data_5339 = value_5339;
    newNode_5339->link = NULL;

    if(rear_5339 == NULL){
        front_5339 = newNode_5339;
    } else {
        rear_5339->link = newNode_5339;
    }
    rear_5339 = newNode_5339;

    printf("%d enqueued to queue\n", value_5339);
}

void dequeue(){
    if(isEmpty() == 1){
        printf("Queue is empty!\n");
        return;
    }

    struct que *temp_5339 = front_5339;
    printf("%d dequeued from queue\n", temp_5339->data_5339);
    front_5339 = front_5339->link;
    if(front_5339 == NULL){
        rear_5339 = NULL;
    }
    free(temp_5339);
}

void display(){
    if(isEmpty() == 1){
        printf("Queue is empty!!\n");
        return;
    }

    struct que *curr = front_5339;
    printf("Queue: ");
    while (curr != NULL){
        printf("%d", curr->data_5339);
        if(curr->link != NULL) printf(" -> ");
        curr = curr->link;
    }
    printf("\n");
}

int main(){

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
                enqueue(value_5339);
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