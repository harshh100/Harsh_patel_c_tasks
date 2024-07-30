/*
*Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. 

*Author : Harsh Patel (164975)

*Created:30/7/24

*/
 
/** required header files */
#include <stdio.h>
#define INPUT_SIZE 100
int main()
{
  int iRunAgain=0;      		    /* for code run again or not */
  
  do{
	  char cInput[INPUT_SIZE]; 	    /* input array */
	  int iFront=0;
	  int iRear;
  		
  	  printf("Enter String : ");
  	  fgets(cInput,INPUT_SIZE,stdin);
  	  
  	  int iCounter =0;
  	  while(cInput[iCounter]!='\n') /* get end index of string*/
  	  	iCounter++;
		
	  iRear = --iCounter;	   /* back track from last one */
		
	  while (iRear > iFront)
  	  {
  	  	/* swapping */
          char CTemp = cInput[iFront];  
          cInput[iFront] = cInput[iRear];
          cInput[iRear] = CTemp;
		
		/* decrement the sie of window */
          ++iFront;
          --iRear;
  	  }
  	  
  	  printf("Reverse String : %s",cInput);
	  
	  printf("\n");
	  printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	  scanf("%d",&iRunAgain);
	  getchar();
  
  }while(iRunAgain);
  
  return 0;
}
