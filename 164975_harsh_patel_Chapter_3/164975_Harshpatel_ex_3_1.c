/*
*Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time. 

*Author : Harsh Patel (164975)

*Created : 20/8/24

*Modified : 20/8/24

*/
 
/** required header files */
#include <stdio.h>
#define MAX_SIZE 100

int binsearch(int iX, int iInput[], int iN);

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  
 do{
	int iInput[] = {1,2,3,4,6,8,10,11,13,15,16,18,20};	    /* value of x input*/
	
	printf("Array : [");
	for(int iCounter=0;iCounter<(sizeof(iInput)/sizeof(iInput[0])) - 1;iCounter++){
		printf("%d,",iInput[iCounter]);
	}
	printf("%d]\n",iInput[(sizeof(iInput)/sizeof(iInput[0])) - 1]);
	
	int iFindNum;
	printf("Enter Num : ");
	scanf("%d",&iFindNum);
	
	(binsearch(iFindNum, iInput, sizeof(iInput)/sizeof(iInput[0]))!=-1) ? printf("%d is Present in Array",iFindNum) : printf("%d is Not Present Array",iFindNum);
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int binsearch(int iX, int iInput[], int iN) {
    int iLow, iHigh, iMid;

    iLow = 0;
    iHigh = iN - 1;

    iMid = (iLow + iHigh) / 2;

    while (iLow < iHigh && iX != iInput[iMid]) {
        if (iX > iInput[iMid])
            iLow = iMid + 1;
        else
            iHigh = iMid - 1;

        iMid = (iLow + iHigh) / 2;
    }

    if (iX == iInput[iMid])
        return iMid;
    else
        return -1;
}



