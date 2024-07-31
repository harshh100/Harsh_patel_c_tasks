/*
*How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? 

*Author : Harsh Patel (164975)

*Created:22/7/24

*Modified : 29/7/24

*/
 
/** required header files */
#include <stdio.h>

#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */ 

/** main function */
int main()
{
  int c, nl, nw, nc, state; 
  state = OUT; 
  nl = nw = nc = 0;
  
    printf("Enter Input : ");

    while ((c = getchar()) != EOF) { 
    	++nc; 
        if (c == '\n') 
        	++nl; 
        if (c == ' ' || c == '\n' || c == '\t') 
        	state = OUT; 
        else if (state == OUT) { 
        	state = IN; 
        	++nw; 
        } 
    } 
  printf("\nlines : %d, words : %d, character : %d\n", nl, nw, nc);
  return 0;
}

/*--test case--
*  1. add more than one blank between two words
*  2. add more than one newline between two words
*  3. add more than one tabs between two words
*  4. do not write anything
*  5. just write blanks
*  6. just write newline 
*/   
