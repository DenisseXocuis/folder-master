#include<stdio.h>
#include <string.h>

int main(int argc, char **argv){
  if ( argc != 2 )
    printf( "Usage: %s string\n", argv[0] );
  else
    printf( "Input string has a length of %i\n", strlen( argv[1] ));

    return 0;
}