#include<stdio.h>

int main(){

    int m,a, d[4] = {30,31,28,29};

    printf("Ingresa el mes y anio en formato dd/aa \n");
    scanf("%d %d", &m,&a);

    if(m == 4 || m == 6 || m == 9 || m == 11)
        printf("\nEl mes tiene %d días", d[0]);
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        printf("\n El mes tiene %d días ", d[1]);
        else if(a % 4 == 0 &&  a %100 != 0 || a % 400 == 0)
                printf("El mes tiene %d días", d[2]);
            else
                printf("El mes tiene %d días", d[3]);
    
    return 0;
}