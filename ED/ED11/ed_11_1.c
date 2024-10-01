#include <stdio.h>
#define MAX_SIZE 100

int count_unmatched_employees(int iStack[], int iStack_size, int iQueue[], int iQueue_size){
    
    int iQueueFront=0;
    int iQueueBack=iQueue_size;
    int iStackPointer=iStack_size;
    int iUnmachedCount=0;
    
    while(iQueueFront<=iQueueBack){
    
    	//	printf("\niQueueFront : %d , iQueueBack : %d , iStackPointer : %d ",iQueueFront,iQueueBack,iStackPointer);
    		
    		if(iUnmachedCount==(iQueueBack-iQueueFront+1)){
    	//		 printf("\niUnmachedCount");
    	//		 printf("\niQueue[iQueueFront] : %d, iStack[iStackPointer]: %d",iQueue[iQueueFront],iStack[iStackPointer]);
    			 return (iQueueBack-iQueueFront+1);
    		}
    		
    		if(iQueue[iQueueFront]==iStack[iStackPointer]){
    	//		printf("\nmatched");
    			//printf("\niQueue[iQueueFront] : %d, iStack[iStackPointer]: %d",iQueue[iQueueFront],iStack[iStackPointer]);
    			iStackPointer--;
    			for(int i=iQueueFront;i<iQueueBack;i++){
    				iQueue[i]=iQueue[i+1];
    			}
    			iQueueBack--;
    			iUnmachedCount=0;
    		}else{
			//printf("\nunmatched");
			//printf("\niQueue[iQueueFront] : %d, iStack[iStackPointer]: %d",iQueue[iQueueFront],iStack[iStackPointer]);
			int temp = iQueue[iQueueFront];
			
			for(int i=iQueueFront;i<iQueueBack;i++){
    				iQueue[i]=iQueue[i+1];
    			}
    			
    			iQueue[iQueueBack] = temp;
    			iUnmachedCount++;
    		}	
    
    }
    
    return (iQueueBack-iQueueFront+1);
    
	
}

int main() {
    
    int iStack[MAX_SIZE];    
    int iQueue[MAX_SIZE];
    
    int iNumOfEmp;
    
    printf("Enter Number Of Employees : ");
    scanf("%d",&iNumOfEmp);
    
    printf("\nEnter types of Dhosa  for Dhasa stack ( 0 for shada and 1 for masala dhosa )     : ");
    
    for(int iStackCounter=iNumOfEmp-1;iStackCounter>=0;iStackCounter--){
    		scanf("%d",&iStack[iStackCounter]);
    }
    
   
    printf("\nEnter types of Dhosa  for employees queue ( 0 for shada and 1 for masala dhosa ) : ");
    
    for(int iQueueCounter=0;iQueueCounter<iNumOfEmp;iQueueCounter++){
    		scanf("%d",&iQueue[iQueueCounter]);
    }
    
     printf("\nAns : %d",count_unmatched_employees(iStack,iNumOfEmp-1,iQueue,iNumOfEmp-1));
    
    return 0;
}

