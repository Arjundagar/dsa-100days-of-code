#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* temp = head;
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Merge two sorted lists
struct Node* merge(struct Node* h1, struct Node* h2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    // First node
    if (h1->data <= h2->data) {
        result = h1;
        h1 = h1->next;
    } else {
        result =  h2;
        h2 = h2->next;
    }

    tail = result;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }

    if (h1 != NULL)
        tail->next = h1;
    else
        tail->next = h2;

    return result;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* merged;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    merged = merge(head1, head2);
    printList(merged);

    return 0;
}