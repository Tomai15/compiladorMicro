#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <scanner.c>

extern int flagToken;
extern TOKEN tokenActual;
extern char buffer[];

void Match(TOKEN t)
{
    if ( !(t == ProximoToken()) ) ErrorSintactico();
    flagToken = 0;
}

TOKEN ProximoToken()
{
    if ( !flagToken )
    {
        tokenActual = scanner();
        if ( tokenActual == ERRORLEXICO )
        {
            printf("Ocurrio un error lexico /n");
        }
        flagToken = 1;
        if ( tokenActual == ID ) Buscar(buffer, &tokenActual);
    }
    return tokenActual;
}

int BuscarEnLaTS(char * id, TOKEN * t)
{
    // TODO : Pendiente la implementacion de la tabla de simbolos 
}

