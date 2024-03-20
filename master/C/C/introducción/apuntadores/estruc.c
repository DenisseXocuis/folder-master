#include<stdio.h>

struct {
    int x,y;
}a = {1,2}, *b;

int main(){
    printf("%d\n", a.x);
    printf("%d\n", a.y);

    //apuntando a la estructura
    b = &a;
    putchar('\n');
    printf("%d\n", b->x);
    printf("%d", b->y);

    
    return 0;
}