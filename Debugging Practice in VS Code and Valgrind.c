/*
Debugging Practice in VS Code and Valgrind
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdio.h>

// ------------------------------------
// Question 1: Postmortem Debugging & Memory Analysis
// ------------------------------------
/*
    This question focuses on debugging segmentation faults and memory leaks
    using VS Code and Valgrind.
*/

// ------------------------------------
// Part (a): Create a Segmentation Fault
// ------------------------------------
/*
    This program attempts to access an invalid memory location, causing a segmentation fault.
    Run this in VS Code and analyze which line causes the error and the values of local variables.
*/

int main() {
    int *a = NULL;  // Declare a null pointer (uninitialized memory)
    int b = *a;  // Attempt to dereference NULL (causes segmentation fault)
    return 0;  // Program never reaches this line due to crash
}

// ------------------------------------
// Part (b): Analyze Segmentation Fault with Valgrind
// ------------------------------------
/*
    When running the above code on ECF using Valgrind:
    - Expected error: "Invalid read of size 4"
    - Access not within mapped region at address 0x0
    - "Segmentation fault (core dumped)"
    Use Valgrind to determine the exact issue and track memory access.
*/

// ------------------------------------
// Part (c): Inducing a Memory Leak
// ------------------------------------
/*
    This program reads a file but does not close it, causing a memory leak.
    Run Valgrind on ECF to observe the memory leak.
*/

int main() {
    FILE *fp;  // Declare file pointer
    char myString[100];  // Buffer to store file content
    
    fp = fopen("a.txt", "r");  // Open file in read mode
    if (fp == NULL) {  // Check if file opened successfully
        printf("Error: Unable to open file.\n");
        return 1;  // Exit program if file cannot be opened
    }
    
    fgets(myString, 100, fp);  // Read content from file
    printf("%s", myString);  // Print file content
    
    // Uncommenting the following line fixes the memory leak:
    // fclose(fp);  // Close file to free system resources
    
    return 0;  // Memory leak occurs if fclose(fp) is not used
}

// ------------------------------------
// Part (d): Handling File Open Errors
// ------------------------------------
/*
    This program correctly handles the case where a file cannot be opened.
    If fopen() fails, an error message is displayed instead of causing undefined behavior.
*/

int main() {
    FILE *fp;  // Declare file pointer
    char myString[100];  // Buffer to store file content
    
    fp = fopen("fp.txt", "r");  // Attempt to open file in read mode
    if (fp == NULL) {  // Check if fopen() failed
        printf("Error: Could not open file.\n");
        return 1;  // Exit with error code
    }
    
    fgets(myString, 100, fp);  // Read content from file
    printf("%s", myString);  // Print file content
    
    fclose(fp);  // Properly close the file to avoid memory leaks
    return 0;
}