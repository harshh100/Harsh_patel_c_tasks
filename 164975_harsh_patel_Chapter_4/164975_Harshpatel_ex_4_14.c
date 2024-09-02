/*
* Define a macro swap(t,x,y) that interchanges two arguments of type t. 

*Author : Harsh Patel (164975)

*Created:29/8/24

*Modified : 29/8/24

*/
 
/** required header files */
#include <stdio.h>
#define swap(t,x,y) t=x;x=y;y=t	/* macro defination for swap */
/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  
 do{
	
	int iVar1,iVar2,iTemp;
	
	printf("Enter Var_1 : ");
	scanf("%d",&iVar1);
	
	printf("Enter Var_2 : ");
	scanf("%d",&iVar2);
	
	printf("Before Swap -> Var_1 : %d, Var_2 : %d",iVar1,iVar2);
	
	swap(iTemp,iVar1,iVar2);
	
	printf("\nAfter Swap  -> Var_1 : %d, Var_2 : %d",iVar1,iVar2);
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}
