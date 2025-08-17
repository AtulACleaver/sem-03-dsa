// Delete any given data from the array

#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_data(int arr[], int *n, int value) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == value) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--; // Decrease the size of the array
            i--; // Adjust index after deletion
        }
    }
    if (!found) {
        printf("Value %d not found in the array.\n", value);
    } else {
        printf("Array after deletion:\n");
        print_array(arr, *n);
    }
}

int main(){
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5; // current number of elements in the array
    int size = 100; // maximum size of the array
    int pos, value;

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    insert_array(arr, &n, size, pos, value);

    return 0;
}

