#include <stdio.h>
#include <stdlib.h>
#define N 4

int top=-1, arr[N];

void push(){
    int x;
    if (top == N - 1)
        printf("Overflow!\n");
    else{
        printf("Ingrese el elemento a ser ingresado en la pila: \n>");
        scanf("%d", &x);
        top = top + 1;
        arr[top] = x;
    }
}

int pop(){
    if (top == -1)
        printf("Underflow!\n");
    else{
        top = top - 1;
        return arr[top+1];
    }
    return '\0';
}

void show(){
    if (top == -1)
        printf("Underflow!\n");
    else{
        printf("Elementos presentes en la pila: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", arr[i]);
    }
}

void clear(){
    system("clear||cls");
}

int main(){
    int opc=0, popped='\0';
    while (opc!=9){
        printf("~~~REALIZAR OPERACIONES EN LA PILA~~~\n");
        printf("1. Push\n2. Pop\n3. Show\n9. Salir\n");
        printf("Seleccione una opción:\n>");
        scanf("%d", &opc);

        switch (opc){
        case 1:
            clear();
            push();
            break;
        case 2:
            clear();
            popped=pop();
            if(popped)
                printf("Elemento retirado: %d\n",popped);
            break;
        case 3:
            clear();
            show();
            break;
        case 9:
            printf("Saliendo...\n");
            break;
        default:
            clear();
            printf("Opción invalida!\n");
        }
    }
    return 0;
}