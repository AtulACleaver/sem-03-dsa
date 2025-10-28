// Bubble sort

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n){
    int i_5339, j_5339, swap_c = 0;
    for(i_5339 = 0; i_5339 < n-1; i_5339++){
        for(j_5339 = 0; j_5339 < n-i_5339-1; j_5339++){
            if(arr[j_5339] > arr[j_5339+1]){
                int temp_5339 = arr[j_5339];
                arr[j_5339] = arr[j_5339+1];
                arr[j_5339+1] = temp_5339;
                swap_c++;
            }
        }
    }
    printf("No. of swaps: %d \n", swap_c);
}

int main(){
    int n_5339 = 10000;
    int arr[n_5339];
    printf("Enter %d integers: ", n_5339);
    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        arr[i_5339] = (int)rand()%10000;
    }

    bubble_sort(arr, n_5339);
    
    printf("Sorted array: \n");
    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        printf("%d ", arr[i_5339]);
    }
    printf("\n");
    return 0;
}

// 25,214,872 
// 25,214,872