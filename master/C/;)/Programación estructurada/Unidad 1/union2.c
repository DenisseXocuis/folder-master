#include <stdio.h>

union var{
    int e;
    float f;
};

struct estruc{
    int tipo;
    union var u;
};

int main() {
    struct estruc s;
    s.tipo = 1;
    s.u.e = 42;

    struct estruc s2;
    s2.tipo = 2;
    s2.u.f = 3.14;

    printf("Estructura 1 : Tipo %d, Valor %f\n", s.tipo, s.u.e);
    printf("Estructura 2 : Tipo %d, Valor %d\n", s2.tipo, s2.u.f);

    return 0;
}



