#include <stdio.h>
#include <stdlib.h>

const char MAS= '+';
const char POR= '*';
const char ENTRE='/';
const char MENOS='-';

struct Nodo {
    char signo;
    char cadena[100];
    struct Nodo *sgte;
};

void agregar(struct Nodo **head_ref, char signo, const char* cadena);
void dividirArray(struct Nodo**lista, char* cadena);
long convertirANumero(char* caracteres);
long realizarOperaciones(long numero1 , long numero2 , char operacion);
long operarTermino(char * termino);
int obtenerSigno(char signo);
long sumarTerminos(struct Nodo* lista);

int main()
{
    struct Nodo* nodo = NULL;
    char linea[1000000];
    scanf("%s",linea);
    dividirArray(&nodo,linea);
    long resultado=sumarTerminos(nodo);
    printf("\nEl Resultado es %d",resultado);
    return 0;
}

void agregar(struct Nodo **head_ref, char signo, const char* cadena) {
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->signo = signo;
    strncpy(nuevoNodo->cadena, cadena, sizeof(nuevoNodo->cadena) - 1);
    nuevoNodo->cadena[sizeof(nuevoNodo->cadena) - 1] = '\0';
    nuevoNodo->sgte = NULL;
    if (*head_ref == NULL) {
        *head_ref = nuevoNodo;
        return;
    }
    struct Nodo* ultimo = *head_ref;
    while (ultimo->sgte != NULL) {
        ultimo = ultimo->sgte;
    }
    ultimo->sgte = nuevoNodo;
}

void dividirArray(struct Nodo**lista, char* cadena)//Divide la operacion y guarda cada termino en una lista
{
    int index=0;
    int aux=0;
    char cadenaAux[100];
    char memoria=MAS;
    while(cadena[index]!='\0')
        {
            if(cadena[index]==MAS || cadena[index]==MENOS)
                {

                    strncpy(cadenaAux,cadena,index);
                    cadenaAux[index] = '\0';
                    agregar(lista,memoria,cadenaAux);
                    memoria=cadena[index];
                    cadena+=index+1;
                    aux+=index;
                    index=-1;
                }
            index++;
        }
    index=0;
    agregar(lista,memoria,cadena);

}

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

long realizarOperaciones(long numero1 , long numero2 , char operacion)//Realiza la operacion dado 2 numeros y la operacion elegida
{

    switch(operacion)
    {
        case 'F': return numero2; break;
        case '/': if(numero2!=0){return numero1 / numero2;} else {return 0;} break;
        case '*': return numero1 * numero2; break;
    }
}

long operarTermino(char * termino)//Va buscando y realizando las operaciones de Izquierda a derecha
{
    char aux_Cadena[50];
    long PrimeraPosicion=1,SegundaPosicion=1;
    int index=0,posicion=0;
    char memoria='F';
    while(termino[index]!='\0')
      while(termino[index]!='\0'){
            if(termino[index]==POR || termino[index]==ENTRE)
                {
                    memoria=termino[index];
                    strncpy(aux_Cadena,termino,index);
                    aux_Cadena[index]='\0';
                    PrimeraPosicion=SegundaPosicion;
                    SegundaPosicion=convertirANumero(aux_Cadena);
                    posicion++;
                    termino+=index+1;
                    index=-1;
                    if(posicion==2){SegundaPosicion=realizarOperaciones(PrimeraPosicion,SegundaPosicion,memoria);}
                }
            index++;
        }
    long aux=convertirANumero(termino);

    if(termino!='\0'){SegundaPosicion=realizarOperaciones(SegundaPosicion,aux,memoria);}

    return SegundaPosicion;
}

int obtenerSigno(char signo){
    if (signo==MAS){
        return 1; 
    } else {
        return -1; 
    }
}

long sumarTerminos(struct Nodo* lista)
{
    long resultado=0;
    while(lista!=NULL)
        {

            resultado= resultado + operarTermino(lista->cadena)*obtenerSigno(lista->signo);

            lista=lista->sgte;
        }
    return resultado;
}
