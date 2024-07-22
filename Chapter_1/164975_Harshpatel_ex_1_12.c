/*
*Write a program that prints its input one word per line.

*Author : Harsh Patel (164975)

*Created:22/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
  int iInput;
  int iLastInput = '\0';
  
  while((iInput=getchar()) != EOF){
  	
  	if(iInput == ' ' || iInput == '\t' || iInput == '\n' ){
  		if(iLastInput != ' ' && iLastInput != '\t' && iLastInput != '\n' && iLastInput != '\0'){  		
  			putchar('\n');
  		}
  	}else{
  		putchar(iInput);
  	}
  	iLastInput = iInput;
  
  }
  
  return 0;
}
