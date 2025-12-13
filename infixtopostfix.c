#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}


char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int pr(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else {
            while (pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix Expression = %s\n", postfix);
    return 0;
}
