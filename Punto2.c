#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
long convertirANumero(char* caracteres) //Convierte un STRING de numeros en LONG , no debe haber otros caracteres en el STRING
{
    int aux=0;
    int index=0;
    int longitud=strlen(caracteres);

    for(index=0;index<longitud;index++)
        {

            aux = aux * 10 + (caracteres[index] - '0');
        }

        return aux;
}
