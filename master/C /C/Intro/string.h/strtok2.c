#include <stdio.h>
#include <string.h>
 
int main(){
   char *token, s1[] = "azul,rojo,amarillo,blanco,rosa";
   token = strtok(s1, ",");
    while (token != NULL) {
        printf("token: %s\n", token);
        token = strtok(NULL, ",");
    }

   return 0;
}





