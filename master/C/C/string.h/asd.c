#include <stdio.h>
#include <string.h>
 
#define SIZE 40
 
 
int main(void)
{
  char buffer1[SIZE] = "computer";
  char * ptr;
 
  ptr = strcat( buffer1, " program" );
  printf( "buffer1 = %s\n", buffer1 );
 
}