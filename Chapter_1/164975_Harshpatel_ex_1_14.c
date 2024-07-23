/*
*Write a program to print a histogram of the frequencies of different characters 
in its input.

*Author : Harsh Patel (164975)

*Created:23/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function */
int main()
{
	
	int iInput;
	int iAlphaFrequencies[26] = {0};
	int iDegitFrequencies[10] = {0};
	
	while((iInput = getchar()) != EOF){
		
		if( iInput >= 'a' && iInput <= 'z'){
			iAlphaFrequencies[iInput - 'a']++;
		}else if(iInput >= '0' && iInput <= '9'){
			iDegitFrequencies[iInput - '0']++;
		}else if(iInput >= 'A' && iInput <= 'Z'){
			iAlphaFrequencies[iInput - 'A']++;
		}

	}
	
	int iAlphaLength = sizeof(iAlphaFrequencies) / sizeof(iAlphaFrequencies[0]);
	int iDegitLength = sizeof(iDegitFrequencies) / sizeof(iDegitFrequencies[0]);
	
	for(int iI=0;iI< iAlphaLength ;iI++){
		if(iAlphaFrequencies[iI]>0){		
			printf("%c : ",('a'+iI));
		
		while(iAlphaFrequencies[iI]>0 ){
			putchar('*');
			iAlphaFrequencies[iI]--;
		}
		putchar('\n');
		}
	}
	
	for(int iI=0;iI< iDegitLength ;iI++){
		
		if(iDegitFrequencies[iI]>0){
			printf("%c : ",('0'+ iI));
		
		
		while(iDegitFrequencies[iI]>0){
			putchar('*');
			iDegitFrequencies[iI]--;
		}
		putchar('\n');
		
		}
	}
	
  return 0;
}
