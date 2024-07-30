/*
*Write a program to print a histogram of the frequencies of different characters 
in its input.

*Author : Harsh Patel (164975)

*Created:23/7/24

*/
 
/** required header files */
#include <stdio.h>

/** main function version 1.0 */
/*int main()
{
	
	int iInput;  					//input
	int iAlphaFrequencies[26] = {0};	//alphabetical character frequencies
	int iDegitFrequencies[10] = {0};	//digit frequenies
	
	while((iInput = getchar()) != EOF){ //input loop
		
		if( iInput >= 'a' && iInput <= 'z'){   		// check for alphabetical character
			iAlphaFrequencies[iInput - 'a']++;
		}else if(iInput >= '0' && iInput <= '9'){	// check for digit
			iDegitFrequencies[iInput - '0']++;
		}else if(iInput >= 'A' && iInput <= 'Z'){	// check for capital alphabetical character
			iAlphaFrequencies[iInput - 'A']++;
		}

	}
	
	int iAlphaLength = sizeof(iAlphaFrequencies) / sizeof(iAlphaFrequencies[0]); // length of alphabetical character array
	int iDegitLength = sizeof(iDegitFrequencies) / sizeof(iDegitFrequencies[0]); // length of digit array
	
	for(int iI=0;iI< iAlphaLength ;iI++){	// print alphabetical character's histogram
		if(iAlphaFrequencies[iI]>0){		
			printf("%c : ",('a'+iI));	// alphabetical character print
		
		while(iAlphaFrequencies[iI]>0 ){	// alphabetical charater's histogram print
			putchar('*');
			iAlphaFrequencies[iI]--;
		}
		putchar('\n');
		}
	}
	
	for(int iI=0;iI< iDegitLength ;iI++){	// print  digit's frequencies
		
		if(iDegitFrequencies[iI]>0){		
			printf("%c : ",('0'+ iI));	// digit print
		
		
		while(iDegitFrequencies[iI]>0){	// digit's histogram print
			putchar('*');
			iDegitFrequencies[iI]--;
		}
		putchar('\n');
		
		}
	}
	
  return 0;
}*/

/** main function version 2.0 */
int main()
{
	
	int iInput;  						/* input*/
	int iCharaterFrequencies[128] = {0};	/* character frequencies store*/
	
	printf("Enter String : ");
	
	while((iInput = getchar()) != EOF){ 	/* input loop */
		if(iInput>-1){
			iCharaterFrequencies[iInput]++;
		}
	}
	
	int iCharLength = sizeof(iCharaterFrequencies) / sizeof(iCharaterFrequencies[0]); /* length of charater array */
	
	printf("\n");
	
	for(int iI=0;iI< iCharLength ;iI++){		/* print character's histogram */
		
		if(iCharaterFrequencies[iI]>0){
		
		if(iI==9)		
			printf("\\t: ");				/* \t print */
		else if(iI==10)
			printf("\\n: ");				/* \n print */
		else if(iI==32)
			printf("\\s: ");				/* \s print */
		else
			printf("%c : ",(iI)); 			/* other character print */
			
		while(iCharaterFrequencies[iI]>0 ){	/* character's histogram print */
			putchar('*');
			iCharaterFrequencies[iI]--;
		}
		putchar('\n');
		}
	}
	
  return 0;
}


