#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int n; // number of vertices

// Push into stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // push after visiting all neighbors
    push(v);
}

// Topological Sort function
void topologicalSort() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    topologicalSort();

    return 0;
}