#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 40

int main(){

    char *s3, s2[MAX], s1[MAX];

    //con apuntador
    puts("Ingresa una palabra");
    scanf("%s", s3);
    printf("%s", s3);

    //sin apuntador
    putchar('\n');
    puts("Ingresa otra palabra");
    getchar();
    gets(s2);
    puts(s2);

    //con espacios
    printf("Ingresa un nombre completo\n");
    fgets(s1, sizeof(s1), stdin);
    printf("%s", s1);


    return 0;
}