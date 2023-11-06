#include <stdio.h>

enum dias{
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO,
}hoy;

int main() {
    hoy = VIERNES;

    switch (hoy) {
        case LUNES:
            printf("Hoy es lunes.\n");
            break;
        case MARTES:
            printf("Hoy es martes.\n");
            break;
        case MIERCOLES:
            printf("Hoy es miércoles.\n");
            break;
        case JUEVES:
            printf("Hoy es jueves.\n");
            break;
        case VIERNES:
            printf("Hoy es viernes.\n");
            break;
        case SABADO:
            printf("Hoy es sábado.\n");
            break;
        case DOMINGO:
            printf("Hoy es domingo.\n");
            break;
        default:
            printf("Día no válido.\n");
            break;
    }

    return 0;
}



