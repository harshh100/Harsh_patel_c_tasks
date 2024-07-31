/*
*Write a program to print all input lines that are longer than 80 characters

*Author : Harsh Patel (164975)

*Created : 30/7/24

*Modified : 30/7/24

*/
 
/*required header files*/
/*stdio for input output function*/
#include <stdio.h>
#define highest_length 1000 /*highest length of array size*/
/*MAIN function*/
 
 
int main(){ /*main function start*/
 
	char cArray[highest_length];      /* Input array */
	int iStartArray[highest_length];  /* array of starting index of line which have length>8  */
	int iEnd=0;				    /* end pointer of line */
	int iStart=0;				    /* start pointer of line */
	int iCounter=0;			    /* counter */
	char cInput;				    /* Input character */

	while((cInput=getchar())!=EOF){   
	 
		if(cInput=='\n'){			/* when new line comes */
			if(iEnd-iStart > 8)		/* check if line length is greater than mininum length */
			{
			    iStartArray[iCounter++]=iStart;	/* store first index of line */
			}
			iStart=iEnd+1;			/* update start pointer to next line */
		} 
		cArray[iEnd++]=cInput;		/* input storing */
	}
	cArray[iEnd]='\n';				/* append '\n' at the end of array */
	if(iEnd-iStart > 8)				/* for last line of input */
	{
	    iStartArray[iCounter++]=iStart;
	}
	printf("\n");
	printf("Line longer than 8 characters:\n");
	
	for(int iIndex=0;iIndex<iCounter;iIndex++){
		int iFlag=iStartArray[iIndex];
		while(cArray[iFlag]!='\n'){			/* print starting index to '\n' for each starting index of line*/
			printf("%c",cArray[iFlag]);
			iFlag++;
		}
	printf("\n"); /*For better output view*/
	}
return 0;
}



