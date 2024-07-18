/*
*Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

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
	

  for (fCelsius = iUpper; fCelsius >= iLower; fCelsius = fCelsius - iStep)
  {
    fFahr = (9.0 / 5.0) * fCelsius + 32.0f;
    printf("%3.0f\t\t%6.1f\n", fCelsius, fFahr);
  }

  return 0;
}
