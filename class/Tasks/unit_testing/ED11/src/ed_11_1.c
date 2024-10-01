#include "ed_11_1.h"
#define MAX_SIZE 100
#include<stdio.h>
int count_unmatched_employees(int iStack[], int iStack_size, int iQueue[], int iQueue_size){
    
    int iQueueFront=0;
    int iQueueBack=iQueue_size;
    int iStackPointer=iStack_size;
    int iUnmachedCount=0;
    
    int start = 0;
    int end = iStack_size;
    while (start < end) {
        int temp = iStack[start];
        iStack[start] = iStack[end];
        iStack[end] = temp;
        start++;
        end--;
    }
    
    
    while(iQueueFront<=iQueueBack){
    
    		//printf("\niQueueFront : %d , iQueueBack : %d , iStackPointer : %d ",iQueueFront,iQueueBack,iStackPointer);
    		
    		if(iUnmachedCount==(iQueueBack-iQueueFront+1)){
    			// printf("\niUnmachedCount");
    			 return (iQueueBack-iQueueFront+1);
    		}
    		
    		if(iQueue[iQueueFront]==iStack[iStackPointer]){
    			//printf("\nmatched");
    			iStackPointer--;
    			for(int i=iQueueFront;i<iQueueBack;i++){
    				iQueue[i]=iQueue[i+1];
    			}
    			iQueueBack--;
    			iUnmachedCount=0;
    		}else{
			//("\nunmatched");
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
