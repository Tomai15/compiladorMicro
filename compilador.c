#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/compilador.h"
#include "headers/parser.h"

FILE *archivo;
FILE *out;
char buffer[32+1];
RegTS TS[1000] = { {"inicio", INICIO}, {"fin", FIN}, {"leer", LEER}, {"escribir", ESCRIBIR}, {"$", 99} };
TOKEN tokenActual;
int flagToken = 0;


int main(int argc, char** argv)
{
    if ( argc == 1 )
    {
        printf("Debe ingresar el nombre del archivo fuente (en lenguaje Micro) en la linea de comandos\n");
        return -1;
    }
    if ( argc == 2 )
    {
        printf("Numero incorrecto de argumentos\n");
        printf("Ingreso %d argumentos\n",argc);
        return -1;
    }
    
    char *nomArchi = malloc(strlen(argv[1]) * sizeof(char) + 1);
    strcpy(nomArchi, argv[1]);
    int l = strlen(nomArchi);

    if ( nomArchi[l-1] != 'm' || nomArchi[l-2] != '.' )
    {
        printf("Nombre incorrecto del Archivo Fuente\n");
        return -1;
    }
    if ( (archivo = fopen(nomArchi, "r") ) == NULL )
    {
        printf("No se pudo abrir archivo fuente\n");
        return -1;
    }
    if ( (out = fopen(argv[2], "w") ) == NULL)
	    {
	        printf("No se pudo abrir archivo de salida\n");
	        return -1;
	    }
    // Inicia el proceso de compilacion:

    Objetivo();

    // Cierro el archivo

    fclose(archivo);
    fclose(out);
}