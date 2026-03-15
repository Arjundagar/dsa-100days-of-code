#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    struct Node *ptr1 = head1, *ptr2 = head2;
    int diff = abs(len1 - len2);
    if (len1 > len2)
        for (int i = 0; i < diff; i++)ptr1 = ptr1->next;
    else
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    insertEnd(&head1, 10);
    insertEnd(&head1, 20);insertEnd(&head1, 30);insertEnd(&head1, 40);insertEnd(&head1, 50);

    // Second list
    insertEnd(&head2, 15);
    insertEnd(&head2, 25);
    
    struct Node* temp = head1;
    while (temp->data != 30)
        temp = temp->next;
    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp;   // intersection created
    
    int result = findIntersection(head1, head2);
    if (result == -1)
        printf("No Intersection\n");
    else
        printf("Intersection at node: %d\n", result);

    return 0;
}