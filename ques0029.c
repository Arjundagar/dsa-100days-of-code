#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the list
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || n == 0) return head;

    // Effectively handle k > n
    k = k % n;
    if (k == 0) return head;

    // 1. Find the current tail and connect it to head
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head; // Link last node to first node

    // 2. Find the new tail: (n - k)th node
    struct Node* newTail = head;
    for (int i = 1; i < (n - k); i++) {
        newTail = newTail->next;
    }

    // 3. Set new head and break the circular connection
    struct Node* newHead = newTail->next;
    newTail->next = NULL; // Break the link

    return newHead;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *temp = NULL;

    // Dynamic memory allocation for the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);
    printList(head);

    return 0;
}