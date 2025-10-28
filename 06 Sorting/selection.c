// Optimized bubble sort

#include <stdio.h>
#include <stdlib.h>

// minimum int value
#define MIN_INT_VALUE -2147483648

void selection(int arr[], int size){
    int i, j, s = MIN_INT_VALUE;
    for(i = 0; i < size; i++){
        int min_index = -1;
        for(j = 0; j < size; j++){
            if(arr[j] > s){
                if(min_index == -1 || arr[j] < arr[min_index]){
                    min_index = j;
                }
            }
        }
        if(min_index != -1){
            s = arr[min_index];
        }
    }
}

// Example input output
// Input: 5 2 9 1 5
// Output: 1 2 5 5 9

int main(){
    int size = 5;
    int arr[size];
    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++){
        arr[i] = (int)rand()%100;
    }

    selection(arr, size);
    
    printf("Sorted array: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}