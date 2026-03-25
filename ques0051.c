#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both smaller → go left
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // If both greater → go right
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Otherwise → this is LCA
    return root;
}

int main() {
    int n, value, p, q;
    struct Node* root = NULL;

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    scanf("%d %d", &p, &q);

    // Find LCA
    struct Node* lca = findLCA(root, p, q);

    // Output
    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}