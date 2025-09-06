# Linked List - Mid Sem Questions

This document contains a collection of possible questions that may appear in the mid-semester exam for the course "Introduction to Data Structures using C". These questions specifically focus on the topic of linked lists and their implementation in the C programming language.

---

### Code Questions
---
1. Write the Pseudocode to convert a Single Linked List to Circular Linked List.
2. Write a pseudocode / C-function that will delete a node from any given position from a Double Linked List.
3. Write a pseudocode / C-function to remove the last node from a Single Linked List and insert that node at the beginning of the list.
4. Write an algorithm/ C function to reverse a singly linked list, where the pointer variable head is holding the address of the first node of the linked list and this head will be passed as an argument to the function.
5. Write an algorithm/ C function to insert a node after a specific position in a doubly linked list, where previous pointer is named as `prev` and the next pointer is named as `next`. `head` is a pointer variable holding the address of the first node of the list, which is passed as the argument to the function.
6. Given two sorted single linked lists. Write an algorithm/ C-type function to merge them into a third linked list in sorted order, where two lists are passed as parameters to the function. Also find the time complexity of the algorithm.
7. If the node of a doubly linked list is declared in C as:
    ```c
    struct node {
        int data;
        struct node *prev;
        struct node *next; 
    };
    ```
    and `ptr` is a pointer pointing to one of the internal nodes of a doubly linked list, then write the required statements to delete the node to which `ptr` is pointing to without using any other pointer variable.
8. The following data are stored in a singly linked list in the order shown below:  
    `1-2-3->4->5->6->7->8->9->10`  
    Write a pseudo code/ C-function to delete all odd numbers from the list.

---

### Theory Questions

1. What is the output of the following function in which head is pointing to the first node of the given linked list: `10->20->30->40->50`?
    ```c
    void disp(struct node *head)
    {
        if (head == NULL)
            return;
        printf("%d ", head->info);
        if (head->next != NULL)
            disp(head->next->next);
        printf("%d ", head->info);
    }
    ```
2. What does the following code segment do on a doubly linked list? `mid` is the address of some middle node and `new` is the address of a newly created node.
    ```c
    new->prev = mid;
    new->next = mid->next;
    new->prev->next = new;
    new->next->prev = new;
    ```
    Where does the new node insert to?
3. What does the following function do for a given linked list with first node as head with a node structure: `struct node { int data; struct node *next; };`?
    ```c
    void func(struct node *head)
    {
        if (head == NULL)
            return;
        func(head->next);
        printf("%d ", head->data);
    }
    ```
4. How a singly linked list can be used to represent the following polynomial:  
    `2xy^2z^3 + 3x^2yz^2 + 4xy^3z
5. Represent a second order polynomial using Linked list.
6. Describe the process of inserting and deleting nodes in a circular linked list at different positions (beginning, middle, end). Use diagrams as well as code snippets to support your explanation.
