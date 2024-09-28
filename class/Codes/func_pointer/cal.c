#include <stdio.h>


int add(int a, int b);
int subtract(int a, int b);


int calculate(int a, int b, int (*op)(int, int)) {
    return op(a, b); 
}

int main() {
    int num1, num2;
    char operator;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter an operator (+, -): ");
    scanf(" %c", &operator);


    int (*operation)(int, int) = NULL; 


    switch (operator) {
        case '+':
            operation = add; 
            break;
        case '-':
            operation = subtract;  
            break;
        default:
            printf("Error: Unknown operator.\n");
            return 1; 
    }


    if (operation != NULL) {
        int result = calculate(num1, num2, operation);
        printf("Result: %d\n", result);
    } else {
        printf("No valid operation selected.\n");
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

