// 1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) return 0; 
    }
    return 1;
}

int sum_of_primes(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}


int main(){
    int n, sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));


    // Input
    for(int i = 0; i < n; i++){
        printf("Value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Sum
    sum = sum_of_primes(arr, n);
    printf("Sum of prime elements: %d\n", sum);


    free(arr);

    return 0;
}