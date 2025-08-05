// WAP to create a menu for insertion of data in a linked_list in the following ways:-
// i. Insert in the beginning
// ii. Insert at the end
// iii. Insert after a given data
// iv. Insert after a given position
// v. Insert before a given data

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Initiate Start
struct node *start = NULL;

// Insert in the beginning
struct node *insert_beginning(struct node *start)
{
    // input data
    int value_5339;
    printf("Value to be inserted at the beginning: ");
    scanf("%d", &value_5339);

    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    new_node_5339->data = value_5339;
    new_node_5339->link = NULL;

    // If the list is empty, make the new node the start & create new elements until -1 is entered
    while (start == NULL || value_5339 != -1)
    {
        start = new_node_5339;
        printf("Enter -1 to stop inserting elements at the beginning\n");
        printf("Enter the next value: ");
        scanf("%d", &value_5339);
        if (value_5339 == -1)
        {
            return start;
        }
        new_node_5339 = (struct node *)malloc(sizeof(struct node));
        new_node_5339->data = value_5339;
        new_node_5339->link = start;
        start = new_node_5339;
    }

    return start;
}

// Insert at the end
struct node *insert_end(struct node *start)
{
    // input data
    int value_5339;
    printf("Value to be inserted in the end: ");
    scanf("%d", &value_5339);

    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    new_node_5339->data = value_5339;
    new_node_5339->link = NULL;

    if (start == NULL)
    {
        start = new_node_5339;
        return start;
    }
    else
    {
        struct node *ptr_5339 = start;
        while (ptr_5339->link != NULL)
        {
            ptr_5339 = ptr_5339->link; // Traverse to the end of the list
        }
        ptr_5339->link = new_node_5339;
        return start;
    }
}

// Insert after a given data
struct node *insert_after_data(struct node *start)
{
    int value_5339, pos_data_5339;
    printf("Value to be inserted after a given data: ");
    scanf("%d", &value_5339);
    printf("Enter the data after which to insert: ");
    scanf("%d", &pos_data_5339);

    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    new_node_5339->data = value_5339;
    new_node_5339->link = NULL;

    if (start == NULL)
    {
        printf("List is empty!\n");
        return start;
    }

    struct node *ptr_5339 = start;
    while (ptr_5339 != NULL && ptr_5339->data != pos_data_5339)
    {
        ptr_5339 = ptr_5339->link;
    }

    if (ptr_5339 == NULL)
    {
        printf("Node with data %d not found!\n", pos_data_5339);
        free(new_node_5339);
        return start;
    }

    new_node_5339->link = ptr_5339->link;
    ptr_5339->link = new_node_5339;
    return start;
}

// Insert after a given position
struct node *insert_after_pos(struct node *start)
{
    int value_5339, pos_5339;
    printf("Value to be inserted after a given data: ");
    scanf("%d", &value_5339);
    printf("Enter the position after which to insert: ");
    scanf("%d", &pos_5339);

    pos_5339--; // Convert to 0 index

    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    new_node_5339->data = value_5339;
    new_node_5339->link = NULL;

    if(start == NULL && pos_5339 == 1){
        return new_node_5339;
    }

    else{
        int count_5339 = 1;
        struct node *ptr_5339 = start;

        while (ptr_5339 != NULL && count_5339 < pos_5339)
        {
            ptr_5339 = ptr_5339->link; // Traverse to the position
            count_5339++;
        }

        if (ptr_5339 == NULL && count_5339 != pos_5339)
        {
            printf("Position %d does not exist in the list!\n", pos_5339);
            free(new_node_5339);
            return start;
        }

        new_node_5339->link = ptr_5339->link;
        ptr_5339->link = new_node_5339;
    }
    return start;
}

// Insert before a given data
struct node *insert_before_data(struct node *start)
{
    int value_5339, pos_data_5339;
    printf("Value to be inserted before a given data: ");
    scanf("%d", &value_5339);
    printf("Enter the data before which to insert: ");
    scanf("%d", &pos_data_5339);

    struct node *new_node_5339 = (struct node *)malloc(sizeof(struct node));
    new_node_5339->data = value_5339;
    new_node_5339->link = NULL;
    if (start == NULL)
    {
        printf("List is empty!\n");
        return start;
    }
    if (start->data == pos_data_5339)
    {
        new_node_5339->link = start;
        return new_node_5339; // Insert at the beginning
    }
    struct node *ptr_5339 = start;
    struct node *ptr_1_5339 = NULL;
    while (ptr_5339 != NULL && ptr_5339->data != pos_data_5339)
    {
        ptr_1_5339 = ptr_5339; // Keep track of the previous node
        ptr_5339 = ptr_5339->link; // Traverse to find the position
    }

    if (ptr_5339 == NULL)
    {
        printf("Node with data %d not found!\n", pos_data_5339);
        free(new_node_5339);
        return start;
    }

    ptr_1_5339->link = new_node_5339;
    new_node_5339->link = ptr_5339;

    return start;
}


void transverse_list(struct node *start)
{
    struct node *ptr_5339 = start;
    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        while (ptr_5339 != NULL)
        {
            printf("%d -> ", ptr_5339->data);
            ptr_5339 = ptr_5339->link;
        }
        printf("NULL\n");
    }
}

// Main function
int main()
{
    int choice_5339;

    // Menu loop
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a given data\n");
        printf("4. Insert after a given position\n");
        printf("5. Insert before a given data\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch (choice_5339)
        {
        case 1:
            start = insert_beginning(start);
            transverse_list(start);
            break;
        case 2:
            start = insert_end(start);
            transverse_list(start);
            break;
        case 3:
            start = insert_after_data(start);
            transverse_list(start);
            break;
        case 4:
            start = insert_after_pos(start);
            transverse_list(start);
            break;
        case 5:
            start = insert_before_data(start);
            transverse_list(start);
            break;
        case 6:
            transverse_list(start);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice_5339 != 7);

    return 0;
}
