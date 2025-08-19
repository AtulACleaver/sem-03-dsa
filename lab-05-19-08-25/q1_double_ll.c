// WAP for the following:-
// 1. Insert at any given position in a double-linked list.
// 2. Delete any given data from a double-linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* rptr;
    struct node* lptr;
};

struct node *start = NULL;

// Function to insert a new node at a given position
struct node *insertAtPosition(struct node *start, int pos_5339, int data_5339) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Overflow \n");
        return start;
    }

    new_node->data = data_5339;
    new_node->lptr = NULL;
    new_node->rptr = NULL;

    if(start == NULL){
        if(pos_5339 != 1){
            printf("Position Out of Bounds\n");
            return start;
        }
        else{
            start=new_node;
            new_node->rptr = NULL;
            new_node->lptr = NULL;
        return start;
        }   
    }

    // Case for beginning
    if(pos_5339 == 1){
        new_node->rptr = start;
        start = new_node;
        return start;
    }

    // Case: in between & end
    struct node *ptr_5339 = start;
    int i = 1;
    while(ptr_5339 != NULL && i < pos_5339 - 1){
        ptr_5339 = ptr_5339->rptr;
        i++;
    }

    if(ptr_5339 == NULL){
        printf("Position out of bounds\n");
        free(new_node);
        return start;
    }

    // Insert at end
    if(ptr_5339->rptr == NULL){
        new_node->lptr = ptr_5339;
        new_node->rptr = NULL;
        ptr_5339->rptr = new_node;
    }
    // Insert in between
    else{
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

void display(struct node *start) {
    struct node *ptr_5339 = start;
    while(ptr_5339 != NULL) {
        printf("%d -> ", ptr_5339->data);
        ptr_5339 = ptr_5339->rptr;
    }
    printf("NULL\n");
}


int main(){

    int n;
    printf("Input n number of nodes to add: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int data;
        printf("Data = ");
        scanf("%d", &data);
        start = insertAtPosition(start, i, data);
    }
    display(start);


    return 0;
}
