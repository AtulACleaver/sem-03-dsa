// delete node at diff postions in linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void transverse(struct node *start)
{
    struct node *ptr = start;

    while (ptr->next != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}




int main()
{
    start = insert(start);
    printf("Transverse the linked list: \n");
    transverse(start);

    //
    printf("\n");
    return 0;
}