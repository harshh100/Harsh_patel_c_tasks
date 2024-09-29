#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          /* Data stored in the node */
    struct Node* left; /* Pointer to left child */
    struct Node* right; /* Pointer to right child */
    int size;         /* To store the size of the subtree rooted at this node */
} Node;

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->size = 0; /* Initialize size */
    return newNode;
}

/* Function to count the number of nodes in the subtree rooted at 'node' */
int countSubtreeNodes(Node* node) {
    if (node == NULL) {
        return 0; /* No node */
    }

    /* Recursively count nodes in left and right subtrees */
    int leftCount = countSubtreeNodes(node->left);
    int rightCount = countSubtreeNodes(node->right);

    /* Total size is 1 (the current node) + size of left and right subtrees */
    node->size = 1 + leftCount + rightCount;

    return node->size;
}

/* Function to print the sizes of the subtrees */
void printSubtreeSizes(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->size);
    printSubtreeSizes(node->left);
    printSubtreeSizes(node->right);
}

int main() {
    int n;
    scanf("%d", &n);

    /* Create an array of node pointers */
    Node** nodes = (Node**)malloc((n + 1) * sizeof(Node*));

    /* Initialize nodes */
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i); /* Using the node's index as its data */
    }

    /* Read the nodes and establish left and right children */
    for (int i = 1; i <= n; i++) {
        int left, right;
        scanf("%d %d", &left, &right);
        if (left != 0) {
            nodes[i]->left = nodes[left];
        }
        if (right != 0) {
            nodes[i]->right = nodes[right];
        }
    }

    /* Count the size of the subtree starting from the root (node 1) */
    countSubtreeNodes(nodes[1]);

    /* Print the sizes of the subtrees for each node */
    for (int i = 1; i <= n; i++) {
        printf("%d ", nodes[i]->size);
    }
    printf("\n");

    /* Free the allocated memory */
    for (int i = 1; i <= n; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}

