#include<stdio.h>
#include "sum.h"

int main(){
	
	int iNum1,iNum2;
	
	printf("Enter Num 1 : ");
	scanf("%d",&iNum1);
	
	printf("Enter Num 2 : ");
	scanf("%d",&iNum2);
	
	int iAns = sum(iNum1,iNum2);
	printf("Sum : %d",iAns);
}
