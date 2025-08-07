// Create linked list with n nodes

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Function to create a new node

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a linked list with n nodes
struct node* create_linked_list(int n) {
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }

    struct node* head = NULL;
    struct node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        struct node* new_node = create_node(i);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

// Function to print the linked list
void print_linked_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list creation
int main() {
    int n;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    struct node* head = create_linked_list(n);
    printf("Created linked list: ");
    print_linked_list(head);

    return 0;
}
