/*
*task5

*Author : Harsh Patel (164975)

*Created:17/9/24

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LAST_NAME_LENGTH 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char cName[MAX_NAME_LENGTH];
    char cLastName[MAX_LAST_NAME_LENGTH];
    int iAge;
    float iSalary;
} Person;

/* 
* addLastNames : Function to input details of multiple persons with last names. 
* Author : Harsh Patel (164975)
*/
void addLastNames() {
    FILE *pFile = fopen("OutPut.txt", "r");
    FILE *pNewFile = fopen("OutPut_with_lastnames.txt", "w");
    
    if (!pFile || !pNewFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH]; /* Buffer to read each line from the file */
    Person person; /* Structure to hold person details */
    int iIndex = 0; /* Counter for the number of persons */

    /* Read each line and prompt for last cName */
    while (fgets(line, sizeof(line), pFile)) {
        sscanf(line, "%*d %s %*s %d %f", person.cName, &person.iAge, &person.iSalary);
        
        printf("Enter last cName for %s: ", person.cName);
        fgets(person.cLastName, MAX_LAST_NAME_LENGTH, stdin);
        person.cLastName[strcspn(person.cLastName, "\n")] = 0; /* Remove newline */

        /* Write the updated person details to the new file */
        fprintf(pNewFile, "%d %s %s %d %.2f\n", iIndex + 1, person.cName, person.cLastName, person.iAge, person.iSalary);
        iIndex++;
    }

    fclose(pFile);
    fclose(pNewFile);
}

/* 
* printUpdatedData : Function to print updated list of persons with last names. 
* Author : Harsh Patel (164975)
*/
void printUpdatedData() {
    FILE *pFile = fopen("OutPut_with_lastnames.txt", "r");
    
    if (!pFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH]; /* Buffer to read each line from the updated file */
    printf("Updated List of People:\n");
    
    /* Print each line from the updated file */
    while (fgets(line, sizeof(line), pFile)) {
        printf("%s", line);
    }

    fclose(pFile);
}

int main() {
    addLastNames(); /* Input last names for persons */
    printUpdatedData(); /* Print the updated list of persons */
    return 0;
}

