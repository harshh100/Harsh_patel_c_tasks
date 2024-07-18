/*
*Modify the temperature conversion program to print a heading above the table. 

*Author : Harsh Patel (164975)

*Created:17/7/24

*/
 
/** required header files */
#include <stdio.h>

// Print Fahrenheit-Celsius table
// for ffahr = 0, 20, ... 300
// floating point version

/** main function */
int main()
{
  float fFahr;	  // Fahrenheit value
  float fCelsius; // celsius value
  int iLower=0;	  // start value of table
  int iUpper=300; // end value of thable
  int iStep=20;	  // incrementing values

  // Printing a heading above the table
  printf("Fahr\t\tCelsius\n");
  printf("-----------------------\n");

  fFahr = iLower;
  
  // Printing the table
  while (fFahr <= iUpper)
  {
    fCelsius = (5.0 / 9.0) * (fFahr - 32.0);
    printf("%3.0f\t\t%6.1f\n", fFahr, fCelsius);
    fFahr = fFahr + iStep;
  }

  return 0;
}

