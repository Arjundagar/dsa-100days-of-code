#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

// Function for Kahn's Algorithm
void topologicalSort() {
    int front = 0, rear = -1;
    int count = 0;

    // Step 1: Calculate in-degree
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with in-degree 0 to queue
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Order:\n");

    // Step 3: Process queue
    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        // Reduce in-degree of adjacent vertices
        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        } 
    }

    // Step 4: Check for cycle
    if(count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}