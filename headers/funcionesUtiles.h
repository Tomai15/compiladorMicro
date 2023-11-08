#include "compilador.h"
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