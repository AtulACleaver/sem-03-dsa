// 1.1 Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

int compare(int *a, int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a < *b) {
        return -1;
    } else {
        return 0;
    }
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = compare(&num1, &num2);

    if (result == 1) {
        printf("The first number is greater.\n");
    } else if (result == -1) {
        printf("The second number is greater.\n");
    } else {
        printf("Both numbers are equal.\n");
    }
    return 0;
}

// Output:
// The first number is greater.
// The second number is greater.
// Both numbers are equal.