/*
*Modify the temperature conversion program to print a heading above the table. 

*Author : Harsh Patel (164975)

*Created:17/7/24]

*Modified : 25/7/24

*/
 
/*required header files */
#include <stdio.h>

/* 
*Print Fahrenheit-Celsius table 
* for ffahr = 0, 20, ... 300
* floating point version 
*/

/* main function */
int main()
{
  float fFahr;	    		/* Fahrenheit value */
  float fCelsius; 		/* celsius value */
  int iLower=0;	  	/* start value of table */
  int iUpper=300; 		/* end value of thable */
  int iStep=20;	  	/* incrementing values */
  int iRunAgain=0;		/* for code run again or not */

  /* Printing a heading above the table */
  do{
  
  
  /* inputs */
  printf("Enter Lower Fahrenheit Value : "); /* start value of table */
  scanf("%d",&iLower);
  printf("Enter Upper Fahrenheit Value : "); /* end value of thable */
  scanf("%d",&iUpper);
  printf("Enter Step Value : ");  /* incrementing values */
  scanf("%d",&iStep);
  

  printf("Fahr\t\tCelsius\n");
  printf("-----------------------\n");

  fFahr = iLower; 		/* Fahrenheit initialisation */
  
  	  /* Printing the table */
	  while (fFahr <= iUpper)
	  {
	    fCelsius = (5.0 / 9.0) * (fFahr - 32.0);		/* Fahrenheit to celsius convertion */
	    printf("%3.0f\t\t%6.1f\n", fFahr, fCelsius);
	    fFahr = fFahr + iStep;
	  }
	  
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
  
   }while(iRunAgain);

  return 0;
}

