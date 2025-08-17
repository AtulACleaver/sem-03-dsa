/*
    1. Delete from any position from a single linked List
    2. Insert at any position in circular single linked list
    3. Delete any given data in a circular single linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *start = NULL;

// 1. Delete from any position from a single linked List
struct node *delete_pos_sll(struct node *start, int pos_5339) {
    if (start == NULL || pos_5339 < 1) {
        printf("Invalid position or empty list.\n");
        return start;
    }

    struct node *ptr_5339 = start;
    if (pos_5339 == 1) { // delete head
        start = ptr_5339->link;
        free(ptr_5339);
        return start;
    }

    for (int i = 1; ptr_5339 != NULL && i < pos_5339 - 1; i++) {
        ptr_5339 = ptr_5339->link;
    }

    if (ptr_5339 == NULL || ptr_5339->link == NULL) {
        printf("Position does not exist.\n");
        return start;
    }

    struct node *temp_5339 = ptr_5339->link;
    ptr_5339->link = temp_5339->link;
    free(temp_5339);

    return start;
}

// 2. Insert at any position in circular single linked list
struct node *insert_pos_circular_sll(struct node *start, int data_5339, int pos_5339) {
    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    if(new_node_5339 == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    new_node_5339->data = data_5339;

    if (start == NULL) {
        if (pos_5339 != 1) {
            printf("Invalid position for empty list.\n");
            free(new_node_5339);
            return start;
        }
        new_node_5339->link = new_node_5339;
        return new_node_5339;
    }

    if (pos_5339 == 1) {
        struct node *ptr_5339 = start;
        while (ptr_5339->link != start) {
            ptr_5339 = ptr_5339->link;
        }
        ptr_5339->link = new_node_5339;
        new_node_5339->link = start;
        return new_node_5339;  // new start
    }

    struct node *ptr_5339 = start;
    for (int i = 1; i < pos_5339 - 1 && ptr_5339->link != start; i++) {
        ptr_5339 = ptr_5339->link;
    }

    new_node_5339->link = ptr_5339->link;
    ptr_5339->link = new_node_5339;

    return start;
}

// 3. Delete any given data in a circular single linked list
struct node *delete_data_circular_sll(struct node *start, int data_5339) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    struct node *ptr_5339 = start, *prev_5339 = NULL;

    do {
        if (ptr_5339->data == data_5339) {
            if (prev_5339 == NULL) { // deleting the first node
                struct node *last = start;
                while (last->link != start) {
                    last = last->link;
                }
                if (start->link == start) { // Only one node
                    free(start);
                    return NULL;
                }
                last->link = start->link;
                free(start);
                return last->link; // new start
            } else {
                prev_5339->link = ptr_5339->link;
                free(ptr_5339);
                return start;
            }
        }
        prev_5339 = ptr_5339;
        ptr_5339 = ptr_5339->link;
    } while (ptr_5339 != start);

    printf("Data not found in the list.\n");
    return start;
}

// Display Circular Linked List
void display_circular_sll(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = start;
    while (ptr != start) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("%d -> (back to start)\n", ptr->data); // Display the last node pointing back to start
}

// Display Single Linked List
void display_sll(struct node *start) {
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Insert at any position in single linked list
struct node *insert_pos_sll(struct node *start, int data_5339, int pos_5339) {
    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    if(new_node_5339 == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    new_node_5339->data = data_5339;
    new_node_5339->link = NULL;

    if (pos_5339 == 1) {
        new_node_5339->link = start;
        return new_node_5339;
    }

    struct node *ptr_5339 = start;
    for (int i = 1; ptr_5339 != NULL && i < pos_5339 - 1; i++) {
        ptr_5339 = ptr_5339->link;
    }
    if (ptr_5339 == NULL) {
        printf("Position does not exist.\n");
        free(new_node_5339);
        return start;
    }
    new_node_5339->link = ptr_5339->link;
    ptr_5339->link = new_node_5339;
    return start;
}

// Delete any given data in single linked list
struct node *delete_data_sll(struct node *start, int data_5339) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    struct node *ptr_5339 = start, *prev_5339 = NULL;
    while (ptr_5339 != NULL) {
        if (ptr_5339->data == data_5339) {
            if (prev_5339 == NULL) {
                start = ptr_5339->link;
                free(ptr_5339);
                return start;
            } else {
                prev_5339->link = ptr_5339->link;
                free(ptr_5339);
                return start;
            }
        }
        prev_5339 = ptr_5339;
        ptr_5339 = ptr_5339->link;
    }
    printf("Data not found in the list.\n");
    return start;
}


int main(){
    // Test the circular linked list
    start = insert_pos_circular_sll(start, 10, 1);
    start = insert_pos_circular_sll(start, 20, 2);
    start = insert_pos_circular_sll(start, 30, 3);
    display_circular_sll(start);

    start = delete_data_circular_sll(start, 20);
    display_circular_sll(start);

    // Test Single Linked List Functions
    struct node *sll = NULL;
    sll = insert_pos_sll(sll, 10, 1);
    sll = insert_pos_sll(sll, 20, 2);
    sll = insert_pos_sll(sll, 30, 3);
    display_sll(sll);

    sll = delete_data_sll(sll, 20);
    display_sll(sll);

    sll = delete_pos_sll(sll, 2); // test delete by position
    display_sll(sll);

    return 0;
}