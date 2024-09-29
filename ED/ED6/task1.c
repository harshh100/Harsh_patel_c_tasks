/*
*task1 

*Author : Harsh Patel (164975)

*Created:17/9/24

*/

#include<stdio.h>
#include<string.h>

#define MAX_INPUT 14

/* Structure to hold information about a person */
struct Person{
	char cName[MAX_INPUT];
	char cHomeTown[MAX_INPUT];
};

void inputPersons(struct Person persons[], int numPersons);
void searchPerson(struct Person persons[], char cSearchName[], int numPersons);

int main(){
	struct Person Persons[3];
	
	printf("\t\t\tINPUT");
	
	/* Input details of persons */
	inputPersons(Persons,3);
	
	printf("\n=========================================================\n");
	
	int iRunAgain=0;  
	do{
		
	char cSearchName[MAX_INPUT];
	printf("Enter the name of the person you want to search for : ");
	scanf("%s",cSearchName);
	
	/* Search for the person and display the result */
	
	searchPerson(Persons,cSearchName,3);
	
	printf("\n");
	printf("Do you want to Search Again [1 for YES / 0 for NO] : "); 
	scanf("%d",&iRunAgain);
	printf("\n");
	fflush(stdin);
  
  }while(iRunAgain);
	
	return 0;
}


/* 
* inputPersons : Function to input details of multiple persons.
* Author : Harsh Patel (164975)
*/

void inputPersons(struct Person Persons[], int numPersons){
	for(int iInputCounter=0;iInputCounter<numPersons;iInputCounter++){
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
}

/* 
* searchPerson : Function to search for a person by name and display their hometown.
* Author : Harsh Patel (164975)
*/

void searchPerson(struct Person Persons[], char cSearchName[],int numPersons){
	
	for(int iSearchCounter=0;iSearchCounter<numPersons;iSearchCounter++){
		
		if(!strcmp(cSearchName,Persons[iSearchCounter].cName)){
			printf("'%s' Lives in --> '%s'\n",cSearchName,Persons[iSearchCounter].cHomeTown);
			break;
		}
	}
}

/*printf("\n\t\t\tOUTPUT\n");
	for(int iPrintCounter=0;iPrintCounter<3;iPrintCounter++){
		printf("\nPerson %d\n",(iPrintCounter+1));
		printf("Name : %s\n",Persons[iPrintCounter].cName);
		printf("HomeTown : %s\n",Persons[iPrintCounter].cHomeTown);
		
}*/
	
