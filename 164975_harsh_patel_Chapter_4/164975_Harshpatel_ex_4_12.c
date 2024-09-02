/*
* Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
*Author: Harsh Patel (164975)
*Create: 29/8/2024
*/
 
 
#include <stdio.h> 
#include<math.h>
#include "error_handling.h"
 
#define MAXIMUM 100
static int index = 0;
void itoa(int n, char arr[]);
 
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */

  
 do{
	
	int num;
	char arr[MAXIMUM];
	printf("Enter a valid integer number : ");
	if (scanf("%d", &num) != 1)
	{
		handle_error(ERROR_INVALID_INPUT);
		return 1;
	}
	if (num < 0) 
	{ 
		arr[index++] = '-'; 
		num = -num; 
	}
	int digit = log10(num);

	itoa(num, arr);
	printf("Converted string : ");
	if(num == 0)
		printf("%c", num + '0');
	for(int i =0; i<=digit; i++)
		printf("%c", arr[i]);
	if(arr[0] == '-')
			printf("%c", arr[digit+1]);
	index=0;
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}

 
/* printd: print n in decimal */ 
void itoa(int n, char arr[]) 
{ 
	//static char arr[MAXIMUM];
	//int index = 0;

	if (n / 10 >0)  
		itoa(n / 10, arr);  
	arr[index++] = (n % 10 + '0'); 
	return;
}
