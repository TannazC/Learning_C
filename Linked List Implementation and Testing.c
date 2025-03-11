/*
Linked List Implementation and Testing
Author: Tannaz Chowdhury  
GitHub: TannazC  
Date: 2025  
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h" // practice using header files and initializing functions first!

// ------------------------------------
// Question 1: Append Node to Linked List
// ------------------------------------
/*
    Implements a function to append a new node to a linked list.
    Assumption: The last node's `next` field is NULL.
*/

// Creates a new node with the given data
void create_node(node **new_node, int new_elem) {
    *new_node = (node *)malloc(sizeof(node)); // Allocate memory for new node
    if (*new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*new_node)->data = new_elem; // Assign data to the new node
    (*new_node)->next = NULL; // Initialize next pointer to NULL
}

// Appends a new element to the linked list
void LL_append(LL *my_list, int new_elem) {
    node *new_node; // Pointer for new node
    create_node(&new_node, new_elem); // Create the new node
    
    if (my_list->head == NULL) { // If list is empty
        my_list->head = new_node; // Set head to new node
    } else {
        node *current_node = my_list->head; // Start at head
        while (current_node->next != NULL) { // Traverse to last node
            current_node = current_node->next;
        }
        current_node->next = new_node; // Attach new node at the end
    }
    my_list->size++; // Increase list size
}

// ------------------------------------
// Question 2: Validate List Length
// ------------------------------------
/*
    Checks if the recorded list size matches the actual count of nodes.
    Returns 1 if valid, otherwise returns 0.
*/
int validate_list_length(LL *my_list) {
    int record_length = 0; // Initialize counter
    node *current_node = my_list->head; // Start at head
    while (current_node != NULL) { // Traverse list
        current_node = current_node->next;
        record_length++;
    }
    return (record_length == my_list->size) ? 1 : 0; // Compare sizes
}

// ------------------------------------
// Question 3: Delete Node by Index
// ------------------------------------
/*
    Deletes a node at the specified index and updates the linked list.
    Ensures proper memory deallocation.
*/
void delete_node(LL *my_list, int index) {
    if (index < 0 || index >= my_list->size) return; // Ensure valid index
    
    node *current_node = my_list->head; // Start at head
    node *previous_node = NULL;
    
    if (index == 0) { // Deleting the first node
        my_list->head = current_node->next; // Update head
        free(current_node); // Free removed node
    } else {
        for (int i = 0; i < index; i++) { // Traverse to the node before target
            previous_node = current_node;
            current_node = current_node->next;
        }
        previous_node->next = current_node->next; // Link previous to next
        free(current_node); // Free removed node
    }
    my_list->size--; // Decrease list size
}
