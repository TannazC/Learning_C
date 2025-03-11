/*
Intro Basics
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdio.h>

// ------------------------------------
// Question 1: Modify an Integer via Pointer
// ------------------------------------
/*
    Define an integer variable and initialize it to 5. 
    Implement a function that modifies its value to 10 using a pointer. 
    Demonstrate the change using printf.
    Trace the execution using a debugger.
*/
void change_a(int *a) { 
    *a = 10; // Dereference the pointer and update the value to 10
}

int main() {
    int a = 5; // Declare an integer variable
    printf("Before change: %d\n", a); // Print initial value
    change_a(&a); // Pass address of 'a' to function
    printf("After change: %d\n", a); // Print modified value
    return 0;
}

// ------------------------------------
// Question 3: Modify Character Array
// ------------------------------------
/*
    Initialize a character array of size 100.
    Implement a function that modifies its contents.
    Print the modified array.
*/
void change_arr(char *arr) {
    for (int i = 0; i < 100; i++) { // Iterate over each element
        arr[i] = 'A' + (i % 26); // Assign characters cyclically from A-Z
    }
}

int main() {
    char arr[100]; // Declare character array
    change_arr(arr); // Call function to modify array
    printf("Modified array: %s\n", arr); // Print modified array
    return 0;
}

// ------------------------------------
// Question 4: Insertion Sort Implementation
// ------------------------------------
/*
    Implement insertion sort algorithm.
    The function takes an integer array and sorts it in ascending order.
*/
void insertion_sort(int *A, int size) {
    for (int i = 1; i < size; i++) { // Start from second element
        int key = A[i]; // Store current element
        int j = i - 1; // Start comparing with previous elements
        while (j >= 0 && A[j] > key) { // Shift larger elements forward
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; // Place key at the correct position
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2}; // Declare unsorted array
    int size = sizeof(A) / sizeof(A[0]); // Compute number of elements
    
    insertion_sort(A, size); // Sort array
    printf("Sorted array: "); // Print header
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]); // Print sorted elements
    }
    printf("\n"); // New line
    return 0;
}

// ------------------------------------
// Question 5: String Length Calculation
// ------------------------------------
/*
    Implement a function to compute the length of a string without using strlen().
    Return the length by iterating until the null terminator is encountered.
*/
int string_length(const char *str) {
    int length = 0; // Initialize length counter
    while (str[length] != '\0') { // Iterate until null terminator
        length++;
    }
    return length; // Return computed length
}

int main() {
    char *string = "cats"; // Declare string
    printf("Length of string: %d\n", string_length(string)); // Print string length
    return 0;
}

// ------------------------------------
// Question 6: Replace Subsequence in Array
// ------------------------------------
/*
    Replace every occurrence of arr2 in arr1 with zeros.
    The function loops through arr1 and checks for arr2.
    If a match is found, it replaces the subsequence with zeros.
*/
void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    if (arr2_sz == 0 || arr1_sz < arr2_sz) return; // Handle edge cases

    for (unsigned long i = 0; i <= arr1_sz - arr2_sz; i++) { // Iterate over arr1
        int match = 1; // Assume a match
        for (unsigned long j = 0; j < arr2_sz; j++) { // Check if subsequence matches
            if (arr1[i + j] != arr2[j]) {
                match = 0; // Set flag if mismatch found
                break;
            }
        }
        if (match) { // If match found, replace with zeros
            for (unsigned long j = 0; j < arr2_sz; j++) {
                arr1[i + j] = 0;
            }
        }
    }
}

void print_array(int *arr, unsigned long size) {
    for (unsigned long i = 0; i < size; i++) { // Iterate and print each element
        printf("%d ", arr[i]);
    }
    printf("\n"); // New line
}

int main() {
    int a[] = {5, 6, 7, 8, 6, 7}; // Input array
    int b[] = {6, 7}; // Subsequence to replace
    seq_replace(a, 6, b, 2); // Call function to replace subsequence
    print_array(a, 6); // Print modified array
    return 0;
}
