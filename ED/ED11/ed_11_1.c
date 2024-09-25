
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int main() {
    
    int iStack[MAX_SIZE];
    int iStackPointer=-1;
    
    int iQueue[MAX_SIZE];
    int iQueueFront=-1;
    int iQueueBack=-1;
    
    int iNumOfEmp;
    printf("Enter Number Of Employees : ");
    scanf("%d",&iNumOfEmp);
    
    printf("\nEnter types of Dhosa  for Dhasa stack ( 0 for shada and 1 for masala dhosa )     : ");
    
    for(int iStackCounter=iNumOfEmp-1;iStackCounter>=0;iStackCounter--){
    		scanf("%d",&iStack[iStackCounter]);
    }
    
    
    iStackPointer=iNumOfEmp-1;
   // printf("\niQueueFront : %d, iQueueBack : %d, iStackPointer : %d",iQueueFront,iQueueBack,iStackPointer);
    
    printf("\nEnter types of Dhosa  for employees queue ( 0 for shada and 1 for masala dhosa ) : ");
    
    for(int iQueueCounter=0;iQueueCounter<iNumOfEmp;iQueueCounter++){
    		scanf("%d",&iQueue[iQueueCounter]);
    		iQueueBack=iQueueCounter;
    }
    
    
    
    iQueueFront=0;
    int iUnmachedCount=0;
    
    //printf("\niQueueFront : %d, iQueueBack : %d, iStackPointer : %d, iUnmachedCount : %d",iQueueFront,iQueueBack,iStackPointer,iUnmachedCount);
    
    while(iQueueFront<=iQueueBack){
    		//printf("\niQueueFront : %d, iQueueBack : %d, iStackPointer : %d, iUnmachedCount : %d",iQueueFront,iQueueBack,iStackPointer,iUnmachedCount);
    		if(iUnmachedCount==(iQueueBack-iQueueFront+1)){
    			 printf("Ans : %d",(iQueueBack-iQueueFront+1));
    			 return 0;
    		}
    		
    		if(iQueue[iQueueFront]==iStack[iStackPointer]){
    			//printf("\nMatched");
    			iStackPointer--;
    			iQueueFront++;
    			iUnmachedCount=0;
    		}else{
    		    	//printf("\nUnMatched");
    			iQueue[iQueueBack+1]=iQueue[iQueueFront];
    			iQueueFront++;
    			iQueueBack++;
    			iUnmachedCount++;
    		}	
    
    }
    
    
    printf("\nAns : %d",(iQueueBack-iQueueFront+1));
    
    return 0;
}

