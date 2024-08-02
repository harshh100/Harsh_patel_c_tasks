/*
*Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest. 

*Author : Harsh Patel (164975)

*Created : 31/7/24

*Modified : 31/7/24

*/
 
/** required header files */
#include <stdio.h>

#define MAXLENGTH 5000 /* max input length*/ 

int main(void)
{
    int iCounter=0;          /* counter */
    char cInput[MAXLENGTH];  /* input store */
    printf("Enter Code:\n=========================\n");
    while((cInput[iCounter]=getchar()) != EOF)   /* input tacking */
    		iCounter++;
    cInput[iCounter]='\0';
    
        printf("\nResult:\n=========================\n");
        iCounter = 0;
        while (cInput[iCounter] != '\0') {
            if (cInput[iCounter] == '/' && cInput[iCounter+1] == '/') {   /* for single line comment */
                iCounter += 2;
                while (cInput[iCounter] != '\n' && cInput[iCounter] != '\0')  /* skip tht line */
                    ++iCounter;
            } else if (cInput[iCounter] == '/' && cInput[iCounter+1] == '*') { /* for multiline line comment */
                iCounter += 2;
                while (cInput[iCounter] != '\0' && cInput[iCounter+1] != '\0' && (cInput[iCounter] != '*' || cInput[iCounter+1] != '/')) 	/* skip all multiline */
                    ++iCounter;
                if (cInput[iCounter] != '\0' && cInput[iCounter+1] == '\0')
                    ++iCounter;
                if (cInput[iCounter] == '*')  /* check for end of comment line */
                    iCounter += 2;
            } else if (cInput[iCounter] == '\"') {  /* for "" */
                putchar('\"');
                ++iCounter;
                while (cInput[iCounter] != '\0' && (cInput[iCounter-1] == '\\' || cInput[iCounter] != '\"'))
                    putchar(cInput[iCounter++]);
            } else {
                putchar(cInput[iCounter++]);
            }
        }
    return 0;
}

/**
 * Test text

 /**
  * Hello World
  */
  
  /*
 #include <stdio.h> // for printf

 int main(void)
 {
     char cInput[] = "// hello \
         world!\n";
     printf("%s\n", s);
 
     return 0;
 }

*/
