/* create a menu driven function for the following sorting methods
- bubble
- insertion
- selection
- quick
*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n_5339){
    int i_5339, j_5339, swap_c = 0;
    for(i_5339 = 0; i_5339 < n_5339 - 1; i_5339++){
        for(j_5339 = 0; j_5339 < n_5339 - i_5339 - 1; j_5339++){
            if(arr[j_5339] > arr[j_5339 + 1]){
                int temp_5339 = arr[j_5339];
                arr[j_5339] = arr[j_5339 + 1];
                arr[j_5339 + 1] = temp_5339;
                swap_c++;
            }
        }
    }
    printf("No. of swaps: %d\n", swap_c);
    printf("Sorted array: \n");
    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        printf("%d ", arr[i_5339]);
    }
    printf("\n");
}

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
    printf("No. of swaps: %d\n", swap_c);
    printf("Sorted array: \n");
    for(int i_5339 = 0; i_5339 < n; i_5339++){
        printf("%d ", arr[i_5339]);
    }
    printf("\n");
}

// helper recursive selection sort and a global swap counter
int sel_swap_count_5339 = 0;

void selection_sort_rec(int arr[], int n, int index){
    if(index == n-1){
        return;
    }
    int min_index_5339 = index;

    for(int i = index + 1; i < n; i++){
        if(arr[i] < arr[min_index_5339]){
            min_index_5339 = i;
        }
    }

    if(min_index_5339 != index){
        int temp = arr[index];
        arr[index] = arr[min_index_5339];
        arr[min_index_5339] = temp;
        sel_swap_count_5339++;
    }

    selection_sort_rec(arr, n, index + 1);
}

// wrapper selection_sort (keeps original signature)
void selection_sort(int arr[], int n, int index){
    sel_swap_count_5339 = 0;
    selection_sort_rec(arr, n, index);

    printf("No. of swaps: %d\n", sel_swap_count_5339);
    printf("Sorted array: \n");
    for(int i_5339 = 0; i_5339 < n; i_5339++){
        printf("%d ", arr[i_5339]);
    }
    printf("\n");
}

// Recursion method for quick sort (no printing inside)
void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i_5339 = (low - 1);
        for(int j_5339 = low; j_5339 < high; j_5339++){
            if(arr[j_5339] < pivot){
                i_5339++;
                int temp_5339 = arr[i_5339];
                arr[i_5339] = arr[j_5339];
                arr[j_5339] = temp_5339;
            }
        }
        int temp_5339 = arr[i_5339 + 1];
        arr[i_5339 + 1] = arr[high];
        arr[high] = temp_5339;
        int pi_5339 = i_5339 + 1;

        quick_sort(arr, low, pi_5339 - 1);
        quick_sort(arr, pi_5339 + 1, high);
    }
}

int main(){
    int choice_5339, n_5339;
    printf("Enter number of elements: ");
    scanf("%d", &n_5339);

    int arr[n_5339];
    printf("Enter %d integers: ", n_5339);

    for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
        arr[i_5339] = (int)rand()%10000;
        printf("\n %d, ", arr[i_5339]);
    }
    printf("\n");

    // Menu
    printf("Choose sorting method: \n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice_5339);
    switch(choice_5339){
        case 1:
            bubble_sort(arr, n_5339);
            break;
        case 2:
            insertion_sort(arr, n_5339);
            break;
        case 3:
            selection_sort(arr, n_5339, 0);
            break;
        case 4:
            quick_sort(arr, 0, n_5339 - 1);
            printf("Sorted array: \n");
            for(int i_5339 = 0; i_5339 < n_5339; i_5339++){
                printf("%d ", arr[i_5339]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}