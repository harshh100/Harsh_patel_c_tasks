#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}clist;

//typedef struct Node clist;

void printCList(clist *l, const clist *h);
void addnode(clist **l,int num);

int main(){
	
	clist *head = NULL;
	int n;
		
	printf("Enter Number of element : ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		
		int num;
		printf("Enter Data : ");
		scanf("%d",&num);
		addnode(&head,num);
	}
	
	printf("Reverse list : ");
	printCList(head,head);
	
}


void addnode(clist **l,int num){
	
	clist *h = *l;
	
	clist *newNode = (clist*)malloc(sizeof(clist));
	newNode->data=num;
	
	if(*l==NULL){
		*l = newNode;
		newNode->next=newNode;
	}else{
		
	   clist *temp = *l;
	   
        while (temp->next != *l) { 
            temp = temp->next;
        }
        
        temp->next = newNode; 
        newNode->next = *l; 
		
	}
		
}



void printCList(clist *l, const clist *h){
	
	if (l == NULL) return;
	
	if(l->next==h){
		printf("%d ",l->data);
		return;
	}
	
	printCList(l->next,h);
	printf("%d ",l->data);
	
};
