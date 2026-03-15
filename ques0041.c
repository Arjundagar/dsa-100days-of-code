#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global pointers to keep track of the front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element (Enqueue)
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    // Add the new node at the end of the queue and update rear
    rear->next = newNode;
    rear = newNode;
}

// Function to remove an element (Dequeue)
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data); // Print the dequeued element

    // Move front to the next node
    front = front->next;

    // If the queue becomes empty after dequeue, reset rear to NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free the memory of the removed node
}

int main() {
    int n;
    
    // Read the total number of operations
    if (scanf("%d", &n) != 1) return 0;

    char command[20];
    int value;

    for (int i = 0; i < n; i++) {
        // Read the command (enqueue or dequeue)
        scanf("%s", command);

        if (strcmp(command, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(value);
        } else if (strcmp(command, "dequeue") == 0) {
            dequeue();
        } else {
            // This catches typos like 'depueue'
            printf("Error: Unknown command '%s'\n", command);
        }
    }

    return 0;
}