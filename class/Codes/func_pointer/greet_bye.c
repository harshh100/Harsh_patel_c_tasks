#include <stdio.h>

void greet() {
    printf("Hello, world!\n");
}

void bye() {
    printf("Goodbye, world!\n");
}

void executeFunction(void (*func)()) {
    func(); 
}

int main() {

    void (*functionPtr)();

    functionPtr = greet;
    printf("calling greet function:\n");
    functionPtr();
    executeFunction(functionPtr);  


    functionPtr = bye;
    printf("calling bye function:\n");
    functionPtr();
    executeFunction(functionPtr);  
    return 0;
}

