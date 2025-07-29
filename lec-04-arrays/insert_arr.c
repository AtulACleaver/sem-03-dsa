// Insert at any postion in an array

#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_array(int arr[], int *n, int size, int pos, int value){
    pos = pos - 1;
    if(*n >= size){
        printf("Array is already full. \n");
    }
    else{
        if (pos > *n || pos < 0)
        {
            printf("Invalid Pos. \n");
        }
        else if(pos == *n){
            arr[pos] = value;
            *n += 1;
        }
        else{
            for (int i = *n-1; i >= pos; i--)
            {
                arr[i+1] = arr[i];
            }
            *n = *n + 1;
            arr[pos] = value;
        }
    }

    print_array(arr, *n);
}

int main(){
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5; // current number of elements in the array
    int size = 100; // maximum size of the array
    int pos, value;

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    insert_array(arr, &n, size, pos, value);

    return 0;
}

