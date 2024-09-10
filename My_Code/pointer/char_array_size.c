#include <stdio.h>

int main()
{
    char *arr1[]={"Frogs","Do","Not","Die","They","Croak!"};
    
    printf("sizeof(arr1) : %d, sizeof(arr1[0]) : %d",sizeof(arr1),sizeof(arr1[0]));
    
    char arr2[6][6]={"Frogs","Do","Not","Die","They","Croak!"};
    printf("\nsizeof(arr2) : %d, sizeof(arr2[0]) : %d",sizeof(arr2),sizeof(arr2[0]));

    return 0;
}
