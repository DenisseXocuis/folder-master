#include<stdio.h>
#include<string.h>
#define MAX 10

int main(){
   char s1[MAX] = "Agua", s2[MAX] = "uhxl";
   system("cls || clear");
   printf("s1 = \"%s\" \n", s1);
   printf("s2 = \"%s\" \n", s2);
   printf("strcspn(s1,s2) = %d \n", strcspn(s1,s2));

   return 0;
}