#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the last added element UP to its correct position
void bubbleUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

// Moves the root element DOWN to restore the heap property
void heapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify(smallest);
    }
}

void insert(int x) {
    if (size >= MAX) return;
    heap[size] = x;
    bubbleUp(size);
    size++;
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1]; // Move last element to root
    size--;
    heapify(0);
}

void peek() {
    if (size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}