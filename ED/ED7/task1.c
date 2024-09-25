#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *args[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", args[0]);
        return 1;
    }

    FILE *file1 = fopen(args[1], "r");
    FILE *file2 = fopen(args[2], "r");
    
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening one of the files.\n");
        return 1;
    }

    char cLineOf1[256];
    char cLineOf2[256];
    int iLine = 1;
    int iDifferenceCount = 0;

    // Compare lines of both files
    while (fgets(cLineOf1, sizeof(cLineOf1), file1) && fgets(cLineOf2, sizeof(cLineOf2), file2)) {
        if (strcmp(cLineOf1, cLineOf2) != 0) {
            iDifferenceCount++;
            printf("-------------------------\n");
            printf("Line %d has not matched!\n", iLine);
            printf("Line of %s: %s", args[1], cLineOf1);
            printf("Line of %s: %s", args[2], cLineOf2);
            printf("-------------------------\n\n");

            // Stop printing after 10 differences
            if (iDifferenceCount >= 10) {
                printf("Stopped printing after 10 differences.\n");
                break;
            }
        }
        iLine++;
    }

    // Check for remaining lines in either file
    while (fgets(cLineOf1, sizeof(cLineOf1), file1)) {
        iDifferenceCount++;
        printf("-------------------------\n");
        printf("Line %d has not matched!\n", iLine);
        printf("Line of %s: %s", args[1], cLineOf1);
        printf("Line of %s: (No matching line)\n", args[2]);
        printf("-------------------------\n\n");
        iLine++;
        if (iDifferenceCount >= 10) {
            printf("Stopped printing after 10 differences.\n");
            break;
        }
    }

    while (fgets(cLineOf2, sizeof(cLineOf2), file2)) {
        iDifferenceCount++;
        printf("-------------------------\n");
        printf("Line %d has not matched!\n", iLine);
        printf("Line of %s: (No matching line)\n", args[1]);
        printf("Line of %s: %s", args[2], cLineOf2);
        printf("-------------------------\n\n");
        iLine++;
        if (iDifferenceCount >= 10) {
            printf("Stopped printing after 10 differences.\n");
            break;
        }
    }

    if (iDifferenceCount == 0) {
        printf("The files are Same.\n");
    }

    fclose(file1);
    fclose(file2);
    return 0;
}

