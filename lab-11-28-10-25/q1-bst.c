// Write a menu driven C program on BST to do the following:-
// Insert
// Delete
// Inorder Traversal
// Pre-Order/Post-Order Traversal

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node (global - keep unchanged)
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to insert a value into the BST
struct BSTNode* insert(struct BSTNode* root_5339, int value_5339) {
    struct BSTNode* new_node_5339 = (struct BSTNode*)malloc(sizeof(struct BSTNode));

    if(new_node_5339 == NULL){
        printf("Overflow!");
        return root_5339;
    }

    new_node_5339->data = value_5339;
    new_node_5339->left = NULL;
    new_node_5339->right = NULL;
    
    if (root_5339 == NULL) {
        root_5339 = new_node_5339;
        return root_5339;
    }
    struct BSTNode* current_5339 = root_5339;
    struct BSTNode* parent_5339 = NULL;

    while(current_5339 != NULL){
        parent_5339 = current_5339;
        if(value_5339 < current_5339->data) 
            current_5339 = current_5339->left;
        else
            current_5339 = current_5339->right;
    }

    if(value_5339 < parent_5339->data)
        parent_5339->left = new_node_5339;
    else
        parent_5339->right = new_node_5339;

    return root_5339;
}

// Example input output
// Input: 5, 3, 7, 2, 4, 6, 8
// Output: Inorder: 2 3 4 5 6 7 8

// Function to delete a value from the BST
struct BSTNode* delete(struct BSTNode* root_5339, int value_5339) {
    if (root_5339 == NULL) {
        printf("Value %d not found in the BST.\n", value_5339);
        return root_5339;
    }
    if (value_5339 < root_5339->data) {
        root_5339->left = delete(root_5339->left, value_5339);
    } else if (value_5339 > root_5339->data) {
        root_5339->right = delete(root_5339->right, value_5339);
    } else {
        // Node with only one child or no child
        if (root_5339->left == NULL) {
            struct BSTNode* temp_5339 = root_5339->right;
            free(root_5339);
            return temp_5339;
        } else if (root_5339->right == NULL) {
            struct BSTNode* temp_5339 = root_5339->left;
            free(root_5339);
            return temp_5339;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct BSTNode* temp_5339 = root_5339->right;
        while (temp_5339 && temp_5339->left != NULL) {
            temp_5339 = temp_5339->left;
        }
        // Copy the inorder successor's content to this node
        root_5339->data = temp_5339->data;
        // Delete the inorder successor
        root_5339->right = delete(root_5339->right, temp_5339->data);
    }
    return root_5339;
}

// Example input output
// Input: 5, 3, 7, 2, 4,
// Delete: 3
// Output: Inorder: 2 4 5 7

// Function for inorder traversal of the BST (iterative)
void inorderTraversal(struct BSTNode* root_5339) {
    struct BSTNode* stack_5339[100];
    int top_5339 = -1;
    struct BSTNode* current_5339 = root_5339;

    while (current_5339 != NULL || top_5339 != -1) {
        while (current_5339 != NULL) {
            stack_5339[++top_5339] = current_5339;
            current_5339 = current_5339->left;
        }
        current_5339 = stack_5339[top_5339--];
        printf("%d ", current_5339->data);
        current_5339 = current_5339->right;
    }
}

// Example input output
// Input: 5, 3, 7, 2, 4,
// Output: Inorder: 2 3 4 5 6 7 8


void preorderTraversal(struct BSTNode* root_5339){
    struct BSTNode* stack_5339[100];
    int top_5339 = -1;
    struct BSTNode* current_5339 = root_5339;

    while (current_5339 != NULL || top_5339 != -1) {
        while (current_5339 != NULL) {
            printf("%d ", current_5339->data);
            stack_5339[++top_5339] = current_5339;
            current_5339 = current_5339->left;
        }
        current_5339 = stack_5339[top_5339--];
        current_5339 = current_5339->right;
    }
}

// Example input output
// Input: 5, 3, 7, 2, 4,
// Output: Preorder: 5 3 2 4 7


int main() {
    struct BSTNode* root_5339 = NULL;
    int choice_5339, value_5339;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_5339);

        switch (choice_5339) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value_5339);
                root_5339 = insert(root_5339, value_5339);
                printf("%d inserted into the BST.\n", value_5339);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value_5339);
                root_5339 = delete(root_5339, value_5339);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root_5339);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root_5339);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                // postorderTraversal(root_5339);  // implement if required
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}