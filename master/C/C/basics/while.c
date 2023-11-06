#include<stdio.h>

int main()
{
    int i = 0, cal, t = 0;
    /* c: contador, cal: calificación, t: total, av: promedio*/

    while(i <=9)
    {
        printf("Ingresa calificacion\n>");
        scanf("%d", &cal);
        t += cal;  /*acumulador*/
        i += 1; /*contador*/
    }
    printf("El promedio de las calificaciones es: %d", t/i);

    
    return 0;
}