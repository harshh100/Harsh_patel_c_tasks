#include<stdio.h>
int* myfun();

int main(){
	
	int* pt = myfun();
	printf("i : %d",*pt);
	return 0;
}

int* myfun(){
	
	static int i=10;
	return(&i);
}
