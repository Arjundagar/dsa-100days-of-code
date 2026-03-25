#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for BFS
struct QNode {
    struct Node* node;
    int hd;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Array of lists (assuming HD range [-100,100])
    int offset = 100;
    int result[200][100];   // store nodes
    int size[200] = {0};    // size of each column

    // Queue for BFS
    struct QNode queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = (struct QNode){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        result[index][size[index]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + offset;
        for (int j = 0; j < size[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    free(arr);
    return 0;
}