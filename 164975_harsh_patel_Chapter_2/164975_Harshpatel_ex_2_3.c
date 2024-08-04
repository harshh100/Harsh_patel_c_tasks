/*
*Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F. 

*Author : Harsh Patel (164975)

*Created : 2/8/24

*Modified : 2/8/24

*/
 
/** required header files */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define INPUT_SIZE 100

int My_htoi(char cHex[]);

/** main function */
int main()
{
  int iRunAgain=0;      	    /* for code run again or not */
  
 do{
	char cInput[INPUT_SIZE]; 	    /* input array */

	printf("Enter Hex Value (format: 0xHHHH) : ");
	scanf("%s",cInput);
	
	printf("Decimal Value : %d",My_htoi(cInput));
	
	printf("\n");
	printf("Do you want to Run Again [1 for YES / 0 for NO] : "); /* Ask for code run again*/
	scanf("%d",&iRunAgain);
	getchar();
  
  }while(iRunAgain);

  return 0;
}


int My_htoi(char cHex[])
{
	int iResult = 0;

     int iCounter = 0; 
     int iLen = strlen(cHex);  /* length of input string */

  while (iCounter < iLen)
  {
    if (cHex[iCounter] == '0' && (cHex[iCounter + 1] == 'x' || cHex[iCounter + 1] == 'X'))	/* skip 'x' and '0' */
    {
      iCounter += 2;
    }

    int iTemp = tolower(cHex[iCounter]);

    if (isdigit(iTemp))		/* convert degit character to integer */
    {
      iTemp -= 48;
    }

    if (isalpha(iTemp) && iTemp <= 'f')	/* convert alphabetical character to integer */
    {
      iTemp = iTemp - 'a' + 10;
    }

    if ((cHex[iCounter] >= '0' && cHex[iCounter] <= '9') || (cHex[iCounter] >= 'a' && cHex[iCounter] <= 'f') || (cHex[iCounter] >= 'A' && cHex[iCounter] <= 'F'))
    {
      iResult += iTemp * (int)pow(16, iLen - iCounter - 1);	/* calculation part */
    }
    else
    {
      printf("Error: Not a valid hex value.\n Try this format: 0xHHHH, where H is a hex digit.\n");	/* for invalid format */
      return -1;
    }

    ++iCounter;
  }

  return iResult;
}




