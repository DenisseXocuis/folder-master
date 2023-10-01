/*Ejercicio 7: área de cuadrilátero*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iostream>
#include<wchar.h>
#include<locale.h>

using namespace std;


int main(){
	float x,y,x2,y2,x3,y3,x4,y4,AB,BC,AC,CD,DA,s,s2,A,A2,t;
	setlocale(LC_ALL, "");
	printf("Programa que calcula el área de un cuadrilátero por sus coordenadas en un plano 2D,\n");
	cout<<"Por favor asigne un valor a su primer coordenada para el punto A:\n"; cin>>x>>y;
	cout<<"Asigne un valor a la segunda coordenada para el punto B:\n"; cin>>x2>>y2;
	cout<<"Asigne un valor a la tercera coordenada para el punto C:\n"; cin>>x3>>y3;
	cout<<"Asigne un valor a la segunda coordenada para el punto D:\n"; cin>>x4>>y4;
	//////////////////////
	AB= sqrt(pow((x2-x),2)+pow((y2-y),2));
	BC= sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	AC= sqrt(pow((x3-x),2)+pow((y3-y),2));
	CD= sqrt(pow((x4-x3),2)+pow((y4-y3),2));
	DA= sqrt(pow((x-x4),2)+pow((y-y4),2));
	////////////////////////
	s= (AB+BC+AC)/2;
	s2= (CD+DA+AC)/2;
	/*áreas*/
	A= sqrt(s*(s-AB)*(s-BC)*(s-AC));
	A2= sqrt(s2*(s2-CD)*(s2-DA)*(s2-AC));
	t=A+A2;
	cout<<"El área del cuadrilátero es de:"<<t;
	return 0;
	
}