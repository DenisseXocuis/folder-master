#include<stdio.h>

int main(){
    int n = 75;
    system("cls || clear");
    printf("n = %d\n", n);
    printf("&n = %p\n", &n);
    putchar('\n');
    {
        int num = 5, *apuntador;
        apuntador = &num;
        printf("num: %d\n&num: %p\napuntador: %d\n&apuntador: %p", num, &num,*apuntador, &apuntador);

        return 0;
    }
    return 0;
}