# Introduction to Data Structures Using C  
Mid-Semester Possible Questions (Introduction Unit)

---

## 1. Conceptual / Theory Questions

### 1.1 Abstract Data Types (ADT)
1. What is an ADT (Abstract Data Type) in data structure? Explain with examples.
Ans - ADT or Abstract Data Type is a way where we look at the data structure and focus on what it does and not on how it does it.  For example - Stacks & Queues can be implemented using both arrays & linked lists.

### 1.2 Time & Space Complexity Analysis
1. Find the worst-case time complexity of the following C function:
   ```c
   void run(int n)
   {
       int i, j, k = 3;
       for (i = 1; i < n; i++)
       {
           for (j = 1; j < n; j += pow(j, k))   // Note: update expression as written is unusual
               printf("%d, %d", i, j);
       }
   }
   ```
   => O(nloglog(n))

2. What is the approximate return value (in terms of n) of the following function? Explain each loop to compute the value of q.
   ```c
   int func(int n)
   {
       int i, j, k, p, q = 0;
       for (i = 1; i < n; i++)
       {
           p = 0;
           for (j = n; j > 1; j = j / 2)
               p++;
           for (k = 1; k < p; k = k * 2)
               q += t;   // 't' is assumed to be a defined value elsewhere
       }
       return q;
   }
   ```

   O(n * log n * log n)
3. What is the time complexity of the following code?
   ```c
   void sample(int n)
   {
       int i, j, k = 0;
       for (i = n / 2; i <= n; i++)
       {
           for (j = 2; j <= n; j = j * 2)
           {
               k = k + n / 2;
           }
       }
   }
   ```
   =>O(nlogn)
4. Find the time complexity of the following function:
   ```c
   void func(int n)
   {
       int i = 1, j;
       while (i <= n)
       {
           for (j = 1; j * j <= n; j++)
               printf("Data Structure...In");
           i++;  // Assumed increment (not shown in original snippet)
       }
   }
   ```
    => O(n√n)
---