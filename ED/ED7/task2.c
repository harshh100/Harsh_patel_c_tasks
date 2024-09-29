/*
*task5\2

*Author : Harsh Patel (164975)

*Created:18/9/24

*/

/*./task2 01 12 2014 ages.txt */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int iDay;   /* Day of the birthdate */
    int iMonth; /* Month of the birthdate */
    int iYear;  /* Year of the birthdate */
} Date;

typedef struct {
    char cName[100]; /* Name of the person */
    Date birthdate; /* Birthdate of the person */
} Person;


/* 
* read_person : Function to read a person's data from the file. 
* Author : Harsh Patel (164975)
*/
int read_person(FILE *pFile, Person *pPerson) {
    while (fgets(pPerson->cName, sizeof(pPerson->cName), pFile) != NULL) {
        if (strlen(pPerson->cName) > 1) { // Check for non-empty line
            break;
        }
    }
    
    /* Remove newline character from name */
    pPerson->cName[strcspn(pPerson->cName, "\n")] = '\0';
  //  printf("\nname : %s", pPerson->cName);
    
    // Read date
    if (fscanf(pFile, "%d %d %d", &pPerson->birthdate.iDay, &pPerson->birthdate.iMonth, &pPerson->birthdate.iYear) != 3) {
        return 0; /* Return 0 if date reading fails */
    }
    
    //printf("\ndate : %d %d %d", pPerson->birthdate.iDay, pPerson->birthdate.iMonth, pPerson->birthdate.iYear);
    return 1;
}

/* 
* calculate : Function to calculate age in years, months, and days. 
* Author : Harsh Patel (164975)
*/
void calculate(Date current, Person *pPerson, int *piYears, int *piMonths, int *piDays) {
    if (current.iDay < pPerson->birthdate.iDay) {
        current.iDay += 30; 
        current.iMonth--;
    }
    
    if (current.iMonth < pPerson->birthdate.iMonth) {
        current.iMonth += 12;
        current.iYear--;
    }

    *piYears = current.iYear - pPerson->birthdate.iYear;
    *piMonths = current.iMonth - pPerson->birthdate.iMonth;
    *piDays = current.iDay - pPerson->birthdate.iDay;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <day> <month> <year> <file>\n", argv[0]);
        return 1;
    }

    Date current; /* Current date */
    current.iDay = atoi(argv[1]);   /* Day from command line argument */
    current.iMonth = atoi(argv[2]); /* Month from command line argument */
    current.iYear = atoi(argv[3]);  /* Year from command line argument */

    FILE *pFile = fopen(argv[4], "r");
    if (pFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person people[100]; /* Array to hold person data */
    int iCount = 0; /* Counter for number of people */
    
    /* Read persons from the file */
    while (read_person(pFile, &people[iCount])) {
    		//printf("\n  iCount : %d",iCount);
        iCount++;
    }
    fclose(pFile);

    int iMaxYears = -1, iOldestIndex = -1; /* Variables for oldest person */
    int iMaxNameLength = 0, iLongestNameIndex = -1; /* Variables for longest name */

    printf("The ages are:\n");
    for (int i = 0; i < iCount; i++) {
        int iYears, iMonths, iDays;
        calculate(current, &people[i], &iYears, &iMonths, &iDays);
       // printf("i : %d",i);
        printf("%s is %d years old\n", people[i].cName, iYears);

        /* Check for oldest person */
        if (iYears > iMaxYears) {
            iMaxYears = iYears;
            iOldestIndex = i;
        }

        /* Check for longest name */
        int iNameLength = strlen(people[i].cName);
        if (iNameLength > iMaxNameLength) {
            iMaxNameLength = iNameLength;
            iLongestNameIndex = i;
        }
    }

    /* Print oldest person */
    if (iOldestIndex != -1) {
        printf("%s is the oldest of the %d persons in the file.\n", people[iOldestIndex].cName, iCount);
    }
    
    /* Print person with longest name */
    if (iLongestNameIndex != -1) {
        printf("The person with the longest name is: %s\n", people[iLongestNameIndex].cName);
    }

    return 0;
}

