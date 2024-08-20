/*
*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount.

*Author : Harsh Patel (164975)

*Created : 7/8/24

*Modified : 7/8/24

*/
 
/** required header files */
#include <stdio.h>

char lower(char c);
/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	char iInput;	    /* value of x input*/
	
	printf("Enter Input : ");
	scanf("%c",&iInput);

  	putchar(lower(iInput));
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


char lower(char iInput)
{
  return (iInput >= 'A' && iInput <= 'Z') ? iInput += 'a' - 'A' : iInput;
}



