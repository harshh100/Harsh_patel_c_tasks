/*
*Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 

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
  	if(iInput != ' ' && iInput != '\t' && iInput != '\n'){
  		putchar('*');
  	}else if (iLastInput != ' ' && iLastInput != '\t' && iLastInput != '\n' && iLastInput != '\0'){ 
  		putchar('\n');
  	}
  }
  
  return 0;
}
