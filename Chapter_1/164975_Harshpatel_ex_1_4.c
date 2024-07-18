/*
*Write a program to print the corresponding Celsius to Fahrenheit table.  

*Author : Harsh Patel (164975)

*Created:17/7/24

*/

/** required header files */
#include <stdio.h>

/** main function */
int main()
{
  float fFahr;    // Fahrenheit value
  float fCelsius; // celsius value
  int iLower=0;   // start value of table
  int iUpper=300; // end value of thable
  int iStep=20;   // incrementing values

  printf("Celsius\t\tFahr\n");
  printf("-----------------------\n");

  fCelsius = iLower;
  while (fCelsius <= iUpper)
  {
    fFahr = (9.0 / 5.0) * fCelsius + 32.0f;
    printf("%3.0f\t\t%6.1f\n", fCelsius, fFahr);
    fCelsius = fCelsius + iStep;
  }

  return 0;
}
