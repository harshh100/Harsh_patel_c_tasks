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


/*
* max: return max value
* Author: Harsh Patel (164975)
* Created: 23/7/24
* Modified: 23/7/24
*/

int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

/** main function version 2.0 */
int main()
{
	
	int iInput;  						/* input*/
	int iCharaterFrequencies[127] = {0};	/* character frequencies store*/
	int imy_max='\0';
	
	printf("Enter String : ");
	
	while((iInput = getchar()) != EOF){ 	/* input loop */
		if(iInput>-1){
			iCharaterFrequencies[iInput]++;	/* frequency count */
			imy_max = max(imy_max,iCharaterFrequencies[iInput]);   /* find maximum frequency */
		}
	}
	
	int iX = 127;		/* value of x-axis for plotting graph */
	int iY = imy_max;   /* value of y-axis for plotting graph */


puts("\n===== VERTICAL HISTOGRAM =====\n");

	
  for (int iFreqCounter = iY; iFreqCounter > 0; iFreqCounter--) {	/* traverse lower frequency count to higher  */
      
    printf("%d |\t", iFreqCounter);		/* Printing '|' */
    
    for(int iCharCounter = 1; iCharCounter < iX ; iCharCounter++) {  /* traverse for each character */
            
        if(iCharaterFrequencies[iCharCounter]>0){			/* printing '*' or ' ' */
            
          if (iCharaterFrequencies[iCharCounter] < iFreqCounter)
            printf("\t");
          else
            printf("*\t");
        }
    }
    putchar('\n');
        
  }
  
  
  /* Printing '-----' */		
  printf("   ");
  for (int iCharCounter = 0; iCharCounter < iX; iCharCounter++){
      if(iCharaterFrequencies[iCharCounter]>0)
        printf("--------");
  }
    
  putchar('\n');
  
  /* Printing characters */ 
  for (int iCharCounter = 0; iCharCounter < iX; iCharCounter++){
    if(iCharaterFrequencies[iCharCounter]>0)
        if(iCharCounter==9)		
			printf("\t\\t");				/* \t print */
		else if(iCharCounter==10)
			printf("\t\\n");				/* \n print */
		else if(iCharCounter==32)
			printf("\t\\s");				/* \s print */
		else
			printf("\t%c", iCharCounter); 			/* other character print */
  }
  putchar('\n');
	
  return 0;
}


