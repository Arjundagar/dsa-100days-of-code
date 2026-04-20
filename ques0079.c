#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure for Adjacency List Node
struct Node {
    int dest, weight;
    struct Node* next;
};

// Structure for Min-Heap Node
struct HeapNode {
    int v, dist;
};

// Structure for Min-Heap
struct MinHeap {
    int size, capacity;
    int *pos; // To track position of vertices in heap
    struct HeapNode **array;
};

// --- Utility Functions for Graph ---
struct Node* newAdjNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// --- Min-Heap Logic ---
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        minHeap->pos[minHeap->array[smallest]->v] = idx;
        minHeap->pos[minHeap->array[idx]->v] = smallest;
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    struct HeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// --- Main Dijkstra Function ---
void dijkstra(int n, struct Node* adj[], int src) {
    int dist[n + 1];
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc((n + 1) * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = n;
    minHeap->array = (struct HeapNode**)malloc(n * sizeof(struct HeapNode*));

    for (int v = 1; v <= n; ++v) {
        dist[v] = INF;
        minHeap->array[v - 1] = newHeapNode(v, dist[v]);
        minHeap->pos[v] = v - 1;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = n;

    while (minHeap->size != 0) {
        struct HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            if (minHeap->pos[v] < minHeap->size && dist[u] != INF && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Node* newNode = newAdjNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int source;
    scanf("%d", &source);
    dijkstra(n, adj, source);

    return 0;
}