/*Write a program to convert an infix expression into its equivalent postfix
notation*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix expression
void convertInfixToPostfix(char *infix, char *postfix) {
    int len = strlen(infix);
    char stack[len];
    int top = -1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[j] = c;
            j++;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            if (top != -1)
                top--;
        } else {
            while (top != -1 && prec(c) <= prec(stack[top])) {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character if present
    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    convertInfixToPostfix(infix, postfix);

    printf("The equivalent postfix expression is: %s\n", postfix);

    return 0;
}
