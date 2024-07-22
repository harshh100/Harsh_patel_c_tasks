/*
*Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.  

*Author : Harsh Patel (164975)

*Created:17/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
  int iInput;		 // input store
  int iLastInput = '\0' ; // last input store

  while ((iInput = getchar()) != EOF) // input until end of file
  {
    if ( ( iInput != ' ' && iInput != '\t' ))  //check for single blank
    {
        putchar(iInput);
    }else if(iLastInput != ' ' && iLastInput != '\t'){
    	putchar(' ');
    }

    iLastInput = iInput; // update last input
  }
  return 0;
}
