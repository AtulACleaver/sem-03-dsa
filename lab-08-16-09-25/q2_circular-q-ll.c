// Implementation of circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front_5339 = NULL;
struct node* rear_5339 = NULL;

void enqueue_5339(int value_5339) {
    struct node* newNode_5339 = (struct node*)malloc(sizeof(struct node));
    newNode_5339->data = value_5339;
    newNode_5339->next = NULL;
    if (front_5339 == NULL && rear_5339 == NULL) {
        front_5339 = newNode_5339;
        rear_5339 = newNode_5339;
        rear_5339->next = front_5339; // Making it circular
    } else {
        rear_5339->next = newNode_5339;
        rear_5339 = newNode_5339;
        rear_5339->next = front_5339; // Maintaining circular nature
    }
    printf("Inserted -> %d\n", value_5339);
}

int dequeue_5339() {
    int value_5339;
    if (front_5339 == NULL && rear_5339 == NULL) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        struct node* temp_5339 = front_5339;
        value_5339 = front_5339->data;
        if (front_5339 == rear_5339) {
            front_5339 = NULL;
            rear_5339 = NULL;
        } else {
            front_5339 = front_5339->next;
            rear_5339->next = front_5339; // Maintaining circular nature
        }
        free(temp_5339);
        printf("Deleted : %d\n", value_5339);
        return value_5339;
    }
}

void display_5339() {
    struct node* temp_5339 = front_5339;
    if (front_5339 == NULL && rear_5339 == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements : ");
        do {
            printf("%d ", temp_5339->data);
            temp_5339 = temp_5339->next;
        } while (temp_5339 != front_5339);
        printf("\n");
    }
}

int main() {
    int choice_5339, value_5339;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);
        switch (choice_5339) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value_5339);
                enqueue_5339(value_5339);
                break;
            case 2:
                dequeue_5339();
                break;
            case 3:
                display_5339();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}