#include "stdio.h"
#include "stdlib.h"

void printcad(char *cad)
{
	while (*cad != '\0')
	{
		printf("%c",*cad);
		cad ++;
	}
	printf("\n");
}

void printcad2(char *cad)
{
	int i = 0;
	while (cad[i] != '\0')
	{
		printf("%c",cad[i]);
		i++;
	}
	printf("\n");
}

void printcad_recur(char *cad)
{
	if (*cad == '\0')
	{
		printf("\n");
		return;
	}
	printf("%c", *cad);
	printcad_recur(++cad);


}

void printcad_recur2(char **cad)
{
	if (*(*cad) == '\0')
	{
		printf("\n");
		return;
	}
	printf("%c", **cad);
	//++*cad;
	printcad_recur2(cad);


}
int main(int argc, char const *argv[])
{
	
	char cad[] = "hola a todos";

	printf("cadena: %s\n",cad);

	char *mi_apun;

	mi_apun = cad;

	printf("apuntador: %s\n",mi_apun);

	printcad_recur(mi_apun);

	printf("%s\n",mi_apun);

	printcad_recur2(&mi_apun);

	return 0;
}