#include <stdio.h>
#include <stdlib.h> // Required for malloc and free functions

// Define a structure for a Node in the linked list
struct Node {
    int data;           // Holds the data value of the node
    struct Node *next;  // Pointer to the next node in the linked list
};

// Function to traverse a circular linked list and print its elements
void linkedListTraversal(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *ptr = head; // Start from the head
    do {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; // Move to the next node
    } while (ptr != head); // Stop when we come back to the head
}

// Function to insert a new node at the beginning of the circular linked list
struct Node *insertAtFirst(struct Node *head, int data) {
    // Create a new node and allocate memory in the heap
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data; // Set the data for the new node

    if (head == NULL) { 
        // If the list is empty, point the new node to itself
        ptr->next = ptr;
        return ptr;
    }

    // Use another pointer to traverse to the last node
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }
    p->next = ptr; // Update the last node's next pointer
    ptr->next = head; // Point the new node to the current head
    head = ptr; // Make the new node the new head
    return head;
}

int main() {
    struct Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Assign data and link nodes to form a circular linked list
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head; // Circular link to the head

    printf("Original Circular Linked List:\n");
    linkedListTraversal(head);

    // Insert a new node at the beginning of the circular linked list
    head = insertAtFirst(head, 10);

    printf("\nCircular Linked List After Insertion at Beginning:\n");
    linkedListTraversal(head);

    return 0; // End of the program
}
