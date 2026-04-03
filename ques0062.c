#include <stdio.h>
#include <stdlib.h>

// Node of linked list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int directed) {
    // Add edge u → v
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // If undirected, add v → u
    if (!directed) {
        newNode = createNode(u);
        newNode->next = graph->adjList[v];
        graph->adjList[v] = newNode;
    }
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d -> ", i);
        struct Node* temp = graph->adjList[i];

        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    int directed;
    printf("Enter 1 for directed, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(graph, u, v, directed);
    }

    printf("\nAdjacency List:\n");
    printGraph(graph);

    return 0;
}