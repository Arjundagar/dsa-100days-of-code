#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple Queue Structure
int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int val) {
    if (count < MAX) {
        rear = (rear + 1) % MAX;
        queue[rear] = val;
        count++;
    }
}

int dequeue() {
    if (count > 0) {
        int val = queue[front];
        front = (front + 1) % MAX;
        count--;
        return val;
    }
    return -1;
}

// Simple Stack Structure
int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, value;
    if (scanf("%d", &n) != 1) return 0;

    // 1. Input: Enqueue elements into the queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // 2. Step 1: Queue -> Stack
    while (count > 0) {
        push(dequeue());
    }

    // 3. Step 2: Stack -> Queue
    while (top != -1) {
        enqueue(pop());
    }

    // 4. Output: Print the reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}