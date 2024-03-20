#include <stdio.h>
//memoria contigua :)
int fun(int par, int par2, int *out){
    par = 7;
    par2 =10;
    return *out = par + par2;
}

int main(){
    int par=5, par2=6, *c;
    fun(par,par2,&c);

    return 0;
}