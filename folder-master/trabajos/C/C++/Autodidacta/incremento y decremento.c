#include<stdio.h>

int main(){ 

    int c = 5;

    printf("%d\n", c); /*Imprime 5*/
    printf("%d\n", c++); /*Imprime 5 y hace el posincremento*/
    printf("%d\n", c); /*Imprime 6*/

    c = 5; /*Se inicializa de nuevo*/

    printf("%d\n", c); /*Imprime 5*/
    printf("%d\n", ++c); /*Pre-incrementa y después imprime 6*/
    printf("%d\n", c); /*Imprime 6*/

    return 0;
}