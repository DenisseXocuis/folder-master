#include<stdio.h>

/*Un grupo de 10 estudiantes realizó un examen. Usted tiene a su disposición las calificaciones de este examen. Determine el promedio*/

int main(){
int calf, cont=0, sum=0; /*INICIALIZA TODO AAAAAAAAAAAA*/
float prom;
for(int i = 1; i<=10; i++)
{   
    printf("Ingrese la calificación del alumno %d\n", i);
    scanf("%d", &calf);
    cont += 1;
    sum  += calf;
}
prom = sum/cont;
printf("El promedio de todos los alumnos es de: %g", prom);

return 0;

}