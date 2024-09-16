/*
*Modify getop so that it doesn't need to use ungetch

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
* Created : 27/8/24
*/

int getch(void) {
    return (iBufp > 0) ? cBuf[--iBufp] : getchar();
}


/*
* ungetch : add inputs in buffer 
* Author : Harsh Patel (164975)
* Created : 27/8/24
*/

void ungetch(int c) {
    if (iBufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        cBuf[iBufp++] = c;
}


int getint(int *pn) {
    int c, sign;

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
        
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void) {
    int iInputCounter, iOutput[SIZE], getint(int *);
    
    	   printf("Enter string : ");
    for (iInputCounter = 0; iInputCounter < SIZE && getint(&iOutput[iInputCounter]) != EOF;iInputCounter++) {
        printf("Enter string : ");
    } 
 
    printf("Output array : ");
    for (int s = 0; s <= iInputCounter; s++)
        printf("%d  ", iOutput[s]);
					
    return 0;
}
