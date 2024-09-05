#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);

	int *MBlock = (int*)malloc(n*sizeof(int));

	printf("Before Initilization {malloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",MBlock[i]);
	}
	
	for(int i=0;i<n;i++)
		MBlock[i]=i+1;
	
	printf("\nAfter Initilization {malloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",MBlock[i]);
	}
	
	free(MBlock);
	printf("\nAfter free {malloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",MBlock[i]);
	}
	
	int *CBlock = (int*)calloc(n,sizeof(int));

	printf("\n\nBefore Initilization {calloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",CBlock[i]);
	}
	
	for(int i=0;i<n;i++)
		CBlock[i]=i+1;
	
	printf("\nAfter Initilization {calloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",CBlock[i]);
	}
	
	free(CBlock);
	printf("\nAfter free {calloc} : ");
	for(int i=0;i<n;i++){
		printf("%d ",CBlock[i]);
	}

}

