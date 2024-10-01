#include <stdio.h>
#include <ctype.h>

int verifica (char*);
int esPalabra(char*);


int main(){
	
	char cadena[] ="12A3456";
	
	if(!verifica (cadena))
	{
		printf("Hay caracteres que no pertenecen al alfabeto");
	
	}else{
		printf("Todos los caracteres son validos");
	}	
	
	/*
	if(esPalabra(cadena))
	{
		printf("Es palabra del lenguaje");
	}else{
		printf("NO es palabra del lenguaje");
	}
	*/
	
	return 0;
}


int verifica(char* cadena){
	int i;
	
	for(i=0;cadena[i];i++){
		
		if(!(cadena[i]=='+'||
			 cadena[i]=='-'||
			 isdigit(cadena[i])))
		{
		return 0;	
		}
	
	}
	return 1;
	
}


int esPalabra(char*);

