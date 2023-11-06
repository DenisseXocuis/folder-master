#include<stdio.h>
#include<string.h>
//diferencia de strcat y strncat
#define MAX 20

int main(){
    char s1[MAX], s2[MAX];
    system("cls || clear");
    puts("Ingresa una cadena");
    scanf("%s ", s1);
    puts("Ingresa otra cadena");
    scanf("%s", s2);
    printf("con strcat: \"%s\"\n", strcat(s1,s2));
    printf("con strncat: \"%s\"", strncat(s1,s2,1));

    return 0;
}


