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
	printf("x= %d y = %d\n",x,y);
	
	int t =m_swap(x,y);
	printf("x= %d y = %d\n",x,y);
	printf("t: %d\n",t);
}
