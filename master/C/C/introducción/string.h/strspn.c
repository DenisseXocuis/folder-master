#include <stdio.h>
#include <string.h>
 
int main(){
    char *s1 = "restaurante", *ch = "eut";
    int cmp;
    system("cls || clear");
    cmp = strspn(s1, ch);
    printf("Los caracteres %s se encuentran en: %s", ch, s1);

    return 0;
}
