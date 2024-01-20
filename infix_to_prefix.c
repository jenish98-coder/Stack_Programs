/*Write a program to convert an infix expression to a prefix expression.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function prototypes
void push(char stack[], int *top, char item);
char pop(char stack[], int *top);
int isOperator(char c);
int getPrecedence(char op);
void reverseString(char *str);
void infixToPrefix(char *infix, char *prefix);

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    // Input infix expression
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character if present
    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    // Convert infix to prefix
    infixToPrefix(infix, prefix);

    // Output the prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

// Function to push an item onto the stack
void push(char stack[], int *top, char item) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++(*top)] = item;
}

// Function to pop an item from the stack
char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[(*top)--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // Default for other characters
}

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char *infix, char *prefix) {
    char operatorStack[MAX_SIZE];
    int top = -1, i, j = 0;

    // Reverse the infix expression
    reverseString(infix);

    // Replace opening parentheses with closing parentheses and vice versa
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Scan the reversed infix expression
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            // Operand
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            // Closing parenthesis
            push(operatorStack, &top, infix[i]);
        } else if (infix[i] == '(') {
            // Opening parenthesis
            while (top != -1 && operatorStack[top] != ')') {
                prefix[j++] = pop(operatorStack, &top);
            }
            pop(operatorStack, &top); // Pop the ')'
        } else if (isOperator(infix[i])) {
            // Operator
            while (top != -1 && getPrecedence(operatorStack[top]) >= getPrecedence(infix[i])) {
                prefix[j++] = pop(operatorStack, &top);
            }
            push(operatorStack, &top, infix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        prefix[j++] = pop(operatorStack, &top);
    }

    // Add null terminator
    prefix[j] = '\0';

    // Reverse the final prefix expression
    reverseString(prefix);
}

/*
sample input:

Enter the infix expression: 2+3*4
Prefix expression: +2*34

*/