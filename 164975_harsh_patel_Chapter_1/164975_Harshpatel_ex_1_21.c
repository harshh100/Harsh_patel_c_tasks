/*
*Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? 

*Author : Harsh Patel (164975)

*Created : 31/7/24

*Modified : 31/7/24

*/
 
/** required header files */
#include <stdio.h>
#define TAB_WIDTH 4   /* Define the number of spaces per tab stop */
#define INPUT_SIZE 100 /* max size of input */

/** main function */
int main() {
    
  int iRunAgain=0;      		    /* for code run again or not */
  
  do{
  		
     int iSpaces = 0;		/* space counter */
     char cInput[INPUT_SIZE]; 	    /* input array */
     printf("Enter String : ");
  	fgets(cInput,INPUT_SIZE,stdin);
  	  
	
	for(int iCounter=0;cInput[iCounter]!='\n';iCounter++){
	
	   if (cInput[iCounter] == ' ') {		/* replace tab with space */
            
            while (cInput[iCounter] == ' ') {  /* count consecutive space */
       	       iSpaces++;
       	       iCounter++;
       	       if(iSpaces==TAB_WIDTH){	/* print '\t' if space is equal to tab_wigth */
       	       	putchar('\\');
       	       	putchar('t');
       	       	iSpaces=0;			/* reset space counter */
       	       }
            }
            iCounter--;
            
            while(iSpaces>0){    /* print remain space which not multiple of tab_wigth */
            	  putchar(' ');
            	  iSpaces--;
            }
            
        }else {
            putchar(cInput[iCounter]);		/* print character */
            
        }
	
	}
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);
	
    return 0;
}
