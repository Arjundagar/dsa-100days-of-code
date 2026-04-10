#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5   // number of vertices

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap structure
struct MinHeap {
    int size;
    int vertex[V];
    int dist[V];
};

// Extract min
int extractMin(struct MinHeap* heap) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < heap->size; i++) {
        if (heap->dist[i] < min) {
            min = heap->dist[i];
            index = i;
        }
    }
    int v = heap->vertex[index];

    // remove element
    for (int i = index; i < heap->size - 1; i++) {
        heap->vertex[i] = heap->vertex[i + 1];
        heap->dist[i] = heap->dist[i + 1];
    }
    heap->size--;
    return v;
}

// Dijkstra function
void dijkstra(struct Node* adj[], int src) {
    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap heap;
    heap.size = V;

    for (int i = 0; i < V; i++) {
        heap.vertex[i] = i;
        heap.dist[i] = dist[i];
    }

    while (heap.size > 0) {
        int u = extractMin(&heap);
        visited[u] = 1;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                // update heap
                for (int i = 0; i < heap.size; i++) {
                    if (heap.vertex[i] == v) {
                        heap.dist[i] = dist[v];
                    }
                }
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    struct Node* adj[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Example graph
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);
    addEdge(adj, 3, 2, 6);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 4, 3, 2);

    int source = 0;
    dijkstra(adj, source);

    return 0;
}