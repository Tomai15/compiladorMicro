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

void Sentencia(void)
{
    TOKEN tok = ProximoToken();
    REG_EXPRESION izq, der;
    switch ( tok )
    {
        case ID :
            /* <sentencia>-> ID := <expresion> #asignar ; */
            Identificador(&izq);
            Match(ASIGNACION);
            Expresion(&der);
            Asignar(izq, der);
            Match(PUNTOYCOMA);
            break;
        case LEER :
            /* <sentencia> -> LEER ( <listaIdentificadores> ) */
            Match(LEER);
            Match(PARENIZQUIERDO);
            ListaIdentificadores();
            Match(PARENDERECHO);
            Match(PUNTOYCOMA);
            break;
        case ESCRIBIR :
            /* <sentencia> -> ESCRIBIR ( <listaExpresiones> ) */
            Match(ESCRIBIR);
            Match(PARENIZQUIERDO);
            ListaExpresiones();
            Match(PARENDERECHO);
            Match(PUNTOYCOMA);
            break;
        default :
            return;
    }
}