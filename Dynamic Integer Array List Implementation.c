/*
Dynamic Integer Array List Implementation
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h" // implement intlist.h first, store header file in the same folder

// ------------------------------------
// Question 1: Implementing a Dynamic IntArrayList
// ------------------------------------
/*
    This structure stores an expandable array of integers.
    It tracks:
    - The current number of elements (size)
    - The maximum possible capacity (capacity)
    The list dynamically resizes when full using realloc.
*/

// ------------------------------------
// Function: Create List from Data
// ------------------------------------
/*
    Allocates memory for an IntList object and initializes it.
    - The provided data array is assigned to the list.
    - The size is set based on the given array.
    - The capacity is initially set to match the size.
*/
void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    *p_IntList = (IntList *)malloc(sizeof(IntList)); // Allocate memory for IntList
    (*p_IntList)->data = (int *)malloc(size * sizeof(int)); // Allocate memory for integer array
    memcpy((*p_IntList)->data, data_arr, size * sizeof(int)); // Copy data into list
    (*p_IntList)->size = size; // Set current size
    (*p_IntList)->capacity = size; // Set initial capacity
}

// ------------------------------------
// Function: Append Element
// ------------------------------------
/*
    Adds a new element to the end of the list.
    If capacity is exceeded, realloc is used to double the storage capacity.
*/
void list_append(IntList *list, int new_elem) {
    if (list->size == list->capacity) { // Check if capacity is full
        list->capacity *= 2; // Double the capacity
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int)); // Expand memory
    }
    list->data[list->size] = new_elem; // Append element at the end
    list->size++; // Increase size counter
}

// ------------------------------------
// Function: Insert Element at Index
// ------------------------------------
/*
    Inserts an element at a specific index.
    - If capacity is exceeded, the list expands.
    - Elements from the index onward are shifted using memmove().
*/
void list_insert(IntList *list, int new_elem, int index) {
    if (index < 0 || index > list->size) return; // Ensure valid index
    
    if (list->size == list->capacity) { // Expand if necessary
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int)); // Shift elements
    list->data[index] = new_elem; // Insert new element
    list->size++; // Increase size counter
}

// ------------------------------------
// Function: Delete Element at Index
// ------------------------------------
/*
    Removes an element from a specific index.
    - Remaining elements are shifted left to fill the gap.
*/
void list_delete(IntList *list, int index) {
    if (index < 0 || index >= list->size) return; // Ensure valid index
    
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int)); // Shift left
    list->size--; // Reduce size counter
}

// ------------------------------------
// Function: Destroy List
// ------------------------------------
/*
    Frees the memory used by the list.
    - First, free the dynamically allocated array.
    - Then, free the IntList structure itself.
*/
void list_destroy(IntList *list) {
    free(list->data); // Free integer array first
    free(list); // Free the IntList structure
}

// ------------------------------------
// Function: Get Element at Index
// ------------------------------------
/*
    Returns the element at a specific index.
    - Returns -1 if the index is out of bounds.
*/
int list_get(IntList *list, int index) {
    if (index < 0 || index >= list->size) return -1; // Ensure valid index
    return list->data[index]; // Return the value at the given index
}
