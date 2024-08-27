/**
* Adding the Modulus operator and provision for negative numbers Program is given the input in a single and and it print the output upon getting a \n character. For e.g: 10 10 + 100 + 2 * 240
 
*Author : Harsh Patel (164975)

*Created : 23/8/24

*Modified : 23/8/24
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);

void ungetch(int);

int getop(char[]);

void push(double);

double pop(void);

void clearsp(void);

void printStack(void);

/* reverse polish calculator */

int main(void) {
    int type;
    char s[MAXOP];
	double op2,op1;
	printf("Enter operands and a operator (in postfix manner): ");
    while ((type = getop(s)) != EOF) {

        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);

                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop() / op2);

                }else
                    printf("error:zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0)
                {
                	if((op1 < 0 && op2 > 0) || (op1 > 0 && op2 < 0))
                	{
                		push(fmod(op1, op2) + op2);
                	}
                	else
                    		push(fmod(op1, op2));
             	
                }
                else
                    printf("erro:zero divisor\n");
                break;
            case 'c':	/* clears the characters in the stack. */
                clearsp();
                break;
            case 'd':	/* doubles the characters */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':	/* swaps the characters. */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'p':
                printStack();
                break;
            case 't': 	/* top element of stack */
            	 if (sp)
  			 {
    				printf("stack_head: %d\n", s[sp]);
  			 }
  			 else
  			 {
  				  printf("Error: stack empty.\n");
  			 }
            case '\n':
            	 double ians = pop();
            	 if(ians !=0.0 && sp>0){
	            	 push(ians);
            	 }
                printf("stack top : %.8g\n", ians);
                printf("Enter operands and a operator (in postfix manner): ");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clearsp(void) { sp = 0; }

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

/*
* printStack : printing the stack elements
* Author : Harsh Patel (164975)
* Created : 27/8/24
*/

void printStack(void) {
    if (sp == 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i < sp; i++) {
            printf("%g ", val[i]);
        }
        printf("\n");
    }
}


void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
