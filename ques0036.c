#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int n, m, value;

    // Read number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;

    // Enqueue operations
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }

    // Read number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;

    // Dequeue operations
    for (int i = 0; i < m; i++) {
        if (front == -1) break; // Queue empty

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display remaining elements from front to rear
    if (front != -1) {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }

    return 0;
}