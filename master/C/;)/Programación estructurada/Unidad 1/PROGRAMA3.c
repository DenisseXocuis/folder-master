#include<stdio.h>
int divisores(int n, int div);
int multiplos(int,int,int);
void pausa();
void menu();

int main(){
    int num, op,a,b;
    do{
        system("clear||cls");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1: printf("Ingrese un numero: \n>");
                    scanf("%d", &num);
                    int i = num;
                    printf("La suma de los divisores de %d es: %d\n", num , divisores(num,i));
                    pausa();
            break;
            case 2: printf("Ingrese un numero: \n>");
                    scanf("%d", &num);
                    puts("Escoga el rango de multiplos a calcular (a-b)");
                    scanf("%d", &a);
                    scanf("%d", &b);
                    printf("La suma de los multiplos de %d es: %d\n", num , multiplos(num,a,b));
                    pausa();
            break;
            default: puts("Saliendo.....");
        }
    }while(op);
    

}

void menu(){
    puts("------------------------------------------------------------------------");
    puts("Programa que dado un numero muestra la suma de sus divisores o multiplos");
    puts("------------------------------------------------------------------------");
    puts("1: Suma de divisores");
    puts("2: Suma de multiplos");
    puts("0: Salir");
    printf("Ingresa una opción\n>");
}
void pausa(){
    printf("Presione cualquier tecla para continuar . . . ");
    fflush(stdin);
    getchar();
    getchar();
}
int divisores(int n , int div){
    if(div == 1)
        return 1;
    else if((n % div) == 0)
        return div + divisores(n, div-1);
    else
        return divisores(n, div-1);
}

int multiplos(int n,int inicio,int final){
    int sum = 0;
    for(int i=inicio; i<=final; i++){
        sum+= (n*i);
    }
    return sum;

}
