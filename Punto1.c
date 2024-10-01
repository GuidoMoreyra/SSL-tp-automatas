#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

static int tt[6][5]={
						{4,2,1,5,5},
						{4,5,5,5,5},
						{4,5,5,3,5},
						{4,5,5,5,5},
						{4,4,5,5,0},
						{5,5,5,5,5}
					};


void Automata() {
	char cadena[1000000];
	printf("\nIngrese una cadena con números separados por #: \n");
    scanf("%s", cadena);

	/*Verificamos que los caracteres existan en el alfabeto. Nos inclinamos por esta opcion
	para no complicar los casos del automata.*/
	if(!verifica(cadena)) {
		printf("\n Hay caracteres que no pertenecen al alfabeto\n");
		return 0;
	} else {
		printf("\nTodos los caracteres son válidos\n");
	}

	if(!esPalabra(cadena)) {
		printf("La cadena ingresada es palabra del lenguaje\n");

		if(cadena[0]=='\0') {
			printf("No se ingresaron números de ningún grupo\n");
		} else {
			contarGrupos(cadena);
		}
	} else {
		printf("La cadena ingresada no es palabra del lenguaje\n");
	}
	return 0;
}

int verifica(char* cadena){
	int i;
	for(i=0;cadena[i];i++){
		if(!(cadena[i]==MAS||
			 cadena[i]==MENOS||
			 cadena[i]==EQUIS||
			 cadena[i]==SEPARADOR||
			 isdigit(cadena[i])))
		{
			return 0;
		}
	}
	return 1;
}

int columna(int c) {
	if(c>=UNO && c<=NUEVE){
		return 0;
	} else if (c==CERO) {
		return 1;
	} else if (c==MAS || c==MENOS) {
		return 2;
	} else if (c==EQUIS) {
		return 3;
	} else {
		return 4;
	}
}

int esPalabra(char* cadena) {
	int estado=0; //inicializado en 0 pues es el estado inicial
	int i=0;
	int c=cadena[0];
	int ultimoCaracter=c;
	while(c!='\0') {
		estado=tt[estado][columna(c)];
		ultimoCaracter=c;
		c=cadena[++i];
	}
	if(estado!=4) {
		return 1;
	}
	return 0;
}

void contarGrupos(char *cadena) {
	int cantidadOctales=0;
	int cantidadHexadecimales=0;
	int cantidadDecimales=0;

	int estadoActual=0; //inicializado en 0 pues es el estado inicial
	int estadoAnterior=0;
	int i=0;
	int c=cadena[0];
	while(c!='\0') {
		estadoAnterior=estadoActual;
		estadoActual=tt[estadoActual][columna(c)];
		if(estadoActual==3){
			cantidadHexadecimales++;
		} else if (estadoActual==4){
			if(estadoAnterior==2) {
				cantidadOctales++;
			} else if (estadoAnterior==0 || estadoAnterior==1) {
				cantidadDecimales++;
			}
		}
		c=cadena[++i];
	}
	printf("\nLa cantidad de números ingresados de cada grupo es \n Decimales: %i \n Octales: %i \n Hexadecimales: %i", cantidadDecimales, cantidadOctales, cantidadHexadecimales);
}
