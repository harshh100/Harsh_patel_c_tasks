#include <stdio.h>

int main()
{
    int arr[2][3] ={{1,2,3},{4,5,6}};
    int (*p)[] = arr;
    
    printf("Base address:-\n");
    printf("arr           : %p\n",arr);
    printf("&arr[0][0]    : %p\n\n",&arr[0][0]);
    
    printf("Row Jump:-\n");
    printf("arr+1         : %p\n",arr+1);
    printf("&arr[1][0]    : %p\n\n",&arr[1][0]);
    
    printf("Column Jump:-\n");
    printf("*(arr+1)+1    : %p\n",*(arr+1)+1);
    printf("&arr[1][1]    : %p\n\n",&arr[1][1]);
    printf("*(arr)+1      : %p\n",*(arr)+1);
    printf("&arr[0][1]    : %p\n",&arr[0][1]);

    return 0;
}
