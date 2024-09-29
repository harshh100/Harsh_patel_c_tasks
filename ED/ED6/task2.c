/*
*task2 

*Author : Harsh Patel (164975)

*Created:17/9/24

*/
#include<stdio.h>
#include<string.h>

#define MAX_INPUT 14

/* Structure to hold information about a person */
struct Person{
	char cName[MAX_INPUT]; /* Name of the person */
	char cHomeTown[MAX_INPUT]; /* Hometown of the person */
	int iAge; /* Age of the person */
	int iSalary;  /* Salary of the person */
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
	
	/* Add age and salary for the specified person */
	add_age_salary(Persons,cSearchName,3);
	
	printf("\n");
	printf("Do you want to Search Again [1 for YES / 0 for NO] : "); 
	scanf("%d",&iRunAgain);
	printf("\n");
	fflush(stdin);
  
  }while(iRunAgain);
  	
  	/* Save the details to a file */
	file_save(Persons);
	return 0;
}

/* 
 * inputPersons(function name) : Function to input details of multiple persons. 
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
		
		/* Copy input data into the persons array */
		strcpy(Persons[iInputCounter].cName,cInputName);
		strcpy(Persons[iInputCounter].cHomeTown,cInputHomeTown);
		//Persons[iInputCounter].cPHomeTown =cInputHomeTown;
	}
}


/* 
 * add_age_salary(function name) : Function to add age and salary for a specific person. 
 * Author : Harsh Patel (164975)
 */
void add_age_salary(struct Person Persons[], char cSearchName[], int numPersons){
	for(int iSearchCounter=0;iSearchCounter<numPersons;iSearchCounter++){
		
		if(!strcmp(cSearchName,Persons[iSearchCounter].cName)){
			int iInputAge; /* Variable to store the input age */
			int iInputSalary;  /* Variable to store the input salary */
			printf("\n--> For '%s' \n",Persons[iSearchCounter].cName);
			printf("Enter Age : ");
			scanf("%d",&iInputAge);
			printf("Enter Salary : ");
			scanf("%d",&iInputSalary);
			
			/* Assign age and salary to the respective person */
			Persons[iSearchCounter].iAge=iInputAge;
			Persons[iSearchCounter].iSalary=iInputSalary;
			break; /* Exit the loop after updating the person */
		}
	}
}


/* 
 * file_save(function name) : Function to save the details of persons to a file. 
 * Author : Harsh Patel (164975)
 */
void file_save(struct Person Persons[]){
	FILE *fptr = fopen("OutPut.txt", "w"); 
	
	/* Check if the file was opened successfully */
     if (fptr == NULL) 
     { 
        printf("Could not open file"); 
        return; 
     } 
     
     /* Write each person's details to the file */
	for(int iSaveCounter=0;iSaveCounter<3;iSaveCounter++){
		fprintf(fptr,"%d %s %s %d %d\n", (iSaveCounter+1), Persons[iSaveCounter].cName,Persons[iSaveCounter].cHomeTown,Persons[iSaveCounter].iAge,Persons[iSaveCounter].iSalary);
	}
	
	/* Close the file */
	fclose(fptr);
}

