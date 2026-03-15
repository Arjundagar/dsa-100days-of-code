#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main() {

    char infix[100];
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {

        char c = infix[i];

        // operand
        if(isalnum(c)) {
            printf("%c", c);
        }

        // left parenthesis
        else if(c == '(') {
            push(c);
        }

        // right parenthesis
        else if(c == ')') {
            while(stack[top] != '(')
                printf("%c", pop());
            pop(); // remove '('
        }

        // operator
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());

            push(c);
        }
    }

    // pop remaining operators
    while(top != -1)
        printf("%c", pop());

    return 0;
}