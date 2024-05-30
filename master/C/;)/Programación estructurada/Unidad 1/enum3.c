#include <stdio.h>
void menu();
enum operaciones{
    SUMA=1, RESTA, MULTIPLICACION, DIVISION,
}op;

int main() {
    double num1, num2;
    menu();
    scanf("%d", &op);

    printf("Ingresa dos números: ");
    scanf("%lf %lf", &num1, &num2);

    switch (op) {
        case 1:
            printf("Resultado: %.2lf\n", num1 + num2);
            break;
        case 2:
            printf("Resultado: %.2lf\n", num1 - num2);
            break;
        case 3:
            printf("Resultado: %.2lf\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Resultado: %.2lf\n", num1 / num2);
            } else {
                puts("ERROR: No se puede dividir entre cero");
            }
            break;
        default:
            printf("ERROR: Opción no válida");
            return 1;
    }
    return 0;
}
void menu(){
    puts("Elige una opción:");
    puts("1. Suma");
    puts("2. Resta");
    puts("3. Multiplicación");
    puts("4. División");
    printf("Opción: \n>");
}



