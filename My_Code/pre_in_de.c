#include <stdio.h>

int main() {
    int x = 5, y = 5;
    
    printf("1->---------------\n");
    printf("    x   : %d\n",x);     //5
    printf("    x++ : %d\n",x++);    //5
    printf("    x   : %d\n",x);      //6
    
    x=5;
    printf("\n2->---------------\n");
    printf("\n    x   : %d\n",x);   //5
    printf("    x-- : %d\n",x--);    //5
    printf("    x   : %d\n",x);      //4
    
    
    x=5;
    printf("\n3->---------------\n");
    printf("\n    x   : %d\n",x);   //5
    printf("    ++x : %d\n",++x);    //6
    printf("    x   : %d\n",x);      //6
   
    
    x=5;
    printf("\n4->---------------\n");
    printf("\n    x   : %d\n",x);   //5
    printf("    --x : %d\n",--x);    //4
    printf("    x   : %d\n",x);      //4
    
    
    x=5;
    printf("\n5->---------------\n");
    printf("\n    x   : %d\n",x);                   //5
    printf("    x++ : %d, x-- : %d\n", x++, x--);    //5 6
    printf("    x   : %d\n",x);                      //5

    
    x=5;
    printf("\n6->---------------\n");
    printf("\n    x   : %d\n",x);                   //5
    printf("    x-- : %d, x++ : %d\n", x--, x++);    //5 5
    printf("    x   : %d\n",x);                      //5

    
    x=5;
    printf("\n7->---------------\n");
    printf("\n    x   : %d\n",x);                   //5
    printf("    ++x : %d, --x : %d\n", ++x, --x);    //6 5
    printf("    x   : %d\n",x);                      //5
 
    
    x=5;
    printf("\n8->---------------\n");
    printf("\n    x   : %d\n",x);                   //5
    printf("    --x : %d, ++x : %d\n", --x, ++x);    //4 5
    printf("    x   : %d\n",x);                      //5
    
    x=5;
    printf("\n9->---------------\n");
    printf("\n    x   : %d\n",x);                   //5
    printf("    x++ : %d, ++x : %d\n", x++, ++x);    //5 6
    printf("    x   : %d\n",x);                      //7

    
    x=5;
    printf("\n10->---------------\n");
    printf("\n    x   : %d\n",x);                  //5
    printf("    x-- : %d, --x : %d\n", x--, --x);    //5 4
    printf("    x   : %d\n",x);                      //3

    
    x=5;
    printf("\n11->---------------\n");
    printf("\n    x   : %d\n",x);                  //5
    printf("    ++x : %d, x-- : %d\n", x++, x--);    //5 5
    printf("    x   : %d\n",x);                      //5

    
    x=5;
    printf("\n12->---------------\n");
    printf("\n    x   : %d\n",x);                  //5
    printf("    x-- : %d, ++x : %d\n", x--, ++x);    //5 6    
    printf("    x   : %d\n",x);                      //5

    
    x=5;
    printf("\n13->---------------\n");
    printf("\n    x   : %d\n",x);                              //5
    printf("    x-- : %d, x : %d, ++x : %d\n", x--,x, ++x);      //5 6    
    printf("    x   : %d\n",x);                                  //5
    
    x=5;
    printf("\n14->---------------\n");
    printf("\n    x   : %d\n",x);                              //5
    printf("    x-- : %d, x : %d, ++x : %d\n", x--,x, ++x);      //5 6    
    printf("    x   : %d\n",x);                                  //5
    
    printf("\nCombined increments and decrements -> x++ : %d, ++x : %d, y-- : %d, --y : %d\n", x++, ++x, y--, --y);    //5 6 6 5
    printf("Final values: x = %d, y = %d\n", x, y); //7 3
    return 0;
}

