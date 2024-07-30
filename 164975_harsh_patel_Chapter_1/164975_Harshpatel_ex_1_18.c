/*
*Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines.

*Author : Harsh Patel (164975)

*Created: 30/7/24

*/
 
/** required header files */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */ 

int get_line(char cStr[],int iLimit) /* getline function */
{
	 int iInput, iCounter; 
	 printf("Enter Input : ");
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

int remove_space(char cStr[]){
	int iCounter =0;
	while(cStr[iCounter] != '\n') /* reach the end of string */
		iCounter++;
	
	iCounter--; /* point at before '\n'  */
	
	while( iCounter>=0 && (cStr[iCounter] == ' ' || cStr[iCounter] == '\t')) /* backtrack untill reads character */
		iCounter--;
		
	
	if(iCounter>=0){
		iCounter++;
		cStr[iCounter] = '\n'; 	/* add '\n' at the end of sting*/
		iCounter++;
		cStr[iCounter] = '\0';   /* add '\0' at end of string */
	}
	
	return iCounter;
	
}



/** main function */
int main()
{

	
	char cLine[MAXLINE]; /* current input line */ 

	 while ((get_line(cLine, MAXLINE)) > 0) 
	 {
		 if (remove_space(cLine)>0) /* check if non-empty string exist or not */
		 { 
			printf("Line : %s\n",cLine);
		 } else{
		 	printf("Line : \n");
		 }		 
	}
  
  
  return 0;
}
