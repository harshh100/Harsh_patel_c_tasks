/*
*Ths Program is to check error of missing parts in hello world Program

*Author : Harsh Patel (164975)

*Created:17/7/24

*/
 
 
/** required header files */

/** missing header file leads to provide declaration of printf */
//#include<stdio.h>

 
/** main function prints hello world */

int main()

{

    /** printing hello world */
  
    printf("Hello World");

    return 0;

}
 
/* ----ANS----
* //#include <stdio.h> -->  
warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   24 |     printf("Hello World");
* //int main()         --> error: expected identifier or ‘(’ before ‘{’ token
*/
