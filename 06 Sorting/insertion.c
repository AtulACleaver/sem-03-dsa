// Insertion sort

#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int size){

    for(int i = 1; i < size; i++){
        
    }
    
}

int main(){
    int size = 5;
    int arr[size];
    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++){
        arr[i] = (int)rand()%100;
    }

    insertion(arr, size);
    
    printf("Sorted array: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}