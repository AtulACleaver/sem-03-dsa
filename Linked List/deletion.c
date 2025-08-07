// delete node at diff postions in linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

// Delete node at the beginning
struct node *delete_beginning(struct node *start){
    if (start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
    return start;
}

// Delete node at the end
struct node *delete_end(struct node *start){

    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    if (start->next == NULL) {
        temp = start;
        start = NULL;
        free(temp);  
    }
    
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return start;
}

// Delete node after pos
struct node *delete_after_pos(int pos, struct node *start){
    struct node *ptr = start;
    if(start == NULL){
        printf("List is empty");
    }else if(pos == 1){
        start = start -> next;
        free(ptr);
        return start;
    }else{
        struct node *ptr1 = ptr;
        int i = 1;
        while (ptr -> next != NULL && i < pos){
            ptr1 = ptr;
            ptr = ptr->next;
            i++;
        }
        if(pos > i){
            printf("Invalid Pos");
        }else{
            ptr1->next = ptr->next;
            free(ptr);
            return start;
        }
    }
}

// Delete Data
struct node *delete_data(int data, struct node *start){
    struct node *ptr = start;
    if(start == NULL){
        printf("List is empty");
    }else{
        struct node *ptr1 = ptr;
        while(ptr->next !=NULL && ptr->data != data){
            ptr1 = ptr;
            ptr = ptr->next;
        }

        if(ptr->data == data){
            ptr1->next = ptr->next;
            free(ptr);
            return start;
        }
    }
}

void transverse(struct node *start)
{
    struct node *ptr = start;

    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
}



int main()
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    for(int i = 0; i<10; i++){
        new_node->data = i;
    }
    
    return 0;
}