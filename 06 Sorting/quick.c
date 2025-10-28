#include <stdio.h>

int arr[] = {17, 6, 19, 26, 39, 48, 9, 29, 31, 37, 45, 50};
int n = sizeof(arr) / sizeof(arr[0]);

// Swap two elements in the global array by index.
void interchange(int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Hoare partition: pivot is arr[low]. Returns an index such that
// all elements at or left of the returned index are <= pivot
// and all elements to the right are >= pivot (for this implementation).
int partition(int low, int high){
    int pivot = arr[low];     // pick first element as pivot
    int left = low - 1;       // start left pointer just before the subarray
    int right = high + 1;     // start right pointer just after the subarray

    // Consider the original array as: [17, 6, 19, 26, 39, 48, 9, 29, 31, 37, 45, 50]
    // What will this function return for partition(0, 11)?
    // It will return the index of the last element in the left partition
    // which is less than or equal to the pivot (arr[0] = 17).
    // In this case, the left partition will be [6, 9] and the right
    // partition will be [19, 26, 39, 48, 29, 31, 37, 45, 50].
    // So the function will return 3.

    while (1) {
        // Move left pointer right until we find an element >= pivot
        do {
            left++;
        } while (arr[left] < pivot);

        // Move right pointer left until we find an element <= pivot
        do {
            right--;
        } while (arr[right] > pivot);

        // If pointers crossed, partitioning is done; return right as split point
        if (left >= right) {
            return right;
        }

        // Otherwise swap the out-of-place elements and continue
        interchange(left, right);
    }
}

// Quick sort on subarray arr[low..high] (both low and high inclusive).
void quick_sort(int low, int high){
    if (low < high) {
        int p = partition(low, high);
        // Recursively sort left part and right part
        quick_sort(low, p);       // note: p is inclusive for Hoare partition
        quick_sort(p + 1, high);
    }
}

void display(){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    printf("Original array:\n");
    display();

    quick_sort(0, n - 1);

    printf("Sorted array:\n");
    display();

    return 0;
}