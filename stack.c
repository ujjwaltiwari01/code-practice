#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack
struct stack {
    int size;    // Maximum size of the stack 
    int top;     // Index of the topmost element    
    int *array;  // Pointer to the array for stack elements
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr) {
    return (ptr->top == -1); 
}

// Function to check if the stack is full
int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1); 
}

// Function to push an element onto the stack
void push(struct stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack overflow! Can't push %d to the stack\n", val);
    } else {
        ptr->top++;
        ptr->array[ptr->top] = val;
    }
}

// Function to pop an element from the stack
int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        int val = ptr->array[ptr->top]; // Retrieve the top element
        ptr->top--;                    // Decrement the top index
        return val;                    // Return the popped value
    }
}

// Function to get the topmost element 
int stackTop(struct stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return sp->array[sp->top];
}

// Function to get the bottommost element of the stack
int stackBottom(struct stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack is empty! No bottom element.\n");
        return -1;
    }
    return sp->array[0];
}

// Main function to test the stack implementation
int main() {
    // Create a stack and allocate memory
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    if (!sp) {
        printf("Memory allocation failed for stack structure.\n");
        return 1;
    }
    
    sp->size = 50;
    sp->top = -1;
    sp->array = (int *)malloc(sp->size * sizeof(int));
    if (!sp->array) {
        printf("Memory allocation failed for stack array.\n");
        free(sp);
        return 1;
    }

    printf("Stack has been created successfully\n");

    // Check stack status before operations
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    // Push elements onto the stack
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);

    // Display the top and bottom elements
    printf("Topmost element: %d\n", stackTop(sp));
    printf("Bottommost element: %d\n", stackBottom(sp));

    // Pop an element and show the updated stack state
    printf("Popped element: %d\n", pop(sp));
    printf("Topmost element after pop: %d\n", stackTop(sp));

    // Free allocated memory
    free(sp->array);
    free(sp);

    return 0;
}
