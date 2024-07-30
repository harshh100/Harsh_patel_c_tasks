/*
*Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.  

*Author : Harsh Patel (164975)

*Created:17/7/24

*Modified : 26/7/24

*/
 
/* required header files */
#include <stdio.h>
#define INPUT_SIZE 50
/* main function */
int main()
{ 

int iRunAgain=0;                  /* for code run again or not */
   do{
   	  
	  int iLastInput = '\0';			 /* last input */
	  char cInput[INPUT_SIZE];          /* input array */
	  int iFirstTime = 1;		      /* for checking single \t or \n or ' ' */
	  
	  
	  printf("Enter String : ");
	  
	  fgets(cInput,INPUT_SIZE,stdin);	 /* input */
	  
	  
  	  int iCounter=0;			 /* counter */
	  while(cInput[iCounter] != '\0'){
	  	
	  	while(cInput[iCounter] != '\n' && cInput[iCounter] != '\t' && cInput[iCounter] != ' '){  /* print latters */	
	  		putchar(cInput[iCounter]);
	  		iFirstTime=1;
	  		iCounter++;
	  	};
	  	
	  	if(iFirstTime){           /* check for word break */
	  		putchar(' ');
	  		iFirstTime=0;
	  		iCounter++;
	  	}else{
	  		iCounter++;		 /* skip the multiple \t or \n or ' ' */
	  	}
	
	  };
	  
	  printf("\n");
	  printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	  scanf("%d",&iRunAgain);
	  getchar();
  	  
  }while(iRunAgain);
  
  return 0;
}
