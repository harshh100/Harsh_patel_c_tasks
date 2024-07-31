/*
*Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 

*Author : Harsh Patel (164975)

*Created : 31/7/24

*Modified : 31/7/24

*/
 
/** required header files */
#include <stdio.h>
#define MAX_LEN 10   /* Define the number of spaces per tab stop */
#define INPUT_SIZE 1000 /* max size of input */

/** main function */
int main() {
    
  int iRunAgain=0;      		    /* for code run again or not */
  
  do{
  	
     char cInput[INPUT_SIZE]; 	    /* input array */
     int iBreakCounter =0;		    /* checking for sub-line length */
     printf("Enter String : ");
  	fgets(cInput,INPUT_SIZE,stdin);
  	  
	for(int iCounter=0;cInput[iCounter]!='\n'  && cInput[iCounter]!='\0' ;iCounter++){
		
		if(iBreakCounter==MAX_LEN){	/* sub-line length is equal to MAX_LEN then */
			
			while(cInput[iCounter]!=' ' && cInput[iCounter]!='\t' && cInput[iCounter]!='\n' && cInput[iCounter]!='\0'){		
				putchar(cInput[iCounter]);		/* print remain character for avoid word-breaking */
				iCounter++;
			}
			
			
			putchar('\n');						/* and new line */
			iBreakCounter=1;					/* reset iBreakCounter fro new sub-line */
			
		}else{
			putchar(cInput[iCounter]);			/* print character */
			iBreakCounter++;
		}
		
	
	
	}
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);
	
    return 0;
}
