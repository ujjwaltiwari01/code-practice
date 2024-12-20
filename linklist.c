#include <stdio.h>
#include <stdlib.h> // Required for malloc and free functions

// Define a structure for a Node in the linked list
struct Node {
    int data;           // Holds the data value of the node
    struct Node *next;  // Pointer to the next node in the linked list
};

// Function to traverse the linked list and print its elements
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) { // Use NULL instead of null
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; // Move to next node
    }
}

// Case 1: Deleting the first node in the linked list
struct Node *deleteFirst(struct Node *head) {
    struct Node *ptr = head; // Temporary pointer to the current head
    head = head->next;       // Move the head to the next node
    free(ptr);               // Free the memory of the old head
    return head;             // Return the new head of the list
}

// Case 2: Deleting a node at a specific index
struct Node *deleteAtIndex(struct Node *head, int index) {
    struct Node *p = head;        // Pointer to traverse the list
    struct Node *q = head->next;  // Pointer to the next node
    for (int i = 0; i < index - 1 && q != NULL; i++) { // Added boundary condition for safety
        p = p->next; // Move p to the desired position
        q = q->next; // Move q one step ahead of p
    }
    if (q != NULL) {
        p->next = q->next;
        free(q);
    }
    return head;
}

// Case 3: Deleting the last node in the linked list
struct Node *deleteAtLast(struct Node *head) {
    struct Node *p = head;      // Pointer to traverse the list
    struct Node *q = head->next; // Pointer to the next node
    while (q->next != NULL) {   // Corrected syntax (!= instead of !)
        p = p->next; // Move p to the next node
        q = q->next; // Move q to the next node
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting a node with a given value
struct Node *deleteByValue(struct Node *head, int value) {
    struct Node *p = head;
    struct Node *q = head->next;
    while (q != NULL && q->data != value) { // Added NULL check before accessing q->data
        p = p->next;
        q = q->next;
    }
    if (q != NULL && q->data == value) { // If the value is found
        p->next = q->next;
        free(q);
    }
    return head;
}

int main() {
    struct Node *head, *second, *third, *fourth;

    // Allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes and assigning data
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion:\n");
    linkedListTraversal(head);

    head = deleteAtLast(head); // Delete the last node

    printf("Linked list after deletion:\n");
    linkedListTraversal(head);

    return 0;
}
