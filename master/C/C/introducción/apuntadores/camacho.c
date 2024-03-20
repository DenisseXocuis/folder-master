#include<stdio.h>
#define T 30

void recursiva(char *p);

int main(){
	char p[50], *w;
	puts("Palabra: ");
	scanf("%s", p);
	w=p;
	printf("%s", w);
	while (*w)
		w++;
	recursiva(w);
	return 0;
}

void recursiva (char *p){
	if(p>=0){
		putchar(*p);
		recursiva(--p);
	}
	return 0;
}