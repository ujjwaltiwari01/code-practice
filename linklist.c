#include <stdio.h>
#include <stdlib.h> // Required for malloc and free functions

// Define a structure for a Node in the linked list
struct Node {
    int data;           // Holds the data value of the node
    struct Node *next;  // Pointer to the next node in the linked list
};

// Function to traverse the linked list and print its elements
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) { // Loop until the end of the list
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; // Move to the next node
    }
}

// Case 1: Deleting the first node in the linked list
struct Node *deleteFirst(struct Node *head) {
    struct Node *ptr = head;   // Temporary pointer to the current head
    head = head->next;         // Move the head to the next node
    free(ptr);                 // Free the memory of the old head
    return head;               // Return the new head of the list
}

// Case 2: Deleting a node at a specific index
struct Node *deleteAtIndex(struct Node *head, int index) {
    struct Node *p = head;      // Pointer to traverse the list
    struct Node *q = head->next; // Pointer to the next node
    for (int i = 0; i < index - 1; i++) {
        p = p->next; // Move `p` to the desired position
        q = q->next; // Move `q` one step ahead of `p`
    }
    p->next = q->next; // Skip the node to be deleted
    free(q);           // Free the memory of the deleted node
    return head;
}

// Case 3: Deleting the last node in the linked list
struct Node *deleteAtLast(struct Node *head) {
    struct Node *p = head;      // Pointer to traverse the list
    struct Node *q = head->next; // Pointer to the next node
    while (q->next != NULL) {   // Stop at the second last node
        p = p->next; // Move `p` to the next node
        q = q->next; // Move `q` to the next node
    }
    p->next = NULL;  // Disconnect the last node
    free(q);         // Free the memory of the last node
    return head;
}

// Case 4: Deleting a node with a given value
struct Node *deleteByValue(struct Node *head, int value) {
    struct Node *p = head;      // Pointer to traverse the list
    struct Node *q = head->next; // Pointer to the next node
    while (q->data != value && q->next != NULL) { // Traverse until the value is found
        p = p->next; // Move `p` to the next node
        q = q->next; // Move `q` to the next node
    }
    if (q->data == value) {    // If the value is found
        p->next = q->next;     // Skip the node with the value
        free(q);               // Free the memory of the deleted node
    }
    return head;
}

int main() {
    // Creating nodes for the linked list
    struct Node *head, *second, *third, *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));   // Allocate memory for the first node
    second = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the second node
    third = (struct Node *)malloc(sizeof(struct Node));  // Allocate memory for the third node
    fourth = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the fourth node

    // Linking nodes and assigning data
    head->data = 4;    head->next = second;
    second->data = 3;  second->next = third;
    third->data = 8;   third->next = fourth;
    fourth->data = 1;  fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // Uncomment one of the following to test deletion cases:
    // head = deleteFirst(head);               // Delete the first node
    // head = deleteAtIndex(head, 2);          // Delete the node at index 2
    head = deleteAtLast(head);               // Delete the last node
    // head = deleteByValue(head, 8);          // Delete the node with value 8

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
