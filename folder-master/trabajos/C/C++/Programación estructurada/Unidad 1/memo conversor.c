#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define T 256

//Funciones prototipo para menú
void menu();
void error();
void salir();
void info();
void pausa();

//Funciones prototipo para calculo
void dec_bin(int n);
void dec_oct(int n);
void dec_hex(int n);
void bin_dec(int n);
void hex_dec(char hex_n[T]);

int main(){
    int opc, n;
    char hex_n[T];
    do{
        menu();
        scanf("%d", &opc);

        switch (opc){
        case 1:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_bin(n);
            pausa();
        break;
        case 2:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_oct(n);
            pausa();
            break;

        case 3:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_hex(n);
            pausa();
        break;
        case 4:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            bin_dec(n);
            pausa();

        break;
        case 5:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            //karina's code 
            pausa();
        break;
        case 6:
            puts("Ingrese el numero a convertir");
            scanf("%s", &hex_n);
            hex_dec(hex_n);
            pausa();
        break;
        case 7:
            info();
        break;
        case 0:
            salir();
        break;
        default:
            error();
        }
    } while (opc);
    
return 0;
}

void menu(){
    system("clear||cls");
    puts("------------------------------------------------------");
    puts("-------CONVERSOR DE DIVERSOS SISTEMAS NUMERICOS-------");
    puts("------------------------------------------------------");
    puts("[1] Convertir de Decimal --> Binario");
    puts("[2] Convertir de Decimal --> Octal");
    puts("[3] Convertir de Decimal --> Hexadecimal");
    puts("[4] Convertir de Binario --> Decimal");
    puts("[5] Convertir de Octal   --> Decimal");
    puts("[6] Convertir de Hexadecimal --> Decimal");
    puts("[7] Acerca de...");
    puts("[0] Salir...");
    printf("Seleccione una opción....  \n>");
}

void error(){
    puts("-------------------");
    puts("--OPCIÓN INVALIDA--");
    puts("-------------------");
    pausa();
}

void salir(){
    puts("---------------------");
    puts("--CERRANDO PROGRAMA--");
    puts("---------------------");
}

void info(){
    system("clear||cls");
    puts("------------------------------------------------------");
    puts("-------CONVERSOR DE DIVERSOS SISTEMAS NUMERICOS-------");
    puts("------------------------------------------------------");
    puts("C. Ing. Martha Denisse Lara Xocuis");
    puts("C. Ing. Guillermo Francisco Themsel Montes");
    puts("C. Ing. Karina Arlet Xalanda Coyolt");
    puts("Ingeniería Informatica");
    puts("Versión 0.6");
    puts("© 2023");
    pausa();
}

void pausa(){
    printf("Presione cualquier tecla para continuar . . . ");
    fflush(stdin);
    getchar();
}

void dec_bin(int n){
int R[T], i;
    for(i=0; n > 0; i++){
        R[i] = n%2;
        n /= 2;
    }

    //Imprime el resultado
    printf("El valor binario es: ");
    for(i-=1; i>=0; i--)
        printf("%d", R[i]);
    putchar('\n');
}

void dec_oct(int n){ 
int R[T], i;
	//Se ejectua la función siempre y cuando decimal sea mayor o igual que 8
	for(i=0; n > 0; i++){
		R[i] = n%8;
		n /= 8;
	} 

    //Imprime el resultado
	printf("El valor octal es: ");
	for(i-=1; i>=0; i--)
	    printf("%d", R[i]);
    putchar('\n');
}

void dec_hex(int n){
    //Definición de i, temporal y Resultado
    int i=0, t;
    char R[T];

    //Se ejecuta la función siempre y cuando n no sea 0
    while (n){
        //Se calcula el modulo de n respecto a 16 y se guarda temporalmente
        t=n%16;
            /* Si t es menor a 10, entonces se le suma 48
            Puede ser un valor entre 48 y 57, que corresponden a los ASCII para numeros */
            if (t<10)
                t+=48;
            /* Sino, suma 55
            El valor puede ser entre 65 y 70, que corresponden a los ASCII para A a F */
            else
                t=t+55;
    //Guarda el resultado en un arreglo y divide n entre 16 para continuar
        R[i]=t;
        n/=16;
        i++;
    }
    //Imprime el resultado
    printf("El valor hexadecimal es: ");
    for (i-=1; i>=0; i--)
    printf("%c", R[i]);
    putchar('\n');
}

void bin_dec(int n){
int R=0,i;
for(int i=1;n != '\0'; i*=2){
    R += (n%10) * i;
    n /= 10;
}
    printf("El valor decimal es: %d \n", R);
}
