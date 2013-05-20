#include <conio.h> 

int main(void) 
{ 
   /* clear the screen */ 
   clrscr(); 

   /* create a text window */ 
   window(10, 10, 80, 25); 

   /* output some text in the window */ 
   cprintf("Hello world\r\n"); 

   /* wait for a key */ 
   getch(); 
   return 0; 
} 
