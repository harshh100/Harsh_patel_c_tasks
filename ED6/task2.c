#include<stdio.h>
#include<string.h>

#define MAX_INPUT 14

struct Person{
	char cName[MAX_INPUT];
	char cHomeTown[MAX_INPUT];
	int iAge;
	int iSalary;
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
		printf("Age : %s\n",Persons[iPrintCounter].iAge);
		printf("Salary : %s\n",Persons[iPrintCounter].iSalary);
		
		
	}*/
	
	printf("\n=========================================================\n");
	
	
	int iRunAgain=0;  
	do{
		
	char cSearchName[MAX_INPUT];
	printf("Enter the name of the person whose 'age' and 'salary' you want to add : ");
	scanf("%s",cSearchName);
	
	for(int iSearchCounter=0;iSearchCounter<3;iSearchCounter++){
		
		if(!strcmp(cSearchName,Persons[iSearchCounter].cName)){
			int iInputAge;
			int iInputSalary;
			printf("\nFor '%s' \n",Persons[iSearchCounter].cName);
			printf("Enter Age : ");
			scanf("%d",&iInputAge);
			printf("Enter Salary : ");
			scanf("%d",&iInputSalary);
			Persons[iSearchCounter].iAge=iInputAge;
			Persons[iSearchCounter].iSalary=iInputSalary;
			break;
		}
	}
	
	printf("\n");
	printf("Do you want to Search Again [1 for YES / 0 for NO] : "); 
	scanf("%d",&iRunAgain);
	printf("\n");
	fflush(stdin);
  
  }while(iRunAgain);
  
  	/*printf("\n\t\t\tOUTPUT\n");
	for(int iPrintCounter=0;iPrintCounter<3;iPrintCounter++){
		printf("\nPerson %d\n",(iPrintCounter+1));
		printf("Name : %s\n",Persons[iPrintCounter].cName);
		printf("HomeTown : %s\n",Persons[iPrintCounter].cHomeTown);
		printf("Age : %d\n",Persons[iPrintCounter].iAge);
		printf("Salary : %d\n",Persons[iPrintCounter].iSalary);
		
		
	}*/
	
	FILE *fptr = fopen("OutPut.txt", "w"); 
	
     if (fptr == NULL) 
     { 
        printf("Could not open file"); 
        return 0; 
     } 
     
     
     //fprintf(fptr,"%d.%s\n", i, str); 
	for(int iSaveCounter=0;iSaveCounter<3;iSaveCounter++){
		fprintf(fptr,"%d %s %s %d %d\n", (iSaveCounter+1), Persons[iSaveCounter].cName,Persons[iSaveCounter].cHomeTown,Persons[iSaveCounter].iAge,Persons[iSaveCounter].iSalary);
	}
	
	
	return 0;
}
