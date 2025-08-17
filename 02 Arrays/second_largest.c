// Find the second largest element in an array

#include <stdio.h>

int second_largest(int arr[], int n){
    if(n < 2) {
        printf("Array must contain at least two elements.\n");
        return -1; // Indicating an error
    }

    int largest = arr[0];
    int second_largest = -1; // Initialize to -1 to indicate no second largest

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        } else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    return second_largest;
}