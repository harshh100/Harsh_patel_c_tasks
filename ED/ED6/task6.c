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
    int age;
    float salary;
    char street[MAX_STREET_LENGTH];
    int number;
    char postalCode[MAX_POSTAL_CODE_LENGTH];
    char state[MAX_STATE_LENGTH];
} Person;

void addFullInfo() {
    FILE *file = fopen("OutPut.txt", "r");
    FILE *newFile = fopen("OutPut_with_full_info.txt", "w");
    if (!file || !newFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    Person person;
    int index = 0;

    // Read each line and prompt for additional information
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*d %s %*s %d %f", person.name, &person.age, &person.salary);
        
        printf("\n\nEnter last name for %s: ", person.name);
        fgets(person.lastName, MAX_LAST_NAME_LENGTH, stdin);
        person.lastName[strcspn(person.lastName, "\n")] = 0; // Remove newline

        printf("Enter street for %s: ", person.name);
        fgets(person.street, MAX_STREET_LENGTH, stdin);
        person.street[strcspn(person.street, "\n")] = 0; // Remove newline

        printf("Enter number for %s: ", person.name);
        scanf("%d", &person.number);
        getchar(); // consume newline character

        printf("Enter postal code for %s: ", person.name);
        fgets(person.postalCode, MAX_POSTAL_CODE_LENGTH, stdin);
        person.postalCode[strcspn(person.postalCode, "\n")] = 0; // Remove newline

        printf("Enter state for %s: ", person.name);
        fgets(person.state, MAX_STATE_LENGTH, stdin);
        person.state[strcspn(person.state, "\n")] = 0; // Remove newline
	
        // Write to the new file
        fprintf(newFile, "%d %s %s %d %.2f %s %d %s %s\n", index + 1, person.name, person.lastName, person.age, person.salary, person.street, person.number, person.postalCode, person.state);
        index++;
    }

    fclose(file);
    fclose(newFile);
}

void printUpdatedData() {
    FILE *file = fopen("OutPut_with_full_info.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Updated List of People with Full Information:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    addFullInfo();
    printUpdatedData();
    return 0;
}

