#include<stdio.h>

int main(){
	
/*	int,float to char pointer
	int i=23125;
	float f=1.23;
	char *ip,*fp;
	
	ip= (char*)&i;
	fp= (char*)&f;
	
	printf("Adress contain in ip : %p\n",ip);
	printf("Adress contain in fp : %p\n",fp);
	
	printf("Value of i : %d\n",*ip);
	printf("Value of f : %d\n",*fp);
*/

/*	char to int,float pointer	
	char c1='a';
	char c2='b';
	int *ip;
	float *fp;
	
	ip= (int*)&c1;
	fp= (float*)&c2;
	
	printf("Adress contain in ip : %p\n",ip);
	printf("Adress contain in fp : %p\n",fp);
	
	printf("Value of i : %d\n",*ip);
	printf("Value of f : %f\n",*fp);	
*/

	char c1='a';
	char c2='b';
	int *ip;
	float *fp;
	
	ip= &c1;
	fp= &c2;
	
	printf("Adress contain in ip : %p\n",ip);
	printf("Adress contain in fp : %p\n",fp);
	
	printf("Value of i : %d\n",*ip);
	printf("Value of f : %f\n",*fp);	
}
