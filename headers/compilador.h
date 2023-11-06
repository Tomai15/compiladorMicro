#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "parser.h"

typedef enum 
{ 
    INICIO, 
    FIN, 
    LEER, 
    ESCRIBIR, 
    ID, 
    CONSTANTE, 
    PARENIZQUIERDO,   
    PARENDERECHO, 
    PUNTOYCOMA, 
    COMA, 
    ASIGNACION,
    SUMA, 
    RESTA, 
    FDT,
    ERRORLEXICO 
} TOKEN; 

extern FILE *archivo;
extern char buffer[];