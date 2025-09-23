// Implementation of circular queue using arrays

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int front_5339 = -1, rear_5339 = -1;
int que_5339[SIZE];

void enqueue_5339(int value_5339) {
    if ((front_5339 == 0 && rear_5339 == SIZE - 1) || (rear_5339 + 1 == front_5339)) {
        printf("Queue Overflow\n");
    } else {
        if (front_5339 == -1 && rear_5339 == -1) {
            front_5339 = 0;
            rear_5339 = 0;
        } else {
            rear_5339 = (rear_5339 + 1) % SIZE;
        }
        que_5339[rear_5339] = value_5339;
        printf("Inserted -> %d\n", value_5339);
    }
}

int dequeue_5339() {
    int value_5339;
    if (front_5339 == -1 && rear_5339 == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        value_5339 = que_5339[front_5339];
        if (front_5339 == rear_5339) {
            front_5339 = -1;
            rear_5339 = -1;
        } else {
            front_5339 = (front_5339 + 1) % SIZE;
        }
        printf("Deleted : %d\n", value_5339);
        return value_5339;
    }
}

void display_5339() {
    int i_5339;
    if (front_5339 == -1 && rear_5339 == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements : ");
        for (i_5339 = front_5339; i_5339 != rear_5339; i_5339 = (i_5339 + 1) % SIZE) {
            printf("%d ", que_5339[i_5339]);
        }
        printf("%d\n", que_5339[i_5339]);
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