/*
*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount.

*Author : Harsh Patel (164975)

*Created : 7/8/24

*Modified : 7/8/24

*/
 
/** required header files */
#include <stdio.h>
#define INT_BITS 32

int bitcount(unsigned iX);
/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	unsigned int iX;	    /* value of x input*/
	
	printf("Enter Input : ");
	if (scanf("%d",&iX)!= 1) {
            printf("Invalid input. Please enter an integer value.\n");
            fflush(stdin);
            continue;
     }
	
	/* input validation */
	if(iX<0){
		printf("Enter positive value \n");
	}else{
		
		printf("Number Of 1's : %d",bitcount(iX));	
	}
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int bitcount(unsigned int iX) 
{ 
	int iCounter=0; 
	for(iCounter=0; iX!=0; iX &= iX-1)
    		++iCounter;
	return iCounter; 
}



