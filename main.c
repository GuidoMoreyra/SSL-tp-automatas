#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    int eleccion=0;

    while(eleccion!=3)
        {
        printf("1.Realizar Operacion\n2.Verificar Cadena\n3.salir\n");
        scanf("%d",&eleccion);
        switch(eleccion)
        {
            case 1: system("cls");Cuenta(); break;
            case 2: system("cls");Automata(); break;
            case 3: break;
            default : system("cls");printf("Opcion Invalida\n"); break;
            }
        }
    return 0;
}




