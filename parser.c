#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <scanner.c>

/* -------------- PROCEDIMIENTOS DE ANALISIS SINTACTICO (PAS) -------------- */
void Objetivo(void)
{
    /* <objetivo> -> <programa> FDT #terminar */
    Programa();
    Match(FDT);
    printf("compilacion terminada /n");
}

void Programa(void)
{
    /* <programa> -> #comenzar INICIO <listaSentencias> FIN */
    printf("Inicio de proceso de compilacion /n");
    Match(INICIO);
    ListaSentencias();
    Match(FIN);
}

void ListaSentencias(void)
{
    /* <listaSentencias> -> <sentencia> {<sentencia>} */
    Sentencia();
    while ( 1 )
    {
        switch ( ProximoToken() )
        {
        case ID : case LEER : case ESCRIBIR :
            Sentencia();
            break;
        default : return;
        }
    }
}
