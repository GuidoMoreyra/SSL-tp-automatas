#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    int eleccion=0;

    while(eleccion!=3)
        {
        printf("1.Realizar Operacion\n2.Verificar Cadena\n3.Salir");
        scanf("%d",&eleccion);
        switch(eleccion)
        {
            case 1: Cuenta(); break;
            case 2: Automata(); break;
            default : printf("Opcion Invalida"); break;
            }
        }
    return 0;
}




