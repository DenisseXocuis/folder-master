#include<stdio.h>
#include<string.h>

int main(){

    char cadena[50];
    int a=0,e=0,i=0,o=0,u=0;

    printf("Contador de vocales de una cad de char");
    printf("\nIngrese la cadena: \n");
    fgets(cadena, 50,stdin); //la cadena se lee con fgets y así limita cuantos caracteres puede leer, stdin representa el teclado y cad la variable

    for(int i = 0; i < strlen(cadena); i++) //strlen limita hasta el num de caracteres de la cadena establecida
    {
        switch (cadena[i])
        {
        case 'A':
        case 'a': a++; 
            
            break;
        case 'E':
        case 'e': e++;

            break; 
        case 'I':
        case 'i': i++;

            break; 
        case 'O':
        case 'o': o++;

            break;
        case 'U':
        case 'u': u++;

            break;
        }
    }

    printf("\nA's %d\n E's %d\n I's %d\n O's %d\n U's %d\n", a,e,i,o,u);

    return 0;
    
}