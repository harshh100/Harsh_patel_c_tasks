#include<stdio.h>

int main(){
	int i=3;
	//int *j=&i;
	
	printf("\ni : %u",i);
	printf("\n&i : %p",&i);
	printf("\n&i size : %lu",sizeof(&i));
	//printf("j : %d\n",*j);
	//printf("&j : %ls\n",j);
	
	char j='3';
	//int *j=&i;
	
	printf("\nj : %c",j);
	printf("\n&j : %p",&j);
	printf("\n&j size : %lu",sizeof(&j));
	
	int a=3;
	char b='3';
	printf("\n&a : %p",&a);
	printf("\n&b : %p",&b);
}
