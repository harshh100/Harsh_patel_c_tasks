/* this program made for recresive form of reverse str
Author:Harsh Patel (164975)
created date: 29/8/24
*/
 
/*required header files*/
/*stdio for input output function*/
#include <stdio.h>
#include <string.h>
#define INPUT_SIZE 1000
/*MAIN function*/
 
void reverse(char* cInput,int start,int end){

	char temp;
	temp=cInput[end];
	cInput[end]=cInput[start];
	cInput[start]=temp;
	
	if(start>=end)
	  return;
	else
  	  reverse(cInput,start+1,end-1);   
}
 
int main(){ /*main function start*/
 
 int iRunAgain=0;      	    /* for code run again or not */
 do{
     char cInput[INPUT_SIZE];
	printf("Enter String: ");
	fgets(cInput,INPUT_SIZE,stdin);
	reverse(cInput,0,strlen(cInput) - 1);
	printf("AFter Reversing String: %s ",cInput);

    	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);
 
}
