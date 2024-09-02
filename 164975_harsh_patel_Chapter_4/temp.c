#include<stdio.h>
#define swap(t,x,y) t=x;x=y;y=t
int main(){
	
	int a=5;
	int b=1;
	int temp;
	
	printf("a : %d, b : %d \n",a,b);
	
	swap(temp,a,b);
	
	printf("a : %d, b : %d",a,b);
}
