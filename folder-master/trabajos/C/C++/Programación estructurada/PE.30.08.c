#include<stdio.h>
#include<math.h>


int main(){
    int m,a,c;
    printf("Ingrese el mes con formato dd/aa\n>");
    scanf("%d", & m);
    printf("Ingrese el año con formato dd/aa\n>");
    scanf("%d", & a);

    if(m == 4 || m == 6 || m == 9 || m == 11)
        c = 1;
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        c = 3;
        else 
            c = 2;

    switch (c)
    {
    case  1:
        printf("El mes tiene 30 días");

        break;

    case 2:
            if(a % 4 == 0 &&  a %100 != 0 || a % 400 == 0)
                printf("El mes tiene 28 días");
            else 
                printf("El mes tiene 29 días");
            //multiplo de 4 pero no de 100 pero si de 400, 1700, 1800 no bs
        
        break;

    case 3:
        printf("El mes tiene 31 días");

        break;

    default:
        printf("El mes no es correcto");

        break;
    }
}