/*
*Write a program to copy its input to its output, replacing each tab by \t, each 
*backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an 
*unambiguous way. 

*Author : Harsh Patel (164975)

*Created:22/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
  int iInput; // input variable
  while((iInput=getchar())!= EOF){
    if (iInput == '\t')
    {
      putchar('\\');    // print '\'
      putchar('t');     // print 't'
    }
    else if (iInput == '\b')
    {
      putchar('\\');    // print '\'
      putchar('b');     // print 'b'
    }
    else if (iInput == '\\')
    {
      putchar('\\');    // print '\'
      putchar('\\');    // print '\'
    }
    else
    {
      putchar(iInput);  // print input
    }
  }
  return 0;
}
