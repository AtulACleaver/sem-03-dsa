/* 1.4 Write a menu driven program to create a structure to represent complex number and perform the following operation using function : 
    1. addition of two complex number (call by value)
    2. multiplication of two complex number (call by address)
*/

#include <stdio.h>

struct complex {
    float real;
    float img;
};

// add two complex numbers (call by value)
struct complex add(struct complex c1, struct complex c2) {
    struct complex result;
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;
    return result;
}

// multiply two complex numbers (call by address)
void multiply(struct complex *c1, struct complex *c2, struct complex *result) {
    result->real = (c1->real * c2->real) - (c1->img * c2->img);
    result->img = (c1->real * c2->img) + (c1->img * c2->real);
}   

int main() {
    struct complex c1, c2, result;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter first complex number (real img): ");
                scanf("%f %f", &c1.real, &c1.img);
                printf("Enter second complex number (real img): ");
                scanf("%f %f", &c2.real, &c2.img);
                
                result = add(c1, c2);
                printf("Sum: %.2f + %.2fi\n", result.real, result.img);
                break;

            case 2:
                printf("Enter first complex number (real img): ");
                scanf("%f %f", &c1.real, &c1.img);
                printf("Enter second complex number (real img): ");
                scanf("%f %f", &c2.real, &c2.img);
                
                multiply(&c1, &c2, &result);
                printf("Product: %.2f + %.2fi\n", result.real, result.img);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
