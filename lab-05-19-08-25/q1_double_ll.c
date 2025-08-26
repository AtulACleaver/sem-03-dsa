// WAP for the following:-
// 1. Insert at any given position in a double-linked list.
// 2. Delete any given data from a double-linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rptr;
    struct node *lptr;
};

struct node *start = NULL;

// Function to insert a new node at a given position
struct node *insertAtPosition(struct node *start, int pos_5339, int data_5339)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Overflow \n");
        return start;
    }

    new_node->data = data_5339;
    new_node->lptr = NULL;
    new_node->rptr = NULL;

    if (start == NULL)
    {
        if (pos_5339 != 1)
        {
            printf("Position Out of Bounds\n");
            return start;
        }
        else
        {
            start = new_node;
            new_node->rptr = NULL;
            new_node->lptr = NULL;
            return start;
        }
    }

    // Case for beginning
    if (pos_5339 == 1)
    {
        new_node->rptr = start;
        start = new_node;
        return start;
    }

    // Case: in between & end
    struct node *ptr_5339 = start;
    int i = 1;
    while (ptr_5339 != NULL && i < pos_5339 - 1)
    {
        ptr_5339 = ptr_5339->rptr;
        i++;
    }

    if (ptr_5339 == NULL)
    {
        printf("Position out of bounds\n");
        free(new_node);
        return start;
    }

    // Insert at end
    if (ptr_5339->rptr == NULL)
    {
        new_node->lptr = ptr_5339;
        new_node->rptr = NULL;
        ptr_5339->rptr = new_node;
    }
    // Insert in between
    else
    {
        new_node->rptr = ptr_5339->rptr;
        new_node->lptr = ptr_5339;
        ptr_5339->rptr->lptr = new_node;
        ptr_5339->rptr = new_node;
    }
    return start;
    new_node->lptr = ptr_5339->lptr;
    ptr_5339->lptr = new_node;
    return start;
}

// example INPUT OUTPUT
// Input: 1 10
// Output: 10 -> NULL
// Input: 1 20
// Output: 20 -> 10 -> NULL
// Input: 2 30
// Output: 20 -> 30 -> 10 -> NULL
// Input: 3 40
// Output: 20 -> 30 -> 40 -> 10 -> NULL
// Input: 4 50
// Output: 20 -> 30 -> 40 -> 50 -> 10 -> NULL
// Input: 5 60
// Output: 20 -> 30 -> 40 -> 50 -> 60 -> 10 -> NULL

// 2. Delete any given data from a double-linked list.
struct node *delete_data(struct node *start, int data_5339) {
    if (start == NULL) {
        printf("List is empty!\n");
        return start;
    }

    struct node *ptr_5339 = start;

    // Deleting the first node
    if (ptr_5339->data == data_5339) {
        start = ptr_5339->rptr;
        if (start != NULL)
            start->lptr = NULL;
        free(ptr_5339);
        return start;
    }

    while (ptr_5339 != NULL && ptr_5339->data != data_5339) {
        ptr_5339 = ptr_5339->rptr;
    }

    if (ptr_5339 == NULL) {
        printf("Data not found\n");
        return start;
    }

    // Deleting in between or last node
    if (ptr_5339->rptr != NULL)
        ptr_5339->rptr->lptr = ptr_5339->lptr;
    if (ptr_5339->lptr != NULL)
        ptr_5339->lptr->rptr = ptr_5339->rptr;
    free(ptr_5339);

    return start;
}

void display(struct node *start)
{
    struct node *ptr_5339 = start;
    while (ptr_5339 != NULL)
    {
        printf("%d -> ", ptr_5339->data);
        ptr_5339 = ptr_5339->rptr;
    }
    printf("NULL\n");
}

// Sample Input/Output
// Input: 1 10
// Output: 10 -> NULL
// Input: 1 20
// Output: 20 -> 10 -> NULL
// Input: 2 30
// Output: 20 -> 30 -> 10 -> NULL
// Input: 3 40
// Output: 20 -> 30 -> 40 -> 10 -> NULL
// Input: 4 50
// Output: 20 -> 30 -> 40 -> 50 -> 10 -> NULL
// Input: 5 60
// Output: 20 -> 30 -> 40 -> 50 -> 60 -> 10 -> NULL 

int main()
{
    int choice_5339, data_5339, pos_5339;

    while (1)
    {
        printf("1. Insert at position\n");
        printf("2. Delete by value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch (choice_5339)
        {
        case 1:
            printf("Enter position and data: ");
            scanf("%d %d", &pos_5339, &data_5339);
            start = insertAtPosition(start, pos_5339, data_5339);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data_5339);
            start = delete_data(start, data_5339);
            break;
        case 3:
            display(start);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
