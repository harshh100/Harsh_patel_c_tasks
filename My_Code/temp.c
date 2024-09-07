/*
*Rewrite the temperature conversion program of Section 1.2 to use a function 
for conversion. 

*Author : Harsh Patel (164975)

*Created : 23/7/24

*Modfied : 29/7/24

*/

/** required header files */
#include <stdio.h>

/* Fahrenheit To Celsius convrtion function*/
float FahrenheitToCelsius(float fFahrenheit){
	return (5.0 / 9.0) * (fFahrenheit - 32.0); 
}

/** main function */
int main()
{
  float fFahr;          /* Fahrenheit value */
  float fCelsius;       /* celsius value */
  int iLower=0;         /* start value of table */
  int iUpper=300;       /* end value of thable */
  int iStep=20;         /* incrementing values */
  int iRunAgain=0;      /* for code run again or not */

	
// 	do{
	
	  /* inputs */
	  printf("Enter Lower Celsius Value : "); /* start value of table */
	  scanf("%d",&iLower);
	  printf("iLower : %d",iLower);
// 	  printf("Enter Upper Celsius Value : "); /* end value of thable */
// 	  scanf("%d",&iUpper);
// 	  printf("Enter Step Value : ");  /* incrementing values */
//   	  scanf("%d",&iStep);
		
// 	  printf("Celsius\t\tFahr\n");
// 	  printf("-----------------------\n");

// 	  fCelsius = iLower;		    /* Fahrenheit initialisation */
	  
// 	  while (fCelsius <= iUpper)
// 	  {
// 	    fFahr = FahrenheitToCelsius(fCelsius);      /* celsius to Fahrenheit convertion */
// 	    printf("%3.0f\t\t%6.1f\n", fCelsius, fFahr);
// 	    fCelsius = fCelsius + iStep;
// 	  }
	  
// 	  printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
//       scanf("%d",&iRunAgain);
		
// 	}while(iRunAgain);	
	
  return 0;
}
