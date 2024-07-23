/*
*Experiment to find out what happens when prints's argument string contains 
\c, where c is some character not listed above.

*Author : Harsh Patel (164975)

*Created:17/7/24

*/
 
 
/** required header files */

#include <stdio.h>
 
/** main function */

int main()

{

    /** \b is backspace */
    printf("Hello\b world");

    return 0;

} 

/* OUTPUT 
*Hell world
*/

