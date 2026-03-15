#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Function to insert an element while maintaining sorted order (Smallest first)
void insert(int x) {
    if (size >= MAX) {
        return; // Queue is full
    }

    int i = size - 1;
    // Shift elements that are greater than x to the right
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    // Insert x at its correct sorted position
    pq[i + 1] = x;
    size++;
}

// Function to remove and print the element with the highest priority (smallest value)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    // The smallest element is at index 0
    printf("%d\n", pq[0]);

    // Shift all remaining elements to the left
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Function to print the highest priority element without removing it
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int n;
    // Read number of operations
    if (scanf("%d", &n) != 1) return 0;

    char command[20];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(command, "delete") == 0) {
            delete();
        } else if (strcmp(command, "peek") == 0) {
            peek();
        }
    }

    return 0;
}