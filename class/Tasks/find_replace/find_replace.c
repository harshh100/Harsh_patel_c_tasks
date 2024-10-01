#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void replace_word_in_file(const char *filename, const char *old_word, const char *new_word) {
    
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    

    char line[MAX_LINE_LENGTH];
    int pos;

   
    char temp[MAX_LINE_LENGTH];	 /* temporary buffer for modified lines */
	
    
    while (fgets(line, sizeof(line), file)) {	/* read each line from the file */
        /* reset temp buffer */
        temp[0] = '\0';

        /* find and replace occurrences of old_word */
        char *ptr = line;
        printf("\nptr : %s",ptr);
        
        while (1) {
        printf("\nwhile start");
            char *next_occurrence = strstr(ptr, old_word);
            printf("\nnext_occurrence : %s",next_occurrence);
            if (!next_occurrence) {
                /* if no more occurrences, append the rest of the line */
                strcat(temp, ptr);
                printf("\nwhile brea/end");
                break;
            }

            /* copy everything before the found word to temp */
            printf("next_occurrence : %ld, ptr : %ld",next_occurrence,ptr);
            printf("\nnext_occurrence - ptr : %ld",next_occurrence - ptr);
            strncat(temp, ptr, next_occurrence - ptr);
            
            /* append the new word to temp */
            printf("\ntemp : %s",temp);
            strcat(temp, new_word);
            printf("\ntemp : %s",temp);

            /* move pointer past the old word */
            ptr = next_occurrence + strlen(old_word);
            printf("\nptr : %s",ptr);
            printf("\nwhile end");
        }

        /* move file pointer back to the current position */
        pos = ftell(file);
        printf("\npos : %d",pos);
        /* clear the line from the file */
        fseek(file, pos - strlen(line), SEEK_SET);
        /* write the modified line back */
        fputs(temp, file);
        /* adjust file position */
        fseek(file, pos, SEEK_SET);
    }

    fclose(file);
    printf("Replacement done.\n");
}

int main() {
    char filename[256] = "my_text.txt";
    char old_word[100];
    char new_word[100];

    //printf("Enter the filename: ");
   // scanf("%s", filename);
    printf("Enter the word to find: ");
    scanf("%s", old_word);
    printf("Enter the word to replace with: ");
    scanf("%s", new_word);

    replace_word_in_file(filename, old_word, new_word);

    return 0;
}

