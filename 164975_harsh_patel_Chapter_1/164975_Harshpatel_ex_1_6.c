/*
*Verify that the expression getchar() != EOF is 0 or 1. 

*Author : Harsh Patel (164975)

*Created:17/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
	while(getchar() != EOF ){
		 printf("value of expression: %d\n", getchar() != EOF);
	}
	
	printf("value of expression: %d\n", getchar() != EOF);
  return 0;
}

/* --input--
h
value of expression: 1
p
value of expression: 1
value of expression: 0  // Ctrl + D in linux
*/
