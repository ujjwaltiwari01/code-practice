#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
struct Node {
    int data;            // Data to store the value
    struct Node* next;   // Pointer to the next node
};

// Declaring a global top pointer to represent the top of the stack
struct Node* top = NULL;

// Function to traverse and print the stack elements
void linkedListTraversal(struct Node* ptr) {
    // Iterate through the stack until the pointer becomes NULL
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);  // Print the current element
        ptr = ptr->next;                    // Move to the next node
    }
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;  // Return 1 if top is NULL, otherwise 0
}

// Function to check if the stack is full
// In a linked list, stack is full if memory cannot be allocated
int isFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node)); // Try allocating memory
    if (p == NULL) {
        return 1;  // Memory allocation failed
    } else {
        free(p);    // Free allocated memory
        return 0;
    }
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");  // If memory allocation fails, stack is full
        return top;
    } else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Create a new node
        n->data = x;        // Assign the value to the new node
        n->next = top;      // Point the new node to the current top
        top = n;            // Update the top to the new node
        return top;
    }
}

// Function to pop the top element from the stack
int pop() {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");  // If stack is empty, nothing to pop
        return -1;
    } else {
        struct Node* n = top;  // Store the current top node in a temporary pointer
        top = top->next;       // Update the top pointer to the next node
        int x = n->data;       // Get the data from the current top node
        free(n);               // Free the memory of the popped node
        return x;              // Return the popped value
    }
}

// Function to peek at an element at a specific position (1-based index)
int peek(int pos) {
    struct Node* ptr = top;  // Create a pointer to traverse the stack
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++) {
        ptr = ptr->next;     // Move to the desired position
    }
    if (ptr != NULL) {
        return ptr->data;    // Return the data at the given position
    } else {
        return -1;           // If position is invalid, return -1
    }
}

// Function to get the top element of the stack
int stackTop() {
    if (!isEmpty(top)) {
        return top->data;  // Return the data of the top node
    } else {
        printf("Stack is empty\n");
        return -1;         // Return -1 if stack is empty
    }
}

// Function to get the bottom element of the stack
int stackBottom(struct Node* top) {
    struct Node* ptr = top;  // Create a pointer to traverse the stack
    while (ptr->next != NULL) {
        ptr = ptr->next;    // Move to the last node
    }
    return ptr->data;       // Return the data of the last node
}

// Main function
int main() {
    // Push elements onto the stack
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    // Display the stack elements
    printf("Stack elements:\n");
    linkedListTraversal(top);

    // Peek at different positions
    printf("\nPeeking at stack positions:\n");
    for (int i = 1; i <= 4; i++) {
        printf("Value at position %d is: %d\n", i, peek(i));
    }

    // Display the top and bottom elements
    printf("\nTop element is: %d\n", stackTop());
    printf("Bottom element is: %d\n", stackBottom(top));

    // Pop elements and show the updated stack
    printf("\nPopping elements:\n");
    printf("Popped element is: %d\n", pop());
    printf("After popping, top element is: %d\n", stackTop());

    return 0;
}
