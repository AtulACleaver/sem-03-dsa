// Optimized bubble sort

#include <stdio.h>
#include <stdlib.h>

void bubble_sort_o(int arr[], int size){
    int i, j, flag=0, temp;

    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
        flag = 0;
    }
}

int main(){
    int size = 5;
    int arr[size];
    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++){
        arr[i] = (int)rand()%100;
    }

    bubble_sort_o(arr, size);
    
    printf("Sorted array: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}