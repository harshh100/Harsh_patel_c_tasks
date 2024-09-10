#include<stdio.h>

int main(){
	char str1[] = "hello";
	char str2[] = "";
	
	char *str3 = "world";
	char *str4 = "";
	
	str2 = str1;
	str4 = str3;
	
	printf("Str 1 : %s",str1);
	printf("\nStr 2 : %s",str2);
	printf("\nStr 3 : %s",str3);
	printf("\nStr 4 : %s",str4);
}
