/*
*task3 

*Author : Harsh Patel (164975)

*Created:17/9/24

*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	/* Open the file for reading */
    FILE *file = fopen("OutPut.txt", "r");
    
    /* Check if the file was opened successfully */
    if (file == NULL) {
        printf("Error opening file");
        return 0;
    }

    char line[256]; /* Buffer to hold each line of the file */
    while (fgets(line, sizeof(line), file)) {
        
        int iIndex;          /* Variable to hold the index of the person */
        char cName[50];     /* Variable to hold the person's name */
        char cHomeTown[50]; /* Variable to hold the person's hometown */
        int iAge;           /* Variable to hold the person's age */
        int iSalary;        /* Variable to hold the person's salary */
        
        
        /* Read and parse the line from the file */
        sscanf(line, "%d %s %s %d %d", &iIndex, cName, cHomeTown, &iAge, &iSalary);
        
        /* Print the details of the person */
        printf("name : %s\n", cName);
        printf("town : %s\n", cHomeTown);
        printf("age : %d\n", iAge);
        printf("salary : %d\n\n", iSalary);
    }

	/* Close the file */
    fclose(file);
    return 0;
}

