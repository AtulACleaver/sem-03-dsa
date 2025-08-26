// Questions on Circular Doubly Linked List
// 3. Insert new data after any given data in a circular double-linked list.
// 4. Delete any given position in a circular double-linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* rptr;
    struct node* lptr;
};

struct node *start = NULL;

// Insert new data after any given data in a circular double-linked list.
struct node* insert_after_value(struct node* start, int value, int new_data) {
    
    struct node* new_node_5339 = (struct node*)malloc(sizeof(struct node));
    if(new_node_5339 == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    new_node_5339->data = new_data;

    if (start == NULL) {
        // If the list is empty, initialize it
        new_node_5339->rptr = new_node_5339;
        new_node_5339->lptr = new_node_5339;
        return new_node_5339;
    }

    struct node* ptr_5339 = start;
    while (ptr_5339->rptr != start) {
        if (ptr_5339->data == value) {
            new_node_5339->rptr = ptr_5339->rptr;
            new_node_5339->lptr = ptr_5339;
            ptr_5339->rptr->lptr = new_node_5339;
            ptr_5339->rptr = new_node_5339;
            return start;
        }
        ptr_5339 = ptr_5339->rptr;
    }

    printf("Value %d not found in the list.\n", value);
    free(new_node_5339);
    return start;
}

// example input output


// Example input output
// Input: 1. Insert after a value
//        2. Delete a position
//        3. Display list
//        4. Exit
// Output: Displays the current state of the list after each operation

// Delete any given position in a circular double-linked list.
struct node* delete_position(struct node* start, int pos_5339) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    struct node* ptr_5339 = start;
    int count = 1;

    // If the position is 1, we need to delete the start node
    if (pos_5339 == 1) {
    struct node* ptr_1_5339 = start->lptr;
    if (start->rptr == start) { // Only one node
        free(start);
        return NULL;
    }
    ptr_1_5339->rptr = start->rptr;
    start->rptr->lptr = ptr_1_5339;
    free(start);
    return ptr_1_5339->rptr;
}

    // Traverse to the node just before the position
    while (ptr_5339->rptr != start && count < pos_5339 - 1) {
        ptr_5339 = ptr_5339->rptr;
        count++;
    }

    // If we found the position
    if (count == pos_5339 - 1 && ptr_5339->rptr != start) {
        struct node* to_delete = ptr_5339->rptr;
        ptr_5339->rptr = to_delete->rptr;
        to_delete->rptr->lptr = ptr_5339;
        free(to_delete);
    } else {
        printf("Position %d is out of bounds.\n", pos_5339);
    }

    return start;
}

// sample input output for the function above
// Input: 1. Insert after a value
//        2. Delete a position
//        3. Display list
//        4. Exit
// Output: Displays the current state of the list after each operation
//example list
// 1 <-> 2 <-> 3 <-> 4
// input: 2
// output: 1 <-> 2 <-> 5 <-> 3 <-> 4

    // Display the circular doubly linked list
void display_list(struct node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* ptr_5339 = start;
    while (ptr_5339->rptr != start)
    {
        printf("%d ", ptr_5339->data);
        ptr_5339 = ptr_5339->rptr;
    }
    printf("%d ", ptr_5339->data);  // Print the last node's data

    printf("\n");
}

int main(){

    int choice_5339=0, value_5339, data_5339, pos_5339;

    while (choice_5339 != 4) {
        printf("1. Insert after a value\n");
        printf("2. Delete a position\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch (choice_5339) {
            case 1:
                printf("Enter the value after which to insert: ");
                scanf("%d", &value_5339);
                printf("Enter the new data to insert: ");
                scanf("%d", &data_5339);
                start = insert_after_value(start, value_5339, data_5339);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos_5339);
                start = delete_position(start, pos_5339);
                break;
            case 3:
                display_list(start);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}