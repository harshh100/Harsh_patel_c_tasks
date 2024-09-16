#include <stdio.h>

int main() {
    char str[1000];  // Assuming input will be less than 1000 characters
    int length = 0;

    printf("Enter String : ");
    while (1) {
        int c = getchar();
        if (c == EOF || c == '\n') break;
        str[length++] = (char)c;
    }
    str[length] = '\0';  // Null-terminate the string

    printf("\n");
    
    
    // Loop through each character in the string
    for (int i = 0; i < length; i++) {
        int count = 0;
        // Check if the current character has already been counted
        int already_counted = 0;
        for (int k = 0; k < i; k++) {
            if (str[k] == str[i]) {
                already_counted = 1;
                break;
            }
        }
        if (already_counted) {
            continue;
        }
        
        // Count the occurrences of str[i]
        for (int j = 0; j < length; j++) {
            if (str[j] == str[i]) {
                count++;
            }
        }

        // Print the histogram
        if (str[i] == '\t') {
            printf("\\t: ");
        } else if (str[i] == '\n') {
            printf("\\n: ");
        } else if (str[i] == ' ') {
            printf("\\s: ");
        } else {
            printf("%c : ", str[i]);
        }

        for (int k = 0; k < count; k++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}

