#include <stdio.h>


int ascending(int a, int b);
int descending(int a, int b);


void sort(int arr[], int n, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (compare(arr[j], arr[j + 1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    char order;


    printf("Enter sorting order (a for ascending, d for descending): ");
    scanf(" %c", &order);


    int (*compare)(int, int) = NULL;


    if (order == 'a') {
        compare = ascending;  
    } else if (order == 'd') {
        compare = descending;  
    } else {
        printf("Error: unknown sorting order.\n");
        return 1; 
    }


    sort(arr, n, compare);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


int ascending(int a, int b) {
    return a - b;  
}

int descending(int a, int b) {
    return b - a;  
}

