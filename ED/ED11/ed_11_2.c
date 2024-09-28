#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int iLeft;
    int iRight;
    int iSubtreeCount;
} Node;

int countSubtreeNodes(Node* tree, int iIndex) {
    /* if the current node is not valid (0)*/
    if (iIndex == 0) {
        return 0;
    }
    
    int iCount = 1; /* count the current node */

    /* recursively count nodes in left and right subtrees */
    iCount += countSubtreeNodes(tree, tree[iIndex].iLeft);
    iCount += countSubtreeNodes(tree, tree[iIndex].iRight);

    /* store the count of nodes in the current subtree */
    tree[iIndex].iSubtreeCount = iCount;

    return iCount;
}

int main() {
    int n;
    scanf("%d", &n);
    
    /* create an array to hold the tree nodes */
    Node* tree = (Node*)malloc((n + 1) * sizeof(Node));
    
    /* initialize nodes */
    for (int i = 1; i <= n; i++) {
        tree[i].iLeft = 0;
        tree[i].iRight = 0;
        tree[i].iSubtreeCount = 0;
    }

    /* read the left and right children for each node */
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tree[i].iLeft, &tree[i].iRight);
    }

    /* start counting from the root node (1) */
    countSubtreeNodes(tree, 1);

    /* print the subtree counts */
    for (int i = 1; i <= n; i++) {
        printf("%d ", tree[i].iSubtreeCount);
    }
    printf("\n");

    /* free allocated memory */
    free(tree);
    
    return 0;
}

