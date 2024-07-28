/*
*Write a program to count blanks, tabs, and newlines.

*Author : Harsh Patel (164975)

*Created : 18/7/24

*Modified : 26/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
  int iBlanksCount = 0;   /* number of blanks */
  int iTabsCount = 0;     /* number of tabs */
  int iNewlinesCount = 0; /* number of newlines */
 
  int iInput = 0;
  
  printf("Enter string : ");

	  while ((iInput = getchar()) != EOF) /*take input untile end of file */
	  {
	    if (iInput == ' ') /* check for blank */
	    {
		 ++iBlanksCount;
	    }
	    else if (iInput == '\t') /* check for tab */
	    {
		 ++iTabsCount;
	    }
	    else if (iInput == '\n') /* check for new line */
	    {
		 ++iNewlinesCount;
	    }
	  }
	  
	  printf("Total Blanks : %d\nTotal Tabs : %d\nTotal Newlines : %d\n", iBlanksCount, iTabsCount, iNewlinesCount);
	
  return 0;
}
