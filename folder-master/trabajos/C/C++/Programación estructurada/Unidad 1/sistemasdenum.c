#include<stdio.h>
#include<string.h>
#define R 60
void debi(int n);
void menu();

int main(){
    int op,n,bi[R],res;
    do{
        menu();
        scanf("%d", &op);

        switch (op)
        {
            case 1: puts("Ingrese el numero decimal a convertir");
                    scanf("%d", &n); //23519
                    debi(n);
                    //printf("%d es %d en binario", n, debi(n,n2));
            break;
            case 2:
            break;
            case 3:  
            break;
            default:
                printf("ERROR: Opcion no valida\n");

        }
    }while(op);

    return 0;
}

void menu(){
    puts("\n----------------------------------------------------------------");
    puts("--Programa que hace conversiones de los sistemas de numeracion--");
    puts("----------------------------------------------------------------");
    puts("[1] Decimal a Binario"); //yo
    puts("[2] Decimal a Octal"); //karina
    puts("[3] Decimal a Hexadecimal"); //memo
    puts("[4] About");
    puts("[0] Salir");
    printf("Opcion: \n >");
}
void debi(int n){
int bi[R], i;
    for(i=0; n > 0; i++){
        bi[i] = n%2;
        n /= 2;
    }
    for(i=i-1; i>=0; i--){
        printf("%d", bi[i]);
    }
}