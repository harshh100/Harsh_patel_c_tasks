//./task2 01 12 2014 ages.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];
    Date birthdate;
} Person;

// function to read a person's data from the file
int read_person(FILE *file, Person *person) {
    if (fgets(person->name, sizeof(person->name), file) == NULL) {
        return 0; 
    }
    // femove newline character from name
    person->name[strcspn(person->name, "\n")] = '\0';
    fscanf(file, "%d %d %d", &person->birthdate.day, &person->birthdate.month, &person->birthdate.year);
    return 1;
}

void calculate(Date current, Person *person, int *years, int *months, int *days) {
    if (current.day < person->birthdate.day) {
        current.day += 30; 
        current.month--;
    }
    if (current.month < person->birthdate.month) {
        current.month += 12;
        current.year--;
    }

    *years = current.year - person->birthdate.year;
    *months = current.month - person->birthdate.month;
    *days = current.day - person->birthdate.day;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <day> <month> <year> <file>\n", argv[0]);
        return 1;
    }

    Date current;
    current.day = atoi(argv[1]);
    current.month = atoi(argv[2]);
    current.year = atoi(argv[3]);

    FILE *file = fopen(argv[4], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person people[100];
    int count = 0;
    while (read_person(file, &people[count])) {
        count++;
    }
    fclose(file);

    int maxYears = -1, oldestIndex = -1;
    int maxNameLength = 0, longestNameIndex = -1;

    printf("The ages are:\n");
    for (int i = 0; i < count; i++) {
        int years, months, days;
        calculate(current, &people[i], &years, &months, &days);
        
        printf("%s is %d years old\n", people[i].name, years);

        // Check for oldest person
        if (years > maxYears) {
            maxYears = years;
            oldestIndex = i;
        }

        // Check for longest name
        int nameLength = strlen(people[i].name);
        if (nameLength > maxNameLength) {
            maxNameLength = nameLength;
            longestNameIndex = i;
        }
    }

    if (oldestIndex != -1) {
        printf("%s is the oldest of the %d persons in the file.\n", people[oldestIndex].name, count);
    }
    
    if (longestNameIndex != -1) {
        printf("The person with the longest name is: %s\n", people[longestNameIndex].name);
    }

    return 0;
}

