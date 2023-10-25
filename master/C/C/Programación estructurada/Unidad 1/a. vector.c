#include<stdio.h> //funciones con retorno de apuntador
/*Examen: */
char *textomeses(int m);

int main(){

    int mes;
    puts("Ingresa el numero del mes");
    scanf("%d", &mes);
    printf("%s", textomeses(mes));

    return 0;
}

char *textomeses(int m){
    char *meses[] = {"Mes no valido", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio","Julio" ,"Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    return((m <= 12 && m>=1) ? *(meses+m) : *meses);
} //operador external