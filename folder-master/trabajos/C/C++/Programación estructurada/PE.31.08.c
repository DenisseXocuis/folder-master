#include<stdio.h>

int main(){
    int aI, aF;
    printf("Dime un rango de años con el formato (año inicial-año final) \n");
    scanf("%d %d", &aI, &aF);

    if(aI>aF)
        printf("ERROR: el año inicial NO puede ser mayor que el año final");
    else if(aI==aF)
        printf("ERROR: el año inicial y el año final es el mismo");
        else 
            while(aI <= aF){
                 if(aI % 4 == 0 &&  aI %100 != 0 || aI % 400 == 0)
                printf("%d \n", aI);
                aI++;

            }

    return 0;
}