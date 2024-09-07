#include <stdio.h>

int main() {
    int x, y;


    x = 5;
    printf("1->---------------\n");
    printf("   x   : %d\n", x);            
    printf("   (x < 10 ? x : 10) = %d\n", x < 10 ? x : 10); 

 
    x = 5;
    printf("\n2->---------------\n");
    printf("   x   : %d\n", x);           
    printf("   (x++ < 10 ? x++ : 10) = %d\n", x++ < 10 ? x++ : 10);
    printf("   x   : %d\n", x);                


    x = 5;
    printf("\n3->---------------\n");
    printf("   x   : %d\n", x);            
    printf("   (++x < 10 ? ++x : 10) = %d\n", ++x < 10 ? ++x : 10); 
    printf("   x   : %d\n", x);                


    x = 5;
    printf("\n4->---------------\n");
    printf("   x   : %d\n", x);            
    printf("   (x-- > 0 ? x-- : 0) = %d\n", x-- > 0 ? x-- : 0); 
    printf("   x   : %d\n", x);                


    x = 5;
    printf("\n5->---------------\n");
    printf("   x   : %d\n", x);           
    printf("   (--x > 0 ? --x : 0) = %d\n", --x > 0 ? --x : 0); 
    printf("   x   : %d\n", x);                


    x = 5; y = 10;
    printf("\n6->---------------\n");
    printf("   x   : %d, y : %d\n", x, y);
    printf("   (x++ < y ? ++x : --y) = %d\n", x++ < y ? ++x : --y); 
    printf("   x   : %d, y : %d\n", x, y);    


    x = 5; y = 10;
    printf("\n7->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   (++x < y-- ? x++ : --y) = %d\n", ++x < y-- ? x++ : --y); 
    printf("   x   : %d, y : %d\n", x, y);    


    x = 5;
    y = 10;
    printf("\n8->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   x++ < y ? ++x : y-- = %d\n", x++ < y ? ++x : y--); 
    printf("   x   : %d, y : %d\n", x, y);    


    x = 5;
    y = 5;
    printf("\n9->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   x++ < ++y ? y-- : ++x = %d\n", x++ < ++y ? y-- : ++x); 
    printf("   x   : %d, y : %d\n", x, y);    


    x = 10;
    y = 5;
    printf("\n10->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   x-- > y ? --x : ++y = %d\n", x-- > y ? --x : ++y); 
    printf("   x   : %d, y : %d\n", x, y);    


    x = 5;
    y = 10;
    printf("\n11->---------------\n");
    printf("      x   : %d, y : %d\n", x, y); 
    printf("   Combined ternary with increments and decrements: %d %d %d %d\n",
           x++, ++x, y--, --y); 
    printf("   Final x: %d, Final y: %d\n", x, y); 

    x = 4;
    y = 6;
    printf("\n12->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   (x++ < y ? ++x : x-- < y ? --y : y++) = %d\n", (x++ < y ? ++x : x-- < y ? --y : y++)); 
    printf("   x   : %d, y : %d\n", x, y);    

    x = 8;
    y = 5;
    printf("\n13->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   x-- < y ? ++y : --x = %d\n", x-- < y ? ++y : --x); 
    printf("   x   : %d, y : %d\n", x, y);   

    x = 5;
    y = 5;
    printf("\n14->---------------\n");
    printf("   x   : %d, y : %d\n", x, y); 
    printf("   x++ < y++ ? ++x : --y = %d\n", x++ < y++ ? ++x : --y); 
    printf("   x   : %d, y : %d\n", x, y);


    x = 5; y = 5;
    printf("\n15->---------------\n");
    printf("    x   : %d, y : %d\n", x, y); 
    printf("   x++ = %d, (x > y ? ++x : x--) = %d, y-- = %d, --y = %d\n", 
           x++, (x > y ? ++x : x--), y--, --y); 
    printf("   Final x: %d, Final y: %d\n", x, y); 
    
    
    
    return 0;
}

