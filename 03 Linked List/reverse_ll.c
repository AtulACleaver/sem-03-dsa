// Reverse a singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* reverseList(node* head) {
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Dry run
// example list: 1 -> 2 -> 3 -> NULL
// reverse list: 3 -> 2 -> 1 -> NULL
// 1. Initialize pointers: prev = NULL, curr = head (1), next = NULL
// 2. Iterate through the list:
//    - 1st iteration: next = 2, curr->next = NULL, prev = 1, curr = 2
//    - 2nd iteration: next = 3, curr->next = 1, prev = 2, curr = 3
//    - 3rd iteration: next = NULL, curr->next = 2, prev = 3, curr = NULL
// 3. Update head to prev (3) and return

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->data = 1;
    head->next = (node*)malloc(sizeof(node));
    head->next->data = 2;
    head->next->next = (node*)malloc(sizeof(node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}