// Insertion sort

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n){
    int i_5339, j_5339, swap_c = 0;
    for(i_5339 = 1; i_5339 < n; i_5339++){
        int key_5339 = arr[i_5339];
        j_5339 = i_5339 - 1;
        while(j_5339 >= 0 && arr[j_5339] > key_5339){
            arr[j_5339 + 1] = arr[j_5339];
            j_5339 = j_5339 - 1;
            swap_c++;
        }
        arr[j_5339 + 1] = key_5339;
    }
    printf("No. of swaps: %d", swap_c);
}

int main(){
    int n_5339, temp_5339;
    printf("Enter number of elements: ");
    scanf("%d", &n_5339);
    int arr[n_5339];
    printf("Enter %d integers: ", n_5339);
    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        arr[i_5339] = (int)rand()%10000;
    }

    insertion_sort(arr, n_5339);

    printf("Sorted array: \n");
    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        printf("%d ", arr[i_5339]);
    }
    printf("\n");
    return 0;
}

