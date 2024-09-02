#include<stdio.h>

int main(){
	
	char c,*cp;
	int i,*ip;
	float f,*fp;
	
	c='A';
	i=1;
	f=1.23;
	
	cp=&c;
	ip=&i;
	fp=&f;
	
	printf("Adress contain in cp : %p\n",cp);
	printf("Adress contain in ip : %p\n",ip);
	printf("Adress contain in fp : %p\n",fp);
	
	printf("Value of c : %c\n",*cp);
	printf("Value of i : %d\n",*ip);
	printf("Value of f : %f\n",*fp);
	

}
