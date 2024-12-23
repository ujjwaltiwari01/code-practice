#include <stdio.h>
#include <stdlib.h>

// Defining the queue structure
struct queue {
    int size;   // Maximum size of the queue
    int f;      // Index of the front of the queue
    int r;      // Index of the rear of the queue
    int* arr;   // Pointer to the dynamically allocated array
};

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    // A queue is empty when front and rear indices are -1
    return (q->f == -1);
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    // A queue is full when the rear index equals size - 1
    return (q->r == q->size - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct queue* q, int val) {
    if (isFull(q)) {
        // If the queue is full, we cannot add any more elements
        printf("This Queue is full. Cannot enqueue %d.\n", val);
    } else {
        if (q->f == -1) {
            // If the queue is empty, set the front index to 0
            q->f = 0;
        }
        // Move the rear index forward and insert the value
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct queue* q) {
    int dequeuedValue = -1; // Initialize a variable to store the dequeued value
    if (isEmpty(q)) {
        // If the queue is empty, we cannot remove any elements
        printf("This Queue is empty. Cannot dequeue.\n");
    } else {
        // Get the value at the front of the queue
        dequeuedValue = q->arr[q->f];
        if (q->f == q->r) {
            // If there is only one element left, reset the queue
            q->f = q->r = -1;
        } else {
            // Otherwise, move the front index forward
            q->f++;
        }
        printf("Dequeued element: %d\n", dequeuedValue);
    }
    return dequeuedValue; // Return the dequeued value
}

// Main function to demonstrate the queue operations
int main() {
    // Step 1: Create and initialize the queue
    struct queue q;
    q.size = 4;          // Set the maximum size of the queue
    q.f = q.r = -1;      // Initialize front and rear indices to -1 (empty queue)
    q.arr = (int*)malloc(q.size * sizeof(int)); // Dynamically allocate memory for the array

    // Step 2: Demonstrate enqueue operations
    enqueue(&q, 10); // Add 10 to the queue
    enqueue(&q, 20); // Add 20 to the queue
    enqueue(&q, 30); // Add 30 to the queue
    enqueue(&q, 40); // Add 40 to the queue
    enqueue(&q, 50); // Attempt to add 50 (should fail since the queue is full)

    // Step 3: Demonstrate dequeue operations
    dequeue(&q); // Remove the first element (10)
    dequeue(&q); // Remove the second element (20)

    // Step 4: Add more elements after dequeuing
    enqueue(&q, 50); // Add 50 to the queue
    enqueue(&q, 60); // Add 60 to the queue

    // Step 5: Check if the queue is full or empty
    if (isEmpty(&q)) {
        printf("Queue is empty.\n");
    }
    if (isFull(&q)) {
        printf("Queue is full.\n");
    }

    // Step 6: Free allocated memory to avoid memory leaks
    free(q.arr);
    
    return 0;
}
