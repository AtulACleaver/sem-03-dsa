// Insert node at 1st position and then transverse

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *insert(struct node *start)
{
    struct node *new_node;
    int x;

    if (start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &start->data);
        start->next = NULL;
        return start;
    }

    printf("Enter -1 to exit \n");
    printf("Enter the data: ");
    scanf("%d", &x);

    while (x != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = x;
        new_node->next = start;
        start = new_node;

        printf("Enter the data: ");
        scanf("%d", &x);
    }

    return start;
}

void transverse(struct node *start)
{
    struct node *ptr = start;

    while (ptr->next != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insert_last(struct node *start, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (start == NULL)
    {
        return new_node; // If the list is empty, return the new node as the head
    }

    struct node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = new_node; // Link the new node at the end
    return start;          // Return the unchanged head
}

struct node *insert_after_data(int value, struct node *start, int pos_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return start; // Return unchanged list if memory allocation fails
    }
    else
    {
        new_node->data = value;
        new_node->next = NULL;

        struct node *ptr = start;
        if (start == NULL)
        {
            printf("List is empty!\n");
            return new_node;
        }

        while (ptr != NULL && ptr->data != pos_data)
        {
            ptr = ptr->next; // Traverse the list to find the position
        }

        new_node->next = ptr->next; // Link the new node to the next node
        ptr->next = new_node;       // Link the previous node to the new node
        return start;               // Return the unchanged head

        printf("Node with data %d not found!\n", pos_data);
        free(new_node);
        return start;
    }
}

// insert node after any given position
struct node *insert_after_position(int value, struct node *start, int pos)
{

    // Pos = 1 means that the node will be added in the beginning of the node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return start; // Return unchanged list if memory allocation fails
    }
    new_node->data = value;
    new_node->next = NULL;
    
    if(start == NULL && pos == 1){
        return new_node;
    }

    else{
        int count = 1;
        struct node *ptr = start;
        while (ptr->next != NULL && count <= pos){
            ptr = ptr->next;
            count++;
        } 
        
        if(count == pos){
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        else{
            printf("postion out of bounds");
        }
    }

    return start;

}

int main()
{
    start = insert(start);
    printf("Transverse the linked list: \n");
    transverse(start);


    printf("\n");
    return 0;
}