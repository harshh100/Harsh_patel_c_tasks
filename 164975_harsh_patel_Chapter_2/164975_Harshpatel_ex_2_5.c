/*
*Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.

*Author : Harsh Patel (164975)

*Created : 5/8/24

*Modified : 5/8/24

*/
 
/** required header files */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define INPUT_SIZE 50

int any(char cInput[],char cRemove[]);

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  

 do{
	char cInput[INPUT_SIZE]; 	    /* input array */
	char cRemove[INPUT_SIZE]; 	    /* remove character array */

	
	printf("Enter Main String : ");
	fgets(cInput,INPUT_SIZE,stdin);
	printf("Enter Remove characters : ");
	fgets(cRemove,INPUT_SIZE,stdin);
	
	if(any(cInput,cRemove)!= -1){
		printf("Matched Location : %d ,Matched Character : %c",any(cInput,cRemove),cInput[any(cInput,cRemove)]);
	
	}else{
		printf("No duplicate characters found.");
	}
	
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int any(char cInput[],char cRemove[]){
	
	int iInputLength = strlen(cInput);	/* Input array length */
	int iRemoveLength = strlen(cRemove);	/* Remove array length */
	
	for(int iInputCounter=0;iInputCounter<iInputLength-1;iInputCounter++){
	
		for(int iRemoveCounter=0;iRemoveCounter<iRemoveLength-1;iRemoveCounter++){
			
			if(tolower(cInput[iInputCounter])==tolower(cRemove[iRemoveCounter])){	/* if input character matched then return index */
				return iInputCounter;
			}
		
		}
		
	}
	
	return -1; /* no character matched then return -1 */

}
