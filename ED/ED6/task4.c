#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *file = fopen("OutPut.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 0;
    }
    printf("Enter The name Which you want to search:");
    char searchName[50];
    scanf("%s",searchName);		 
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int iIndex;
        char cName[50], cHomeTown[50];
        int iAge, iSalary;
        sscanf(line, "%d %s %s %d %d", &iIndex, cName, cHomeTown, &iAge, &iSalary);
        if (strcmp(cName, searchName) == 0) {
        printf("name : %s\n", cName);
        printf("town : %s\n", cHomeTown);
        printf("age : %d\n", iAge);
        printf("salary : %d\n\n", iSalary);
        }
    }
    fclose(file);
    return 0;
}
