#include <stdio.h>
#include <string.h>
 
int main(){
   char *token, s1[] = "cadena de tokens con la funcion strtok";
   token = strtok(s1, " ");
   do{ printf("token: %s\n", token);
   }while (token = strtok(NULL, " "));

   return 0;
}


