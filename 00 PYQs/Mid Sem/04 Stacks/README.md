// Set all possible questions coming in mid sem exam from Stack of DS using C

# Stack - Mid Sem Questions

This document contains a collection of possible questions that may appear in the mid-semester exam for the course "Introduction to Data Structures using C". These questions specifically focus on the topic of stacks and their implementation in the C programming language.

---

### Code Questions

1. How can a stack be used to reverse a string? Outline the steps involved.
2. Write a C program or algorithm to evaluate a postfix expression using a stack. Demonstrate the step-by-step evaluation of the expression "534*+2-" based on your implementation. Clearly illustrate each intermediate step and the contents of the stack at each stage of the evaluation. 
3. Which data structure is used to implement recursion? Give one small example of recursive program in C.
4. Write a pseudocode / C-function to sort the elements of a stack without using any additional data structure or variable, and without violating the Stack abstraction principle. [IMPORTANT]
5. Balance ( ) , { } , [ ] are called matching symbols. Write a pseudocode / C-function to check whether the input expression has balanced parentheses or not usi
6. Write a recursive function to display elements of stack using the operations push() and pop() without violating the LIFO concept.
ng Stack.
1. Given a stack of integers, write the pseudo code/ C function to display all elements in the order in which they have been inserted using another temporary stack without violating LIFO concept.
2. Design a method for keeping two stacks within a single linear array S in such a way that neither stack overflows until the entire array is used. Write C functions push1(), push2(), pop1(), and pop2() to manipulate the two stacks. (Hints: Two stacks grow towards each other)
3.  Write an algorithm/ pseudo code/ C-function to convert an expression in infix notation to its equivalent prefix expression. Convert the infix expression: (A+B)+C-(D-E)F to prefix equivalent mentioning each step of the algorithm.

---

### Theory Questions

1. The items: 11, 12, 13, 14, 15 and 16 are pushed in a stack, one after the other starting from 11. The stack is popped five times and each element is inserted in a queue. Then, three elements are deleted from the queue and pushed back on the stack. Now two items are popped from the stack. The popped items are? => 14, 15
2. Convert the following expression to postfix notation using the infix-to-postfix conversion algorithm with a Stack. Provide a detailed step-by-step representation of the process. a*b/ (a-c) +d*b
3. Convert the following expression to postfix notation using the infix-to-postfix conversion algorithm with a Stack. Provide a detailed step-by-step representation of the process. a / (b-c)+d*e-a*c
4. A stack of integers initially contain three elements 5, 7, 3 from bottom to top. The size of the stack is 6. Mention the output of the operations push (4), pop (0), push (10), push (8), push (0), push (9), pop (0), pop (0) on the stack.
5. Convert the infix expression: M^(N*P)/Q+R-S^T/((U/V)/W-X) to postfix expression using stack. Explain each step showing the status of the stack as well as the partial postfix expression.
6. What will be the output of the prefix expression: +, * ,2, t, 1, 14, 2, 5, 1 after evaluation?
7. A stack is implemented using an array declared in C: st[N] and an integer variable: pos. The pseudo code for the push ( and pop operations of the stack are as follow:

    ```
    push(x)
    {
        st[pos] = x;
        pos - pos - 1;
    }
    pop0
    {
        pos = pos + 1;
        return (st[pos]);
    }
    ```
    Find the initialization of integer variable: pos for an empty stack with a maximum capacity of N elements for the