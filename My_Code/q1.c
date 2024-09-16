#include <stdio.h>

char my_swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

int m_swap(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

int main()
{
	int x=10,y=20; 
	
	my_swap(&x,&y);
	printf("x= %d y = %d",x,y);
	
	int t =m_swap(x,y);
	printf("\nx= %d y = %d",x,y);
	printf("\nt: %d",t);
}
