#include<stdio.h>
#include<string.h>

#define MAX_INPUT 14

struct Person{
	char cName[MAX_INPUT];
	char cHomeTown[MAX_INPUT];
	int age;
	int salary;
};

int main(){
	struct Person Persons[3];
	
	printf("\t\t\tINPUT");
	for(int iInputCounter=0;iInputCounter<3;iInputCounter++){
		char cInputName[MAX_INPUT];
		char cInputHomeTown[MAX_INPUT];
		printf("\nFor Person %d\n",(iInputCounter+1));
		printf("Enter Name : ");
		scanf("%s",cInputName);
		printf("Enter HomeTown : ");
		scanf("%s",cInputHomeTown);
		strcpy(Persons[iInputCounter].cName,cInputName);
		strcpy(Persons[iInputCounter].cHomeTown,cInputHomeTown);
		//Persons[iInputCounter].cPHomeTown =cInputHomeTown;
	}
	
	/*printf("\n\t\t\tOUTPUT\n");
	for(int iPrintCounter=0;iPrintCounter<3;iPrintCounter++){
		printf("\nPerson %d\n",(iPrintCounter+1));
		printf("Name : %s\n",Persons[iPrintCounter].cName);
		printf("HomeTown : %s\n",Persons[iPrintCounter].cHomeTown);
		
	}*/
	
	printf("\n=========================================================\n");
	
	int iRunAgain=0;  
	do{
		
	char cSearchName[MAX_INPUT];
	printf("Enter the name of the person you want to search for : ");
	scanf("%s",cSearchName);
	
	for(int iSearchCounter=0;iSearchCounter<3;iSearchCounter++){
		
		if(!strcmp(cSearchName,Persons[iSearchCounter].cName)){
			printf("'%s' Lives in '%s'\n",cSearchName,Persons[iSearchCounter].cHomeTown);
			break;
		}
	}
	
	printf("\n");
	printf("Do you want to Search Again [1 for YES / 0 for NO] : "); 
	scanf("%d",&iRunAgain);
	printf("\n");
	fflush(stdin);
  
  }while(iRunAgain);
	
	return 0;
}
