#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} clist;

void search(clist *l, int num);
void addnode(clist **l, int num);

int main() {
    clist *head = NULL;
    int n;

    printf("Enter Number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter Data: ");
        scanf("%d", &num);
        addnode(&head, num);
    }

    int searchNum;
    printf("\nEnter a number to search: ");
    scanf("%d", &searchNum);
    search(head, searchNum);

    return 0;
}

void addnode(clist **l, int num) {
    clist *h = *l;
    clist *newNode = (clist*)malloc(sizeof(clist));
    newNode->data = num;

    if (*l == NULL) {
        *l = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else {
        clist *temp = *l;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}

void search(clist *l, int num) {
    clist *temp = l;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == num) {
            printf("Number %d found at position %d.\n", num, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Number %d not found in the list.\n", num);
}

