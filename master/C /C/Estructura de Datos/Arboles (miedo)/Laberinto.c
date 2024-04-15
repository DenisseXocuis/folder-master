#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void introduccion();
/*  Contexto
        Eres un conejo en una pradera que busca su zanahoria.
        El conejo es el punto "0" y la zanahoria "X"
 */
    //tipo de nodo base 
    typedef struct paso{
        int Conejo;
        struct paso *izquierda;
        struct paso *derecha;
    }PASO;

int main(){
    int op;
    introduccion();
    scanf("%d", &op);
    do{
        switch(op){
            case 1: //empieza el laberinto
                    int camino;
                    puts("Te encuentras en medio de dos caminos");
                    puts("Unos grandes arboles pasando un rio a tu izquierda y a tu derecha un camino totalmente desconocido");
                    puts("¿A donde decides ir?");
                    scanf("%d", &camino);
                    exit(0);
            break;

            case 2: puts("De acuerdo! Adios");
                    sleep(1);
                    puts("Solo recuerda que las verduras son necesarias para un buen desarrollo ;)");
                    exit(0);
            break;

            //por si alguien no sabe tomar decisiones como yo ;)
            case 3: system("cls || clear");
                    puts("Muy bien! Entonces te doy unos segundos para pensar ;)");
                    sleep(3);
                    puts("1");
                    sleep(1);
                    puts("2");
                    sleep(1);
                    puts("3");
                    sleep(1);
                    system("cls || clear");
                    puts("¿Eres capaz de encontrar la zanahoria?");
                    putchar('\n');
                    puts("[1]: Si, dale");
                    puts("[2]: No, al cabo ni me gustan las zanahoria");
                    puts("[3]: No se");
                    printf("Opcion: \n>");
                    scanf("%d", &op);
                    if(op == 3){
                        system("cls || clear");
                        puts("Ya te di 3 segundos para pensar, no te puedo dar mas");
                        sleep(4);
                        do{ system("cls || clear");
                            puts("¿Eres capaz de encontrar la zanahoria?");
                            putchar('\n');
                            puts("[1]: Si, dale");
                            puts("[2]: No, al cabo ni me gustan las zanahoria");
                            puts("[3]: -----");
                            printf("Opcion: \n>");
                            scanf("%d", &op);
                        }while(op!=1 && op!=2); 
                    }
                break;
        }
    }while(op == 1 || op == 2);

    return 0;
}

void introduccion(){
    system("cls || clear");
    puts("Eres un pequenio conejo en una pradera");
    sleep(3);
    puts("Un dia vas al lugar donde siempre buscas tus ricas y nutritivas zanahorias");
    sleep(4);
    puts("Sin embargo, te pierdes");
    sleep(5);
    puts(":(");
    sleep(3);
    puts("¿Eres capaz de encontrar la zanahoria?");
    putchar('\n');
    puts("[1]: Si, dale");
    puts("[2]: No, al cabo ni me gustan las zanahorias");
    puts("[3]: No se");
    printf("Opcion: \n>");
}