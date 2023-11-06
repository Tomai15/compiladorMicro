#include "headers/superH.h"

extern int flagToken;
extern TOKEN tokenActual;
extern char buffer[];
extern TOKEN tokenActual;
extern int flagToken;

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

void ErrorLexico()
{
    printf("\033[33mError Lexico\033[37m\n");
    fprintf(out, "Error Lexico\n");
    
}

void ErrorSintactico()
{
    printf("\033[31mError Sintactico\033[37m\n");
    fprintf(out, "Error Sintactico\n");
}

void Generar(char * accion, char * a, char * b, char * c)
{
    /* Produce la salida de la instruccion para la MV por stdout */
    printf("\033[34m%s\033[37m %s%c%s%c%s\n", accion, a, ',', b, ',', c);
    fprintf(out,"%s %s%c%s%c%s\n", accion, a, ',', b, ',', c );
}

char * Extraer(REG_EXPRESION * preg)
{
    /* Retorna la cadena del registro semantico */
    return preg->nombre;
}


int BuscarEnLaTS(char * id, TOKEN * t)
{
    int i = 0;
    while ( strcmp("$", TS[i].identificadorDeLexema) )
    {
        if ( !strcmp(id, TS[i].identificadorDeLexema) )
        {
            *t = TS[i].t;
            return 1;
        }
        i++;
    }
    return 0; 
}

void ColocarEnTS(char * id)
{
    /* Agrega un identificador a la TS */
    int i = 4;
    while ( strcmp("$", TS[i].identificadorDeLexema) ) i++;
    {
        if ( i < 999 )
        {
            strcpy(TS[i].identificadorDeLexema, id );
            TS[i].t = ID;
            strcpy(TS[++i].identificadorDeLexema, "$" );
        }
    }
}

void ChequearEnLaTablaDeSimbolos(char * s)
{
    /* Si la cadena No esta en la Tabla de Simbolos la agrega,y si es el nombre de una variable genera la instruccion */
    TOKEN t;
    if ( !Buscar(s, &t) )
    {
        Colocar(s);
        Generar("Declara", s, "Entera", "");
    }
}

void Comenzar(void)
{
    /* Inicializaciones Semanticas */
    printf("\033[30mInicio de la compilacion\033[37m\n");
    fprintf(out,"Inicio de  la compilacion\n");
}

void Terminar(void)
{
    /* Genera la instruccion para terminar la ejecucion del programa */
    printf("\033[30mFinalizacion de la compilacion\033[37m\n");
    fprintf(out,"Finalizacion de la compilacion\n");
}

void Asignar(REG_EXPRESION izq, REG_EXPRESION der)
{
    /* Genera la instruccion para la asignacion */
    Generar("Almacena", Extraer(&der), izq.nombre, "");
}