#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


typedef int (*Operation)(int, int);


int calculate(int a, int b, Operation op) {
    return op(a, b);  
}

int main() {
    int num1, num2;
    char operator;


    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);


    Operation op = NULL;

    switch (operator) {
        case '+':
            op = add;
            break;
        case '-':
            op = subtract;
            break;
        case '*':
            op = multiply;
            break;
        case '/':
            if (num2 != 0) {
                op = divide;
            } else {
                printf("Error: Division by zero.\n");
                return 1;
            }
            break;
        default:
            printf("Error: Unknown operator.\n");
            return 1;
    }

    int result = calculate(num1, num2, op);
    printf("Result: %d\n", result);

    return 0;
}


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

