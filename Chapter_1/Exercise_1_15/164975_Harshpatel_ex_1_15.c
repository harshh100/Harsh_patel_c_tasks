/*
*Rewrite the temperature conversion program of Section 1.2 to use a function 
for conversion. 

*Author : Harsh Patel (164975)

*Created: 23/7/24

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
  float fFahr;    // Fahrenheit value
  float fCelsius; // celsius value
  int iLower=0;   // start value of table
  int iUpper=300; // end value of thable
  int iStep=20;   // incrementing values

  // Printing a heading above the table
  printf("Fahr\t\tCelsius\n");
  printf("-----------------------\n");

  fFahr = iLower;

  // Printing the table
  while (fFahr <= iUpper)
  {
    fCelsius = FahrenheitToCelsius(fFahr);          // FahrenheitToCelsius function call
    printf("%3.0f\t\t%6.1f\n", fFahr, fCelsius);
    fFahr = fFahr + iStep;					  // incrementing Fahrenheit
  }

  return 0;
}
