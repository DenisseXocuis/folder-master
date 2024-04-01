#include<stdio.h>

union datos{
    char *nom, *num, *direcc;
};

struct rev{
    char *nom, *aut, *fecha;
};

main(){

    union datos u;
    struct rev s;

    printf("Imprimiendo direccion de memoria de una union\n");
    printf("Direccion de u.nom: %p\n", &u.nom);
    printf("Direccion de u.num: %p\n", &u.num);
    printf("Direccion de u.direcc: %p\n\n", &u.direcc);
    printf("Imprimiendo direccion de memoria de una estructura\n");
    printf("Direccion de s.nom: %p\n", &s.nom);
    printf("Direccion de s.aut: %p\n", &s.aut);
    printf("Direccion de s.fecha: %p\n", &s.fecha);

    return 0;
}


