#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete first occurrence of key
struct Node* deleteFirst(struct Node* head, int key) {
    
    // If list is empty
    if (head == NULL)
        return head;

    // If head contains key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = head;
    struct Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            break;   // delete only first occurrence
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main() {
    int n, key, i;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteFirst(head, key);

    // Print list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}