# Arrays - Mid Sem Questions

This document contains a collection of possible questions that may appear in the mid-semester exam for the course "Introduction to Data Structures using C". These questions specifically focus on the topic of arrays and their applications.

---

## Code Questions

1. Write pseudocode / C-function to convert a given 2D array into its Sparse matrix representation and display it in triplet format.
2. Write pseudocode / C-function to merge two sorted arrays using only Array data structure.
3. Write a pseudocode / C-function that will add two Sparse matrix using suitable data-structure.
4. Write pseudocode / C-function to Transpose a Sparse matrix.
5. Write a C function of O(n) order for removing all odd numbers from a given array. Example, if the array contains 10, 2, 3, 7, 8, 6, and 11. The output should be 10, 2, 8, and 6.
6. Given an array of integers, write a C function to update every element with the multiplication of its previous and next elements with the exceptions: i) the First element is replaced the by multiplication the of first and second elements and ii) the last element is replaced by multiplication of last and second last elements.
   
   Example:  
   Input: arr[] = {2, 3, 4, 5, 6}  
   Output: arr[] = {6, 8, 15, 24, 30}
7. Write a pseudo code/ C-function to sort the elements present at the even index of an array in ascending order without using any additional data structure. **[IMPORTANT]**

---

## Theory Questions

1. Given a 2D array A[14][15] stored in row-major order, with a base address of 1000 and each element occupying 4 bytes, calculate the memory address of the element A[18][81].
2. A matrix B[12][12] is stored in the memory with each element requiring 8 bytes of storage. If the address of B[3][3] is 1140, write the formula to solve this problem and calculate the address of B[5][5] when the matrix is stored in Row Major Order.
3. A matrix ARR[4...6][3...8] is stored in the memory with each element requiring 4 bytes of storage. If the base address is 1430, find the address of ARR[3][6] when the matrix is stored in Row Major Order.
4. Consider a two-dimensional array with dimensions m × n, where m represents the number of rows and n represents the number of columns. What is the time complexity to access an arbitrary element in this array?
5. Given an array arr[1...10][1...15] with base address 100 and the size of each element of the array 2 bytes in memory. Find the address of arr[8][6] in column-major order.
6. Each element of an array X[-25 ... 20, 25 ... 40] requires four bytes of storage space. If the beginning location of array is 2001 determine the location of X[20][25] using column major address calculation method.
7. Consider a 2-D array arr[3...6, -2...5] requires 4 bytes of memory space for each element of the array. If the array is stored in row-major order having base address 1001, then what will be the address of the array element arr[5, 3]?
8. Explain sparse matrix and its representations.
9. The following codes create a two dimensional matrix dynamically.
   
   1. Code A:
      ```c
      int *a[4];
      a[0]=malloc(12 * sizeof(int));
      for(int i=0;i<3;i++)
          a[i]=a[0]+(i*4);
      ```
   2. Code B:
      ```c
      int *a[4];
      for(int i=0;i <3;i++)
          a[i]=malloc(4 * sizeof(int));
      ```
   Which of the following statement will work properly in both these above codes?
   - I) `a[1][2]=7;`
   - II) `a[2]=a[1];`
   - III) `*(a[1]+3)=7;`
   - IV) `*(a[0]+7)=7;`