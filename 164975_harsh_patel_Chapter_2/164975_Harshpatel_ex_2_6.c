/*
*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged.

*Author : Harsh Patel (164975)

*Created : 6/8/24

*Modified : 6/8/24

*/
 
/** required header files */
#include <stdio.h>
#define INPUT_SIZE 50

int setbits(int iX,int iP,int iN,int iY);

void printBinary(int n) {
   unsigned int mask = 1 << (sizeof(int) * 8 - 1); // Create a mask with the highest bit set
    int started = 0; // Flag to skip leading zeros

    if (n < 0) {
        printf("-");
        n = ~n + 1; // Convert negative number to positive using two's complement
    }

    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (n & mask) {
            started = 1;
            printf("1");
        } else if (started) {
            printf("0");
        }
        mask >>= 1;
    }

    if (!started) {
        printf("0"); // If the number is zero
    }

    printf("\n");
}

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	int iX;	    /* value of x */
	int iY;	    /* value of x */
	int iP;	    /* value of x */
	int iN;	    /* value of x */
	
	printf("Enter X : ");
	scanf("%d",&iX);
	
	printf("Enter Y : ");
	scanf("%d",&iY);	
	
	printf("Enter P : ");
	scanf("%d",&iP);	
	
	printf("Enter N : ");
	scanf("%d",&iN);
	
	
	printf("X : ");
	printBinary(iX);
	printf("\n");
	printf("Y : ");
	printBinary(iY);
	printf("\n");
	printf("P : ");
	printBinary(iP);
	printf("\n");
	printf("N : ");
	printBinary(iN);
	printf("\n");
		
	
	printf("New X : %d",setbits(iX,iP,iN,iY));	
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int setbits(int iX,int iP,int iN,int iY){

	int iMask = (1 << iN) - 1;
	printf("iMask { (1 << iN) - 1 } : ");
	printBinary(iMask);
	printf("\n");
	
	int iNbitofy = iY & iMask;
	printf("iNbitofy { iY & iMask } : ");
	printBinary(iNbitofy);
	printf("\n");
	
	iNbitofy = iNbitofy << (iP-1);
	printf("iNbitofy { iNbitofy << (iP-1) } : ");
	printBinary(iNbitofy);
	printf("\n");
	
	int iMaskOfX = ~(iMask<<(iP-1));
	printf("iMaskOfX { ~(iMask<<(iP-1)) } : ");
	printBinary(iMaskOfX);
	printf("\n");
		
	iX = iX & iMaskOfX;
	
	printf("iX { iX & iMaskOfX } : ");
	printBinary(iX);
	printf("\n");
	
	iX = iX | iNbitofy;
	printf("iX { iX | iNbitofy } : ");
	printBinary(iX);
	printf("\n");
	printf("--------------\n");
	
	
	return iX;

}



