#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "headers/rSemanticas.h"
#include "headers/fAuxs.h"

extern char buffer[];

/* -------------------  RUTINAS SEMANTICAS  ------------------- */
REG_EXPRESION ProcesarCte(void)
{
    /* Convierte cadena que representa numero a numero entero y construye un registro semantico */
    REG_EXPRESION reg;
    reg.clase = CONSTANTE;
    strcpy(reg.nombre, buffer);
    sscanf(buffer, "%d", &reg.valor);
    return reg;
}

REG_EXPRESION ProcesarId(void)
{
    /* Declara ID y construye el correspondiente registro semantico */
    REG_EXPRESION reg;
    Chequear(buffer);
    reg.clase = ID;
    strcpy(reg.nombre, buffer);
    return reg;
}

char * ProcesarOp(void)
{
    /* Declara OP y construye el correspondiente registro semantico */
    return buffer;
}

void Leer(REG_EXPRESION in)
{
    /* Genera la instruccion para leer */
    Generar("Read", in.nombre, "Entera", "");
}

void Escribir(REG_EXPRESION out)
{
    /* Genera la instruccion para escribir */
    Generar("Write", Extraer(&out), "Entera", "");
}

REG_EXPRESION GenInfijo(REG_EXPRESION e1, char * op, REG_EXPRESION e2)
{
/* Genera la instruccion para una operacion infija y construye un registro semantico con el resultado */
    REG_EXPRESION reg;
    static unsigned int numTemp = 1;
    char cadTemp[TamanioNombreLexema] ="Temp&";
    char cadNum[TamanioNombreLexema];
    char cadOp[TamanioNombreLexema];
    if ( op[0] == '-' ) strcpy(cadOp, "Restar");
    if ( op[0] == '+' ) strcpy(cadOp, "Sumar");
    sprintf(cadNum, "%d", numTemp);
    numTemp++;
    strcat(cadTemp, cadNum);
    if ( e1.clase == ID) Chequear(Extraer(&e1));
    if ( e2.clase == ID) Chequear(Extraer(&e2));
    Chequear(cadTemp);
    Generar(cadOp, Extraer(&e1), Extraer(&e2), cadTemp);
    strcpy(reg.nombre, cadTemp);
    return reg;
}