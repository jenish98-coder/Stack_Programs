/*Write a program to evaluate a prefix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure and operations
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1;
}

// Function to evaluate the prefix expression
int EvaluatePrefix(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    int i, result, operand1, operand2;
    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0');
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch (exp[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand2 - operand1; // Corrected order
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand2 / operand1; // Corrected order
                    break;
            }
            push(stack, result);
        }
    }
    return pop(stack);
}

int main() {
    char exp[100];  // Assuming a maximum expression length of 100 characters

    printf("Enter the prefix expression: ");
    fgets(exp, sizeof(exp), stdin);

    if (exp[strlen(exp) - 1] == '\n') {
        exp[strlen(exp) - 1] = '\0'; // Remove the newline character
    }

    printf("The result of the expression %s = %d\n", exp, EvaluatePrefix(exp));
    return 0;
}
