#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;
    int count = 0;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse and count nodes
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    printf("\nTotal number of nodes = %d", count);

    return 0;
}