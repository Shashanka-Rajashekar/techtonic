#include <stdio.h>

int main() {
    char operator;
    int num1, num2, result;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (operator == '+') {
        result = num1 + num2;
    } else if (operator == '-') {
        result = num1 - num2;
    } else if (operator == '*') {
        result = num1 * num2;
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("Error: division by zero\n");
            return 1;
        }
        result = num1 / num2;
    } else {
        printf("Error: invalid operator\n");
        return 1;
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);
    return 0;
}
