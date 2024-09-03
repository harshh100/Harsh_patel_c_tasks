#include<stdio.h>

int main(){
	
	int *p1,i=25;
	void *p2;
	
	p1 = &i;
	p2 = &i;
	
	printf("p1 : %p, p2 : %p\n",p1,p2);
	
	p1=p2;
	p2=p1;
	
	printf("p1 : %p, p2 : %p",p1,p2);
}
