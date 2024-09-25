/*
*Write getfloat, the floating-point analog of getint. What type does 
getfloat return as its function value? 

*Author : Harsh Patel (164975)

*Created:16/9/24

*Modified : 16/9/24

*/

/*Required headers*/
#include<stdio.h>
#include<ctype.h>

/*declaring buffer size and buffer*/
#define SIZE 100
#define BUFSIZE 10

char cBuf[BUFSIZE];
int iBufp = 0;


/*
* getch : take input from buffer or user
* Author : Harsh Patel (164975)
* Created : 16/9/24
*/

int getch(void) {
    return (iBufp > 0) ? cBuf[--iBufp] : getchar();
}


/*
* ungetch : add inputs in buffer 
* Author : Harsh Patel (164975)
* Created : 16/9/24
*/

void ungetch(int c) {
    if (iBufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        cBuf[iBufp++] = c;
}


int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()));	/* skip white space */
	
    if(c == EOF){
    		return EOF;
    }
	
    if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c); /* it's not a number */
        printf("Invalid Entry!!!\n");
        cBuf[0]='\0';
        iBufp = 0;
        return 0; /* -1 will end the program directly */
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();
        
    /*avoids to treat a '+' or '-' not followed by a digit as a valid representation of zero */
    if (!isdigit(c)){
    	   printf("Invalid Entry!!!\n");
    	   cBuf[0]='\0';
    	   iBufp = 0;
        return 0;
    }
        
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.')
        c = getch();
    
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');    /* fractional part */
        power *= 10.0;
    }
    
    *pn *= sign / power;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void) {
    int iInputCounter;
    float iOutput[SIZE];
    
    	   printf("Enter string : ");
    for (iInputCounter = 0; iInputCounter < SIZE && getfloat(&iOutput[iInputCounter]) != EOF;iInputCounter++) {
        printf("Enter string : ");
    } 
 
    printf("\nOutput array : ");
    for (int s = 0; s < iInputCounter; s++)
        printf("%f  ", iOutput[s]);
					
    return 0;
}
