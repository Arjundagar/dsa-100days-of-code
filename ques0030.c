#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, c, e;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print polynomial
    temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}