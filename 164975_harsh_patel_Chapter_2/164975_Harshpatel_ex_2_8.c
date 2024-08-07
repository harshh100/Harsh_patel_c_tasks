/*
*Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions.

*Author : Harsh Patel (164975)

*Created : 7/8/24

*Modified : 7/8/24

*/
 
/** required header files */
#include <stdio.h>
#define INT_BITS 32

int rightrot(int iX,int iN);

/*void printBinary(int n) {
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

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	int iX;	    /* value of x input*/
	int iN;	    /* value of number of bits */
	
	printf("Enter X : ");
	scanf("%d",&iX);
	
	printf("Enter N : ");
	scanf("%d",&iN);
	
	/* input validation */
	if(iX<0){
		printf("Enter positive value \n");
	}else{
		/*printf("X : ");
		printBinary(iX);
		printf("\n");
		printf("N : ");
		printBinary(iN);
		printf("\n"); */
		printf("New X : %d",rightrot(iX,iN));	
	}
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int rightrot(int iX,int iN){

	printf("--------------\n");
	
	/*printf("iX >> iN : ");
	printBinary(iX >> iN);
	printf("\n");
	
	printf("iX << (INT_BITS - iN) : ");
	printBinary(iX << (INT_BITS - iN));
	printf("\n");     */
	
	return iX >> iN | iX << (INT_BITS - iN);

}



