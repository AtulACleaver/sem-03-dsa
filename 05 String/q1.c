// String Functions with & without string fxn
// Q1. Finding the length of the string (with/without using string fxn)
// Q2. Converting a string to lowercase from uppercase
// Q3. Appending a string to another string
// Q4. Compare string two
// Q5. Reverse a given string

// Write the main function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int findLength(char *str){
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    return count;        
}

// Example
// Input: Hello World
// Output: 11

void toLowerCase(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if((str[i] >= 'A' && str[i] <= 'Z')){
            str[i] = str[i]+32;
        }
        i++;
    }
}

// Example
// Input: HELLO WORLD
// Output: hello world

void appendStrings(char *str1, char *str2){
    int i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

// Output: If str1 = "Hello", str2 = " World", then str1 = "Hello World"

int compareStrings(char *str1, char *str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    // If we reached here, one of the strings is a prefix of the other
    return str1[i] - str2[i];
}

 // Output: If str1 is "Hello" and str2 is "Hello", return 0
// If str1 is "Hello" and str2 is "World", return a negative value
// If str1 is "World" and str2 is "Hello", return a positive value

// Meaning of comparing strings
// If str1 is less than str2, return a negative value
// If str1 is greater than str2, return a positive value
// If they are equal, return 0


void reverseString(char *str){
    int len = findLength(str);
    int i = 0, j = len - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Output: If str = "Hello", then str = "olleH"


int main(){
    char str1[100], str2[100];
    
    // Q1. Finding the length of the string
    printf("Enter a string to find its length: ");
    gets(str1);
    printf("Length of the string: %d\n", findLength(str1));
    
    // Q2. Converting a string to lowercase from uppercase
    printf("Enter a string to convert to lowercase: ");
    gets(str1);
    toLowerCase(str1);
    printf("Lowercase string: %s\n", str1);
    
    // Q3. Appending a string to another string
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    printf("Enter second string to append: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character
    appendStrings(str1, str2);
    printf("Appended string: %s\n", str1);

    // Q4. Compare two strings
    printf("Enter first string to compare: ");
    gets(str1);
    printf("Enter second string to compare: ");
    gets(str2);
    int cmpResult = compareStrings(str1, str2);
    if(cmpResult == 0) {
        printf("Strings are equal.\n");
    } else if(cmpResult < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }

    // Q5. Reverse a given string
    printf("Enter a string to reverse: ");
    gets(str1);
    reverseString(str1);
    printf("Reversed string: %s\n", str1);

    return 0;
}