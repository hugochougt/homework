#include <time.h> 
#include <stdio.h> 

int main(void) 
{ 
   clock_t start, end; 
   start = clock(); 

   // do something 

   end = clock(); 
   printf("The runtime was: %d ms\n", end - start); 

   return 0; 
} 

