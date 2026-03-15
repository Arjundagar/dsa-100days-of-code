#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {

    char postfix[] = "231*+9-";   // Hardcoded postfix expression
    int a, b, result;

    for(int i = 0; postfix[i] != '\0'; i++) {

        if(isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        else {
            b = pop();
            a = pop();

            switch(postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
    }

    printf("%d", pop());

    return 0;
}