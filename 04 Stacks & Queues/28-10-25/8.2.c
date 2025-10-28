#include <stdio.h>
#include <stdlib.h>

/* Priority Queue using singly linked list
   - Lower numeric priority value => higher priority (ascending priority)
   - enqueue inserts node so list stays sorted by priority (stable FIFO for equal priorities)
*/

struct node {
    int data;
    int priority;
    struct node* next;
};

/* Create a new node with given data and priority */
struct node* createNode(int data, int priority) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

/* Return 1 if empty, 0 otherwise */
int isEmpty(struct node* head) {
    return head == NULL;
}

/* Insert element according to ascending priority (smaller priority first).
   Stable insertion: new node is placed after existing nodes with equal priority.
*/
void enqueue(struct node** head, int data, int priority) {
    struct node* newNode = createNode(data, priority);

    /* Insert at head if list empty or new node has higher priority than head */
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        /* Find insertion point: after last node whose priority <= new priority */
        struct node* curr = *head;
        while (curr->next != NULL && curr->next->priority <= priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    printf("Enqueued: %d (priority %d)\n", data, priority);
}

/* Remove and return data of highest priority element (head). Returns -1 if empty. */
int dequeue(struct node** head) {
    if (isEmpty(*head)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    struct node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}

/* Print list as data:priority pairs in order (head => front of queue) */
void traverse(struct node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty\n");
        return;
    }
    struct node* curr = head;
    printf("Queue (data:priority) -> ");
    while (curr) {
        printf("%d:%d ", curr->data, curr->priority);
        curr = curr->next;
    }
    printf("\n");
}

/* Free entire list */
void freeList(struct node** head) {
    struct node* curr = *head;
    while (curr) {
        struct node* nxt = curr->next;
        free(curr);
        curr = nxt;
    }
    *head = NULL;
}

int main() {
    struct node* pq = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data and priority (e.g. 42 3): ");
                if (scanf("%d %d", &data, &priority) != 2) {
                    printf("Invalid input\n");
                    /* clear stdin remainder */
                    int ch; while ((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                traverse(pq);
                break;
            case 4:
                freeList(&pq);
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    freeList(&pq);
    return 0;
}