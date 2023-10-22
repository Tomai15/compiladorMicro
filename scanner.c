#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <compilador.c>

TOKEN scanner()
{
int tabla[15][13] = { 
                        {  1,  3,  5,  6,  7,  8,  9, 10, 11, 14, 13,  0, 14 },
 				        {  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2 },
 				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        {  4,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 12, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
				        { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 } 
                    };
int caracter;
int columna ;
int estado = 0;
int i = 0;
do
{
    caracter = fgetc(archivo);
    columna = fColumna(caracter);
    estado = tabla[estado][columna];
    if ( columna != 11 )
    {
        buffer[i] = caracter;
        i++;
    } 
} while ( !estadoFinal(estado) && !(estado == 14) );

buffer[i] = '\0';
switch ( estado )
{
    case 2 : 
    if ( columna != 11 )
    {
	    ungetc(caracter, archivo);
	    buffer[i-1] = '\0';
    }
   	return ID;
    
    case 4 : 
    if ( columna != 11 )
    {
	    ungetc(caracter, archivo);
	    buffer[i-1] = '\0';
	}
    return CONSTANTE;
  
    case 5 : return SUMA;
    case 6 : return RESTA;
    case 7 : return PARENIZQUIERDO;
    case 8 : return PARENDERECHO;
    case 9 : return COMA;
    case 10 : return PUNTOYCOMA;
    case 12 : return ASIGNACION;
    case 13 : return FDT;
    case 14 : return ERRORLEXICO;
}
return 0;
}


int estadoFinal(int e)
{
 if ( e == 0 || e == 1 || e == 3 || e == 11 || e == 14 ) return 0;
 return 1;
}

int fColumna(int c)
{
    if ( isalpha(c) ) return 0;
    if ( isdigit(c) ) return 1;
    if ( c == '+' ) return 2;
    if ( c == '-' ) return 3;
    if ( c == '(' ) return 4;
    if ( c == ')' ) return 5;
    if ( c == ',' ) return 6;
    if ( c == ';' ) return 7;
    if ( c == ':' ) return 8;
    if ( c == '=' ) return 9;
    if ( c == EOF ) return 10;
    if ( isspace(c) ) return 11;
    return 12;
}