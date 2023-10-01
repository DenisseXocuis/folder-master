/*Funciones sin retorno y sin parámetros
Funciones con retorno y con parámetros*/
//PARÁMETRO POR VALOR
#include<stdio.h>

/*declaración de funciones prototipo*/
//las funciones sirven para dar mejor visibilidad al código
void menu();
int suma(int x, int y);
int resta(int x, int y);
int mult(int x, int y);
float div(int x, int y);
int mod(int x, int y);
int pot(int x, int y);

int main(){

    int op,a,b,r;
    float rf;
    do{
        menu(); //llamado de la función
        scanf("%d", &op);
        switch(op){
            case 1: puts("Ingresa dos numeros");
                    scanf("%d %d", &a, &b);
                    printf("La suma de %d + %d es %d \n",a,b, suma(a,b));
            break;
            case 2: puts("Ingresa dos numeros");
                    scanf("%d %d", &a, &b);
                    printf("La resta de %d - %d es %d \n",a,b, resta(a,b));
            break;
            case 3: puts("Ingresa dos numeros");
                    scanf("%d %d", &a, &b);
                    printf("La multiplicación de %d * %d es %d \n", a,b, mult(a,b));
            break;
            case 4: puts("Ingresa dos numeros");
                    scanf("%d %d", &a, &b);
                    printf("La división de %d / %d es %g \n", a,b, div(a,b));
            break;
            case 5: puts("Ingresa dos numeros");
                    scanf("%d %d", &a, &b);
                    printf("El residuo de %d mod %d es %d \n", a,b,mod(a,b));
            break;
            case 6: puts("Ingresa la base y el exponente");
                    scanf("%d %d", &a, &b);
                    printf("La potencia de %d ^ %d es %d \n", a,b,pot(a,b));
            break;
            case 0: puts("Saliendo......");
                break;
            default: printf("ERROR: Opcion no valida");
        }
    }while(op);
    return 0;
}

//menu de inicio
void menu(){
    puts("\n----------------------------------------------------");
    puts("-----Programa que realiza operaciones aritmeticas-----");
    puts("------------------------------------------------------");
    puts("[1] Suma");
    puts("[2] Resta");
    puts("[3] Multiplicacion");
    puts("[4] Division");
    puts("[5] Modulo");
    puts("[6] Potencia"); //sin usar función pow
    puts("[0] Salir");
    printf("Opcion: \n >");
}

//suma
int suma(int x, int y){
    //z = variable local de la función 
    return x+y; 
}

int resta(int x, int y){
    return x-y;
}

int mult(int x,int y){
    return x*y;
}

float div(int x, int y){
    return (float)x/y; //el retorno lo pone como flotante
}

int mod(int x, int y){
    return x%y;
}
//potencia
int pot(int x, int y){
    int z=1;
    for (int i=0; i<y; i++)
    {
        z*=x;
    }
    return z;
}

