/*
*Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.   

*Author : Harsh Patel (164975)

*Created:22/7/24

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
        putchar('*');
    }else if(iLastInput != ' ' && iLastInput != '\t'){
    	putchar('\n');
    }

    iLastInput = iInput; // update last input
  }
  return 0;
}
