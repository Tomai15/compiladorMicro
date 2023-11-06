//compilador.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

typedef struct
{
    char identificadorDeLexema[32+1];
    TOKEN t;
} RegTS;


typedef struct
{
    TOKEN clase;
    char nombre[32+1];
    int valor;
} REG_EXPRESION;

extern FILE *archivo;
extern FILE *out;
extern char buffer[];

	//FILE * archivo;
	//FILE * out;
extern RegTS TS[1000] = { {"inicio", INICIO}, {"fin", FIN}, {"leer", LEER}, {"escribir", ESCRIBIR}, {"$", 99} };
extern char buffer[32+1];
extern TOKEN tokenActual;
extern int flagToken = 0;

//funcionesUtiles
void Match(TOKEN t);
TOKEN ProximoToken();
void ErrorLexico();
void ErrorSintactico();
void Generar(char * accion, char * a, char * b, char * c);
char * Extraer(REG_EXPRESION * preg);
int BuscarEnLaTS(char * id, TOKEN * t);
void ColocarEnTS(char * id);
void ChequearEnLaTablaDeSimbolos(char * s);
void Comenzar(void);
void Terminar(void);
void Asignar(REG_EXPRESION izq, REG_EXPRESION der);

//parser
void Objetivo(void);
REG_EXPRESION ProcesarId(void);
void Programa(void);
void ListaSentencias(void);
void Sentencia(void);
void ListaIdentificadores(void);
void Identificador(REG_EXPRESION * resultado);
void ListaExpresiones(void);
void Expresion(REG_EXPRESION * resultado);
void Primaria(REG_EXPRESION * resultado);
void OperadorAditivo(char * resultado);

//rSemanticas
REG_EXPRESION ProcesarCte(void);
REG_EXPRESION ProcesarId(void);
char * ProcesarOp(void);
void Leer(REG_EXPRESION in);
void Escribir(REG_EXPRESION out);
REG_EXPRESION GenInfijo(REG_EXPRESION e1, char * op, REG_EXPRESION e2);



//#define TamanioNombreLexema 32+1





