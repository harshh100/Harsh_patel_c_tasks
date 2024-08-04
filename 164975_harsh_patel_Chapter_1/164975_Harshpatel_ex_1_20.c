/*
*Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter?

*Author : Harsh Patel (164975)

*Created : 31/7/24

*Modified : 31/7/24

*/
 
/** required header files */
#include <stdio.h>
#define TAB_WIDTH 8   /* Define the number of spaces per tab stop */
#define INPUT_SIZE 100 /* max size of input */

/** main function */
int main() {
    
  int iSpaces = TAB_WIDTH;		/* tab width */
  int iRunAgain=0;      		    /* for code run again or not */
  
  do{
  		
     char cInput[INPUT_SIZE]; 	    /* input array */
     printf("Enter String : \n");
  	fgets(cInput,INPUT_SIZE,stdin);
  	  
	
	for(int iCounter=0;cInput[iCounter]!='\n';iCounter++){
	
	   if (cInput[iCounter] == '\t') {		/* replace tab with space */
            
            while (iSpaces > 0) {
                putchar(' ');
                iSpaces--;
            }
            iSpaces=TAB_WIDTH;			/* initially assign tab width to space */
        }else if(cInput[iCounter] == ' '){	/* skip multiple spaces */
        	  putchar(cInput[iCounter]);
        	  
        	  while(cInput[iCounter]==' ')
        	  	iCounter++;
        	  	
        	  iCounter--;
        }else {
            putchar(cInput[iCounter]);		/* print character */
            if(iSpaces>=0){
            	iSpaces--;				/* decrement space for mainten tab width */
            }else{
            	iSpaces=TAB_WIDTH;			/* reset space if word bigger than tab width */
            }
            
        }
	
	}
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);
	
    return 0;
}
