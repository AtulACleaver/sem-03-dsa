// 1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.

#include <stdio.h>

struct emply{
    long empId;
    char name[25];
    char designation[15];
    float basic_salary;
    float hra;
    float da;
};


int main(){
    int n;

    printf("value of n: ");
    scanf("%d", &n);

    struct emply em[n];

    // Input value of employees
    for(int i = 0; i<n; i++){
        printf("Emp-Id of emp[%d]: ", i);
        scanf("%ld", &em[i].empId);

        printf("Name of emp[%d]:  ", i);
        scanf("%s", em[i].name);

        printf("Designation of emp[%d]: ", i);
        scanf("%s", em[i].designation);

        printf("Basic Salary of emp[%d]: ", i);
        scanf("%f", &em[i].basic_salary);

        printf("HRA%% of emp[%d]: ", i);
        scanf("%f", &em[i].hra);

        printf("DA%% of emp[%d]: ", i);
        scanf("%f", &em[i].da);
    }

    // gross salary calculation and display
    for (int i = 0; i < n; i++)
    {
        printf("\n\nDetails of Employee %d\n", i+1);
        printf("\nEmp-Id: %ld", em[i].empId);
        printf("\nName: %s", em[i].name);
        printf("\nDesignation: %s", em[i].designation);
        printf("\nGross Salary: %.2f", em[i].basic_salary+((em[i].da/100)*em[i].basic_salary) + ((em[i].hra/100)*em[i].basic_salary));
    }

    return 0;
}

// Output
// value of n: 2
// Emp-Id of emp[0]: 101
// Name of emp[0]:  Alice
// Designation of emp[0]:  Manager
// Basic Salary of emp[0]: 50000
// HRA% of emp[0]: 20
// DA% of emp[0]: 10
// Emp-Id of emp[1]: 102
// Name of emp[1]:  Bob
// Designation of emp[1]:  Developer
// Basic Salary of emp[1]: 40000
// HRA% of emp[1]: 15
// DA% of emp[1]: 5
//
// Details of Employee 1
// Emp-Id: 101
// Name: Alice
// Designation: Manager
// Gross Salary: 65000.00
//
// Details of Employee 2
// Emp-Id: 102
// Name: Bob
// Designation: Developer
// Gross Salary: 46000.00
//