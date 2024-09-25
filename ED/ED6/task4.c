#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void searchByName(const char *searchName) {
    FILE *file = fopen("OutPut.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Person person;
        sscanf(line, "%*d %s %*s %d %f", person.name, &person.age, &person.salary);

        if (strcmp(person.name, searchName) == 0) {
            printf("name: %s\n", person.name);
            printf("age: %d\n", person.age);
            printf("salary: %.2f\n", person.salary);
            fclose(file);
            return;
        }
    }
    printf("Person not found.\n");
    fclose(file);
}

int main() {
    char searchName[MAX_NAME_LENGTH];
    printf("What’s the name of the person you want to search for? :  ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    searchByName(searchName);

    return 0;
}

