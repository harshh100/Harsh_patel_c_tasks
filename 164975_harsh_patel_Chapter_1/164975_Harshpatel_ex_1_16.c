/*
*Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text. 

*Author : Harsh Patel (164975)

*Created : 30/7/24

*Modified : 30/7/24

*/
 
/* Required Libraries */
#include <stdio.h> 
#define MAXLINE 1000 /* maximum input line length */ 
/* int getline(char line[], int maxline); 
void copy(char to[], char from[]); */
/* print the longest input line */ 
/* getline: read a line into s, return length */ 

int get_line(char cStr[],int iLimit) /* getline function */
{
	 int iInput, iCounter; 
	 for (iCounter=0; iCounter < iLimit-1 && (iInput=getchar())!=EOF && iInput!='\n'; ++iCounter) /* tack input untill '\n' or EOF */
	 	cStr[iCounter] = iInput; 
	 if (iInput == '\n') /* store '\n' at the end of string */
	 { 
		 cStr[iCounter] = iInput; 
		 ++iCounter; 
	 } 
	 cStr[iCounter] = '\0'; /* store '\0' at the end of string */
	 return iCounter; 
}

/* copy: copy 'from' into 'to'; assume to is big enough */ 
void copy(char cTo[], char cFrom[]) 
{ 
	 int iCounter =0; 
	 while ((cTo[iCounter] = cFrom[iCounter]) != '\0') 
	 	++iCounter;
}
 
int main() 
{ 
	 int iLen; /* current line length */ 
	 int iMax =0; /* maximum length seen so far */ 
	 char cLine[MAXLINE]; /* current input line */ 
	 char cLongest[MAXLINE]; /* longest line saved here */ 
	
	printf("Enter Input : ");
	 while ((iLen = get_line(cLine, MAXLINE)) > 0) 
	 {
		 if (iLen > iMax) /* compare size of current line with max line */
		 { 
			 iMax = iLen; 
			 copy(cLongest, cLine); 
		 } 
	}
	 if (iMax > 0) /* there was a line */ 
	 	printf("\nLongest line is %s with length %d", cLongest,iMax); 
	 return 0; 
}





