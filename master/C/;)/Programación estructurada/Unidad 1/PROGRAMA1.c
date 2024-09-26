#include<stdio.h>

void menu();
int mayor(int n);
int main(){
    int num;
    menu();
    scanf("%d", &num);
    printf("El digito mayor de %d es: %d", num , mayor(num));

    return 0;
}
void menu(){
    puts("---------------------------------------------------");
    puts("Programa que dado un numero muestra el digito mayor");
    puts("---------------------------------------------------\n");
    printf("Ingresa un numero:\n>");
}

int mayor(int n){ 
    static may = 0;
    int n1;
    if(n > 0){ 
        n1 = n%10; 
        if(n1 > may) 
            may = n1; 
        mayor(n / 10); 
    }
    else return may;
}

