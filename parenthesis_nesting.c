/*Write a program to check nesting of parentheses using a stack*/

#include <stdio.h>

int areParenthesesBalanced(char exp[]) {
    int balance = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            balance++;
        } else if (exp[i] == ')') {
            balance--;
        }

        // If balance goes negative, unbalanced parentheses
        if (balance < 0) {
            return 0;
        }
    }

    // If balance is zero, parentheses are balanced
    return balance == 0;
}

int main() {
    char expression[100];

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
