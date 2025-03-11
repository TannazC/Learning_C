/*
Student Data Management and Memory Allocation
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------
// Question 1: Value vs. Pointer Function
// ------------------------------------
/*
    Demonstrates the difference between passing an integer by value
    and passing an integer by pointer to modify the original variable.
*/

void set_int1(int x) {
    x = 42; // Assigns 42 to local copy of 'x', does not affect original variable
}

void set_int2(int *p_x) {
    *p_x = 42; // Dereferences pointer and modifies original variable
}

int main() {
    int y = 25; // Declare integer variable
    set_int1(y); // Pass by value (no effect outside function)
    printf("After set_int1: %d\n", y); // Still prints 25
    set_int2(&y); // Pass address of y (modifies original variable)
    printf("After set_int2: %d\n", y); // Now prints 42
    return 0;
}

// ------------------------------------
// Question 2: Struct and Printing Student Data
// ------------------------------------
/*
    Defines a structure for student data and demonstrates initialization and printing.
*/

typedef struct student1 {
    char name[200]; // Fixed-size character array for name
    char student_number[11]; // Fixed-size character array for student number
    int year; // Integer representing academic year
} student1;

int main() {
    student1 s1 = {"Alice", "1010940010", 2}; // Initialize struct
    printf("My name is: %s\n", s1.name); // Print name
    printf("My student number is: %s\n", s1.student_number); // Print student number
    return 0;
}

// ------------------------------------
// Question 3: Modify Struct by Pointer
// ------------------------------------
/*
    Modifies struct fields using a pointer to change values.
*/

void set_default_name(student1 *p_s) {
    strcpy(p_s->name, "Default Student"); // Copy string into struct field
    p_s->year = 0; // Set year to 0
}

int main() {
    student1 s1; // Declare struct variable
    set_default_name(&s1); // Pass struct pointer to function
    printf("Student Name: %s, Year: %d\n", s1.name, s1.year); // Print updated values
    return 0;
}

// ------------------------------------
// Question 4: Dynamic Memory Allocation for Struct
// ------------------------------------
/*
    Allocates memory dynamically for an array of students.
*/

void create_block1(student1 **p_p_s, int n_students) {
    *p_p_s = (student1 *)malloc(sizeof(student1) * n_students); // Allocate memory
    if (*p_p_s == NULL) { // Check if allocation failed
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

int main() {
    student1 *s1; // Declare pointer to student1 struct
    create_block1(&s1, 3); // Allocate memory for 3 students
    printf("Memory allocated for 3 students.\n");
    free(s1); // Free allocated memory
    return 0;
}

// ------------------------------------
// Question 6: Freeing Allocated Memory
// ------------------------------------
/*
    Deallocates memory for dynamically allocated student structs.
*/

void destroy_block1(student1 **p_p_s) {
    if (*p_p_s != NULL) { // Check if pointer is not NULL
        free(*p_p_s); // Free allocated memory
        *p_p_s = NULL; // Avoid dangling pointer
    }
}

int main() {
    student1 *s1; // Declare pointer
    create_block1(&s1, 3); // Allocate memory
    destroy_block1(&s1); // Free memory
    if (s1 == NULL) { // Check if pointer is NULL
        printf("Memory successfully freed.\n");
    }
    return 0;
}

// ------------------------------------
// Question 7: Struct with Dynamic Strings
// ------------------------------------
/*
    Allocates memory for student structs but does not allocate memory for names yet.
*/

typedef struct student2 {
    char *name; // Pointer to dynamically allocated string
    char *student_number; // Pointer to dynamically allocated student number
    int year; // Integer storing academic year
} student2;

void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = (student2 *)malloc(sizeof(student2) * num_students); // Allocate memory
    if (*p_p_s == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < num_students; i++) { // Initialize each student entry
        (*p_p_s)[i].name = NULL;
        (*p_p_s)[i].student_number = NULL;
        (*p_p_s)[i].year = 0;
    }
}

int main() {
    student2 *students; // Declare pointer to student array
    create_block2(&students, 3); // Allocate memory
    free(students); // Free allocated memory
    return 0;
}

// ------------------------------------
// Question 8: Assigning Names Dynamically
// ------------------------------------
/*
    Dynamically assigns names to student2 structs.
*/

void set_name2(student2 *p_s, const char *new_name) {
    p_s->name = (char *)malloc(strlen(new_name) + 1); // Allocate memory for name
    if (p_s->name == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(p_s->name, new_name); // Copy name into allocated memory
}

int main() {
    student2 *students; // Declare pointer
    create_block2(&students, 3); // Allocate memory
    set_name2(&students[0], "Alice Johnson"); // Assign name to first student
    printf("Student Name: %s\n", students[0].name); // Print assigned name
    free(students[0].name); // Free allocated name
    free(students); // Free allocated array
    return 0;
}