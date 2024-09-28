#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_LAST_NAME_LENGTH 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_LAST_NAME_LENGTH];
    int age;
    float salary;
} Person;

void addLastNames() {
    FILE *file = fopen("OutPut.txt", "r");
    FILE *newFile = fopen("OutPut_with_lastnames.txt", "w");
    if (!file || !newFile) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    Person person;
    int index = 0;

    // Read each line and prompt for last name
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*d %s %*s %d %f", person.name, &person.age, &person.salary);
        
        printf("Enter last name for %s: ", person.name);
        fgets(person.lastName, MAX_LAST_NAME_LENGTH, stdin);
        person.lastName[strcspn(person.lastName, "\n")] = 0; // Remove newline

        // Write to the new file
        fprintf(newFile, "%d %s %s %d %.2f\n", index + 1, person.name, person.lastName, person.age, person.salary);
        index++;
    }

    fclose(file);
    fclose(newFile);
}

void printUpdatedData() {
    FILE *file = fopen("OutPut_with_lastnames.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Updated List of People:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    addLastNames();
    printUpdatedData();
    return 0;
}

