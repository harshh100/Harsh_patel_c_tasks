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
	scanf("%d",&iX);
	
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
	while (iX) {
        iCounter += iX & 1;
        iX >>= 1;
    }
	return iCounter; 
}



