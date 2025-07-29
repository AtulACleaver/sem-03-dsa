// WAP to create a 1D array of n element and perform the following menu based funciton:-
// i. insert a particular element at a particular index
// ii. delete a particular element at a particular index
// iii. perform linear search a particular element in the array
// iv. transverse the array

#include <stdio.h>

void insert(int arr[], int *n, int index, int element) {
    if (index < 0 || index > *n) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*n)++;
}

void delete(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main()