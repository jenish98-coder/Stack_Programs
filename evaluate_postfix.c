/*Write a program to evaluate a postfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int isOperand(char ch) {
    return isalnum(ch);
}

int calculate(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        case '^':
            return operand1 ^ operand2; // XOR operation as a placeholder for exponentiation
        default:
            printf("Error: Unknown operator\n");
            exit(EXIT_FAILURE);
    }
}

int evaluatePostfix(char postfix[]) {
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        if (isOperand(current)) {
            stack[++top] = current - '0';
        } else {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = calculate(operand1, operand2, current);
            stack[++top] = result;
        }
    }

    if (top != 0) {
        printf("Error: Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return stack[top];
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    if (postfix[strlen(postfix) - 1] == '\n') {
        postfix[strlen(postfix) - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}


/*suggested inputs

Enter the postfix expression:  934*8+4/-
934*8+4/-
Result of the postfix expression: 4
*/
