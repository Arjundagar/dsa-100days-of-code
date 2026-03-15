#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;
int count = 0;

bool isFull() {
    return count == MAX;
}

bool isEmpty() {
    return count == 0;
}

void push_back(int val) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    deque[rear] = val;
    count++;
}

void push_front(int val) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = val;
    count++;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Popped from front: %d\n", deque[front]);
    front = (front + 1) % MAX;
    count--;
    if (count == 0) { front = -1; rear = -1; }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Popped from rear: %d\n", deque[rear]);
    rear = (rear - 1 + MAX) % MAX;
    count--;
    if (count == 0) { front = -1; rear = -1; }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", deque[(front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    display();      // Output: 5 10 20
    pop_back();     // Output: Popped from rear: 20
    display();      // Output: 5 10
    return 0;
}