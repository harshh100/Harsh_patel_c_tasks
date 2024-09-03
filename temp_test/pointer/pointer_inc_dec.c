#include<stdio.h>

int main(){
	
	int *p;
	
	int value = 5;
	p = &value;
	printf("*p   : %d, &p : %p\n",*p,p);
	printf("++*p : %d, &p : %p\n",++*p,p);
	printf("*p++ : %d, &p : %p\n",*p++,p);
	printf("*p   : %d, &p :%p\n",*p,p);

}
