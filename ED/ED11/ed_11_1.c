
#include <stdio.h>
#include <stdbool.h>

/* Define the maximim capacity of the stack */
#define MAX_SIZE 100

/* Define stack */
typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;


/* 
newstack : initialize stack
Author : Harsh Patel
Created : 25/9/2024	
*/
void newstack(Stack *stack) {
    stack->top == -1;  
}



/* 
isEmpty : check if the stack is empty 
Author : Harsh Patel
Created : 25/9/2024	
*/
bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

/* 
isFull : check if the stack is full
Author : Harsh Patel
Created : 25/9/2024	
*/
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;  
}


/* 
push : push an element onto the stack
Author : Harsh Patel
Created : 25/9/2024	
*/
void push(Stack *stack, int value) {

    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}


/* 
pop : pop an element from the stack
Author : Harsh Patel
Created : 25/9/2024	
*/
int pop(Stack *stack) {

    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}


/* 
pop : top element of the stack
Author : Harsh Patel
Created : 25/9/2024	
*/
int top(Stack *stack) {

    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}

int main() {
    Stack stack;  
    newstack(&stack);

    push(&stack, 3);
    printf("Top element: %d\n", top(&stack));

    push(&stack, 5);
    printf("Top element: %d\n", top(&stack));

    push(&stack, 2);
    printf("Top element: %d\n", top(&stack));

    push(&stack, 8);
    printf("Top element: %d\n", top(&stack));

    // Pop elements from the stack and print the stack after each pop
    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", top(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}

