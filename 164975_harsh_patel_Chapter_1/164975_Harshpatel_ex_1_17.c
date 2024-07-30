/*
*Write a program to print all input lines that are longer than 80 characters

*Author : Harsh Patel (164975)

*Created : 30/7/24

*Modified : 30/7/24

*/
 
/* Required Libraries */
#include <stdio.h> 
#define MAXLINE 1000 /* maximum input line length */ 
#define MINSIZE 8 /* minimum character */
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
 
int main() 
{ 
	 int iLen; /* current line length */  
	 char cLine[MAXLINE]; /* current input line */ 
	
	printf("Enter Input : ");
	 while ((iLen = get_line(cLine, MAXLINE)) > 0) 
	 {
		 if (iLen > MINSIZE) /* compare size of current line with minimun character */
		 { 
			printf("Line longer than %d characters: %s",MINSIZE,cLine);
		 } 
	} 
	 return 0; 
}





