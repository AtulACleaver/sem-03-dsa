// Insert a number into a sorted array

#include <stdio.h>

void insert_sorted(int arr[], int n, int arr_size, int value) {
    if (n >= arr_size) {
        printf("Array is full\n");
    }
    else {
        if(arr[0] > value){
            for(int i = n; i >= 0; i--){
                arr[i + 1] = arr[i];
            }
            arr[0] = value;
        }
        else if(arr[n - 1] < value){
            arr[n] = value;
            n = n+1;
        }
        else {
            for(int i = 0; i < n-1; i++){
                if(value >= arr[i] && value <= arr[i + 1]){
                    for(int j = n; j >= i + 1; j--){
                        arr[j+1] = arr[j];
                    }
                    arr[i + 1] = value;
                    n = n + 1;
                    break;
                }
            }
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {11, 22, 33, 44, 55}; // Example sorted array
    int n = 5; // Current number of elements in the array
    int arr_size = 100; // Maximum size of the array
    int value;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    insert_sorted(arr, n, arr_size, value);
    print_array(arr, n + (n < arr_size ? 1 : 0)); // Print updated array

    return 0;
}