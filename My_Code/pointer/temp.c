#include <stdio.h>
int getmylen(int arr[8]);
int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    
    printf("main : %ld\n",sizeof(arr)/sizeof(arr[0]));
    printf("&arr(main) : %p\n",&arr);
    printf("&arr+1(main) : %p\n",&arr+1);
     
    printf("getlen : %d\n",getmylen(arr));

    return 0;
}

int getmylen(int arr[8]){
    printf("&arr(getmylen) : %p\n",&arr);
    printf("&arr+1(getmylen) : %p\n",&arr+1);
    printf("arr[0] : %d, arr[1] : %d\n",arr[0],arr[1]);
    int len = sizeof(arr)/sizeof(arr[0]);
    return len;
}
