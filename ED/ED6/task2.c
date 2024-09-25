#include<stdio.h>
#include<string.h>

#define MAX_INPUT 14

struct Person{
	char cName[MAX_INPUT];
	char cHomeTown[MAX_INPUT];
	int iAge;
	int iSalary;
};

void inputPersons(struct Person Persons[], int numPersons);
void add_age_salary(struct Person persons[], char cSearchName[], int numPersons);
void file_save(struct Person Persons[]);

int main(){
	struct Person Persons[3];
	
	printf("\t\t\tINPUT");
	inputPersons(Persons,3);
	
	/*printf("\n\t\t\tOUTPUT\n");
	for(int iPrintCounter=0;iPrintCounter<3;iPrintCounter++){
		printf("\nPerson %d\n",(iPrintCounter+1));
		printf("Name : %s\n",Persons[iPrintCounter].cName);
		printf("HomeTown : %s\n",Persons[iPrintCounter].cHomeTown);
		printf("Age : %s\n",Persons[iPrintCounter].iAge);
		printf("Salary : %s\n",Persons[iPrintCounter].iSalary);
		
		
	}*/
	
	printf("\n=========================================================\n");
	
	
	int iRunAgain=0;  
	do{
		
	char cSearchName[MAX_INPUT];
	printf("--> Enter the name of the person whose 'age' and 'salary' you want to add : ");
	scanf("%s",cSearchName);
	
	add_age_salary(Persons,cSearchName,3);
	
	printf("\n");
	printf("Do you want to Search Again [1 for YES / 0 for NO] : "); 
	scanf("%d",&iRunAgain);
	printf("\n");
	fflush(stdin);
  
  }while(iRunAgain);
  	
	file_save(Persons);
	return 0;
}

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

void add_age_salary(struct Person Persons[], char cSearchName[], int numPersons){
	for(int iSearchCounter=0;iSearchCounter<numPersons;iSearchCounter++){
		
		if(!strcmp(cSearchName,Persons[iSearchCounter].cName)){
			int iInputAge;
			int iInputSalary;
			printf("\n--> For '%s' \n",Persons[iSearchCounter].cName);
			printf("Enter Age : ");
			scanf("%d",&iInputAge);
			printf("Enter Salary : ");
			scanf("%d",&iInputSalary);
			Persons[iSearchCounter].iAge=iInputAge;
			Persons[iSearchCounter].iSalary=iInputSalary;
			break;
		}
	}
}

void file_save(struct Person Persons[]){
	FILE *fptr = fopen("OutPut.txt", "w"); 
	
     if (fptr == NULL) 
     { 
        printf("Could not open file"); 
        return; 
     } 
     
	for(int iSaveCounter=0;iSaveCounter<3;iSaveCounter++){
		fprintf(fptr,"%d %s %s %d %d\n", (iSaveCounter+1), Persons[iSaveCounter].cName,Persons[iSaveCounter].cHomeTown,Persons[iSaveCounter].iAge,Persons[iSaveCounter].iSalary);
	}
	
	fclose(fptr);
}

