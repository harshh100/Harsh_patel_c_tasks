/*
*Write a program to copy its input to its output, replacing each tab by \t, each 
*backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an 
*unambiguous way. 

*Author : Harsh Patel (164975)

*Created:22/7/24

*/
 
/* required header files */
#include <stdio.h>
#define INPUT_SIZE 50

/* main function */
int main()
{
  int iRunAgain=0;      		    /* for code run again or not */
  char cInput[INPUT_SIZE]; 	    /* input array */
  
  do{
  		
  	  printf("Enter String : ");
  	  fgets(cInput,INPUT_SIZE,stdin);

	  for(int iCounter=0;cInput[iCounter] != '\0';iCounter++){
	    
	    if (cInput[iCounter] == '\t')
	    {
		 putchar('\\');    /* print '\' */
		 putchar('t');     /* print 't' */
	    }
	    else if (cInput[iCounter] == '\b')
	    {
		 putchar('\\');    /* print '\' */
		 putchar('b');     /* print 'b' */
	    }
	    else if (cInput[iCounter] == '\\')
	    {
		 putchar('\\');    /* print '\' */
		 putchar('\\');    /* print '\' */
	    }else if(cInput[iCounter]=='\n'){
	    	 cInput[iCounter];
	    }
	    else
	    {
		 putchar(cInput[iCounter]);  /* print input */
	    }
	  }
	  
	  printf("\n");
  
	  printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	  scanf("%d",&iRunAgain);
  
  }while(iRunAgain);
  
  return 0;
}
