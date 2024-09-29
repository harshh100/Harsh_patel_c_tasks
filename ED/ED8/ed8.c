#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLEN 64

typedef struct node {
    char name[STRLEN];
    struct node *next;
} Node;

void showHelp(void);
void add(char *, Node **);
void removeElement(char *, Node **);
int isItem(char *, Node *);
int countItems(Node *);
void removeList(Node **);
void showList(Node *);
char * trim(char *);

int main(void) {
    char instruction[STRLEN];
    Node *head = NULL;
    char *pi;

    printf("Test program for a single-linked list.\n");
    printf("\nEnter an instruction (h = help)\n");
    
    while (1) {
        printf("\n> ");
        if (fgets(instruction, sizeof(instruction), stdin) == NULL) {
            break; /* Handle EOF or input error */
        }
        instruction[strcspn(instruction, "\n")] = 0; /* Remove the newline character */
        pi = trim(instruction);
        
        if (*pi == 'q') break;

        switch (*pi) {
            case 'i': add(trim(pi + 1), &head); break;
            case 'd': removeElement(trim(pi + 1), &head); break;
            case 'f': 
                if (isItem(trim(pi + 1), head))
                    printf("\"%s\" is in the list.\n", trim(pi + 1));
                else
                    printf("\"%s\" is NOT in the list.\n", trim(pi + 1));
                break;
            case 'l': showList(head); break;
            case 'n': printf("Number of list items: %d\n", countItems(head)); break;
            case 'r': removeList(&head); break;
            case 'h': showHelp(); break;
            default: printf("Unknown instruction (h = help)\n");
        }
    }
    
    removeList(&head);
    return 0;
}

void showHelp(void) {
    printf("i <string> : inserts the element in <string> alphabetically into the list\n");
    printf("d <string> : removes the element in <string> from the list\n");
    printf("f <string> : searches the list and returns if the string is in the list or not.\n");
    printf("l : shows the full list\n");
    printf("n : returns the number of items in the list\n");
    printf("r : removes the full list\n");
    printf("h : shows the help menu (this list).\n");
    printf("q : end of the program (first remove the list)\n");
}

void add(char *s, Node **b) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, s);
    newNode->next = NULL;

    if (*b == NULL || strcmp((*b)->name, s) > 0) {
        newNode->next = *b;
        *b = newNode;
        return;
    }

    Node *current = *b;
    while (current->next != NULL && strcmp(current->next->name, s) < 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeElement(char *s, Node **b) {
    if (*b == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = *b;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->name, s) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\"%s\" not found in the list.\n", s);
        return;
    }

    if (previous == NULL) {
        *b = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("\"%s\" has been removed from the list.\n", s);
}

int isItem(char *s, Node *b) {
    while (b != NULL) {
        if (strcmp(b->name, s) == 0) {
            return 1;
        }
        b = b->next;
    }
    return 0;
}

int countItems(Node *b) {
    int count = 0;
    while (b != NULL) {
        count++;
        b = b->next;
    }
    return count;
}

void removeList(Node **b) {
    Node *p = *b;
    while (p != NULL) {
        *b = p->next;
        free(p);
        p = *b;
    }
}

void showList(Node *b) {
    if (b == NULL) {
        printf("The list is EMPTY\n");
    } else {
        printf("The list:\n");
        while (b != NULL) {
            printf("%s ", b->name);
            b = b->next;
        }
        printf("\n");
    }
}

char * trim(char *s) {
    while (*s == ' ') s++;
    return s;
}

