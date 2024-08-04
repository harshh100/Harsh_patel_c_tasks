/*
*Write a loop equivalent to the for loop above without using && or ||. 

*Author : Harsh Patel (164975)

*Created : 2/8/24

*Modified : 2/8/24

*/
 
/** required header files */
#include <stdio.h>
#define INPUT_SIZE 50

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	
	  char cInputStr[INPUT_SIZE];	    /* input array */
	
	  printf("Enter Input : ");
       int iCounter = 0;
	  int iloop = 1;
	  while (iloop)
	  {
	    char cInput = getchar();

	    if (iCounter >= (INPUT_SIZE - 1))  /* check for maximum size */
	    {
		 iloop = 0;
	    }
	    else if (cInput == '\n')		   /* check for end line size */
	    {
		 iloop = 0;
	    }
	    else if (cInput == EOF)		   /* check for EOF */
	    {
		 iloop = 0;
	    }

	    cInputStr[iCounter++] = cInput;
	  }

	  cInputStr[iCounter] = '\0';		  /* for end the string */ 

	  printf("%s", cInputStr);

	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}
