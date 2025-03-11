/*
[ Program Name ]
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------
// Question 1: Set Even-Indexed Elements to Zero
// ------------------------------------
/*
    This function sets all elements at even indices in an integer array to 0.
    Example:
    Input: {5, 6, 7, 8}
    Output: {0, 6, 0, 8}
*/
void set_even_to_zero(int *block, int size) {
    for (int i = 0; i < size; i += 2) { // Loop through even indices
        block[i] = 0; // Modify array in-place using pointer dereferencing
    }
}

int main() {
    int block[] = {1, 2, 3, 4}; // Declare integer array
    int size = sizeof(block) / sizeof(block[0]); // Compute number of elements
    set_even_to_zero(block, size); // Call function to modify array
    
    printf("Modified array: "); // Print header
    for (int i = 0; i < size; i++) { // Loop through array
        printf("%d ", block[i]); // Print each element
    }
    printf("\n"); // New line
    return 0;
}

// ------------------------------------
// Question 2: String Concatenation (Two Versions)
// ------------------------------------
/*
    Implement two versions of strcat():
    - Version 1: Uses indexing
    - Version 2: Uses pointer arithmetic
*/

// Version 1 - Using Indexing
char *strcat1(char *destination, const char *source) {
    int length = strlen(destination); // Find end of destination string
    for (int i = 0; source[i] != '\0'; i++) { // Iterate over source string
        destination[length++] = source[i]; // Copy characters one by one
    }
    destination[length] = '\0'; // Add null terminator at the end
    return destination; // Return modified string
}

// Version 2 - Using Pointer Arithmetic
char *strcat2(char *destination, const char *source) {
    while (*destination) destination++; // Move pointer to end of destination string
    while ((*destination++ = *source++)); // Copy characters, including null terminator
    return destination; // Return modified string
}

int main() {
    char str1[100] = "Hello, "; // Destination string with sufficient space
    char str2[] = "World!"; // Source string
    
    strcat1(str1, str2); // Concatenate using indexing
    printf("Concatenated (Indexing): %s\n", str1);
    
    strcpy(str1, "Hello, "); // Reset str1
    strcat2(str1, str2); // Concatenate using pointer arithmetic
    printf("Concatenated (Pointer Arithmetic): %s\n", str1);
    return 0;
}

// ------------------------------------
// Question 3: Recursive String Comparison
// ------------------------------------
/*
    Implement a recursive version of strcmp().
    The function compares two strings character by character.
*/
int strcmp_recursive(const char *str1, const char *str2) {
    if (*str1 != *str2) return (*str1 > *str2) - (*str1 < *str2); // Compare characters
    if (*str1 == '\0') return 0; // Base case: both strings end
    return strcmp_recursive(str1 + 1, str2 + 1); // Move to next character recursively
}

int main() {
    printf("strcmp_recursive(\"abcd\", \"abCd\") = %d\n", strcmp_recursive("abcd", "abCd")); // Compare different strings
    printf("strcmp_recursive(\"abcd\", \"abcd\") = %d\n", strcmp_recursive("abcd", "abcd")); // Compare identical strings
    return 0;
}

// ------------------------------------
// Question 4: Binary Search Deluxe
// ------------------------------------
/*
    Find both the first and last occurrence of a target in a sorted array.
    Runs in O(log n) time.
*/
int find_first(int arr[], int size, int target) {
    int left = 0, right = size - 1, first_index = -1; // Initialize variables
    while (left <= right) {
        int mid = left + (right - left) / 2; // Midpoint calculation
        if (arr[mid] == target) {
            first_index = mid; // Possible first occurrence
            right = mid - 1; // Move search space left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first_index; // Return first occurrence index
}

int find_last(int arr[], int size, int target) {
    int left = 0, right = size - 1, last_index = -1; // Initialize variables
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last_index = mid; // Possible last occurrence
            left = mid + 1; // Move search space right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last_index; // Return last occurrence index
}

void binary_search_deluxe(int arr[], int size, int target, int result[2]) {
    result[0] = find_first(arr, size, target); // Find first occurrence
    result[1] = find_last(arr, size, target); // Find last occurrence
}

int main() {
    int arr[] = {1, 2, 3, 10, 10, 10, 12, 12}; // Example sorted array
    int result[2]; // Array to store results
    binary_search_deluxe(arr, 8, 10, result); // Perform search
    printf("First and Last Occurrence: [%d, %d]\n", result[0], result[1]); // Print results
    return 0;
}

// ------------------------------------
// Question 5: Custom atoi() Function
// ------------------------------------
/*
    Convert a numeric string to an integer.
    Handles leading whitespace and optional signs.
*/
int my_atoi(char *str) {
    int result = 0, sign = 1;
    while (*str == ' ' || *str == '\t' || *str == '\n') str++; // Skip whitespace
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1; // Handle sign
        str++;
    }
    while (isdigit(*str)) {
        result = result * 10 + (*str - '0'); // Convert digit to integer
        str++;
    }
    return result * sign; // Return final integer with sign
}

int main() {
    printf("my_atoi(\"   123\") = %d\n", my_atoi("   123")); // Convert positive number
    printf("my_atoi(\"-456\") = %d\n", my_atoi("-456")); // Convert negative number
    printf("my_atoi(\"+789\") = %d\n", my_atoi("+789")); // Convert explicitly positive number
    printf("my_atoi(\"42abc\") = %d\n", my_atoi("42abc")); // Convert number with trailing characters
    return 0;
}
