#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LAST_NAME_LENGTH 100
#define MAX_STREET_LENGTH 100
#define MAX_POSTAL_CODE_LENGTH 10
#define MAX_STATE_LENGTH 50
#define MAX_LINE_LENGTH 512

typedef struct {
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_LAST_NAME_LENGTH];
    int iAge;
    float fSalary;
    char cStreet[MAX_STREET_LENGTH];
    int iNumber;
    char cPostalCode[MAX_POSTAL_CODE_LENGTH];
    char cState[MAX_STATE_LENGTH];
} Person;

/* 
* addFullInfo : Function to input full details of multiple persons. 
* Author : Harsh Patel (164975)
*/
void addFullInfo() {
    FILE *pFile = fopen("OutPut.txt", "r");
    FILE *pNewFile = fopen("OutPut_with_full_info.txt", "w");
    
    if (!pFile || !pNewFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH]; /* Buffer to read each line from the file */
    Person person; /* Structure to hold person details */
    int iIndex = 0; /* Counter for the iNumber of persons */

    /* Read each line and prompt for additional information */
    while (fgets(line, sizeof(line), pFile)) {
        sscanf(line, "%*d %s %*s %d %f", person.name, &person.iAge, &person.fSalary);
        
        printf("\n\nEnter last name for %s: ", person.name);
        fgets(person.lastName, MAX_LAST_NAME_LENGTH, stdin);
        person.lastName[strcspn(person.lastName, "\n")] = 0; /* remove newline */


        printf("Enter cStreet for %s: ", person.name);
        fgets(person.cStreet, MAX_STREET_LENGTH, stdin);
        person.cStreet[strcspn(person.cStreet, "\n")] = 0; /* Remove newline */


        printf("Enter iNumber for %s: ", person.name);
        scanf("%d", &person.iNumber);
        getchar(); /* consume newline character */

        printf("Enter postal code for %s: ", person.name);
        fgets(person.cPostalCode, MAX_POSTAL_CODE_LENGTH, stdin);
        person.cPostalCode[strcspn(person.cPostalCode, "\n")] = 0; /* remove newline */

        printf("Enter cState for %s: ", person.name);
        fgets(person.cState, MAX_STATE_LENGTH, stdin);
        person.cState[strcspn(person.cState, "\n")] = 0; /* Remove newline */

        /* Write the complete information of the person to the new file */
        fprintf(pNewFile, "%d %s %s %d %.2f %s %d %s %s\n", iIndex + 1, person.name, person.lastName, person.iAge, person.fSalary, person.cStreet, person.iNumber, person.cPostalCode, person.cState);
        iIndex++;
    }

    fclose(pFile);
    fclose(pNewFile);
}

/* 
* printUpdatedData() : Function to print updated list of persons with full information. 
* Author : Harsh Patel (164975)
*/
void printUpdatedData() {
    FILE *pFile = fopen("OutPut_with_full_info.txt", "r");
    
    if (!pFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH]; /* Buffer to read each line from the updated file */
    printf("Updated List of People with Full Information:\n");
    
    /* Print each line from the updated file */
    while (fgets(line, sizeof(line), pFile)) {
        printf("%s", line);
    }

    fclose(pFile);
}

int main() {
    addFullInfo(); /* Input full information for persons */
    printUpdatedData(); /* Print the updated list of persons */
    return 0;
}

