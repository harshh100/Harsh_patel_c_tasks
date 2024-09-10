/*
*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged.

*Author : Harsh Patel (164975)

*Created : 6/8/24

*Modified : 7/8/24

*/
 
/** required header files */
#include <stdio.h>
#define INPUT_SIZE 50

int setbits(int iX,int iP,int iN,int iY);	

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	int iX;	    /* value of x */
	int iY;	    /* value of y */
	int iP;	    /* value of position */
	int iN;	    /* value of xnumber of bits */
	
	/* Input */
	printf("Enter X : ");
	if (scanf("%d",&iX)!= 1) {
            printf("Invalid input. Please enter an integer value.\n");
            fflush(stdin);
            continue;
     }
	
	printf("Enter Y : ");
	if (scanf("%d",&iY)!= 1) {
            printf("Invalid input. Please enter an integer value.\n");
            fflush(stdin);
            continue;
     }	
	
	printf("Enter P : ");
	if (scanf("%d",&iP)!= 1) {
            printf("Invalid input. Please enter an integer value.\n");
            fflush(stdin);
            continue;
     }
	
	printf("Enter N : ");
	if (scanf("%d",&iN)!= 1) {
            printf("Invalid input. Please enter an integer value.\n");
            fflush(stdin);
            continue;
     }
	
	if(iX<0 || iY<0){
		printf("Enter positive value \n");
	}else if(iP-iN<0){
		printf("Insufficient bits. N should be >= P + 1 \n");
	}else{
	
	/* printf("X : ");
	printBinary(iX);
	printf("\n");
	printf("Y : ");
	printBinary(iY);
	printf("\n"); */
		
	/* function call */
	printf("New X : %d",setbits(iX,iP,iN,iY));	
	}
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int setbits(int iX,int iP,int iN,int iY){	/* function deffination */

	int iMask = (1 << iN) - 1;         /* mask for iN bit extracting from iY */
	/* printf("iMask { (1 << iN) - 1 } : ");
	printBinary(iMask);
	printf("\n"); */
	
	int iNbitofy = iY & iMask;		/* Extracted iN bit from iY */
	/* printf("iNbitofy { iY & iMask } : ");
	printBinary(iNbitofy);
	printf("\n"); */
	
	iNbitofy = iNbitofy << (iP-1);	/* add extra padding to match with iY's position iP*/
	/* printf("iNbitofy { iNbitofy << (iP-1) } : ");
	printBinary(iNbitofy);
	printf("\n"); */
	
	int iMaskOfX = ~(iMask<<(iP-1));	/* Mask for set off iN bits from iX which start from iP postion */
	/* printf("iMaskOfX { ~(iMask<<(iP-1)) } : ");
	printBinary(iMaskOfX);
	printf("\n"); */
		
	iX = iX & iMaskOfX;				/* set off iN bits using mask */
	
	/* printf("iX { iX & iMaskOfX } : ");
	printBinary(iX);
	printf("\n"); */
	
	iX = iX | iNbitofy;				/* add iN bits of iY in iX */
	/* printf("iX { iX | iNbitofy } : ");
	printBinary(iX);
	printf("\n"); */
	printf("--------------\n");
	
	
	return iX;

}






/*
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
}*/


