%{
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TablaDeSimbolos.h"

void yyerror(char *s);

extern int yynerrs;
extern int yylexerrs;
extern FILE* yyin;

%}

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA PARENDERECHO PARENIZQUIERDO COMA
%token <id> ID
%token <cte> CONSTANTE
%union {
    char* id;
    int cte;
}
%left SUMA RESTA
%right ASIGNACION

%type <cte> expresion primaria

%%
programa:
    INICIO listaSentencias FIN {
        if (yynerrs || yylexerrs) YYABORT;
        return -1;
    }
;

listaSentencias:
       sentencia
    |  listaSentencias sentencia
;

sentencia:
       ID ASIGNACION expresion PUNTOYCOMA               {escribir_en_TS($1, $3);}         
    |  LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA     
    |  ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA
;

listaIdentificadores:
       ID                               {cargar_entradas($1);}                                                   
    |  listaIdentificadores COMA ID      {cargar_entradas($3);}
;

listaExpresiones:
       expresion                        {printf("%d\n", $1);}
    |  listaExpresiones COMA expresion   {printf("%d\n", $3);}
;

expresion:
       primaria                          {$$ = $1;}
    |  expresion SUMA primaria            {$$ = $1 + $3;}
    |  expresion RESTA primaria            {$$ = $1 - $3;}                    
;


primaria:
       ID                               {$$ = valor_simbolo($1);}
    |  CONSTANTE                        {$$ = $1;}
    |  PARENIZQUIERDO expresion PARENDERECHO                {$$ = $2;}
;

%%

int yylexerrs = 0;

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

////// MAIN //////
int main(int argc, char** argv) {
    
    // Argumentos
    if (argc > 2){
        printf("Numero incorrecto de argumentos.");
        return EXIT_FAILURE;
    }
    else if (argc == 2) {
        char filename[50];                  // Nombre del archivo
        sprintf(filename, "%s", argv[1]);   // El 2do argumento
        int largo = strlen(filename);       // Largo del nombre del archivo

        // Si no termina en .m dar error
        if (argv[1][largo-1] != 'm' || argv[1][largo-2] != '.'){
            printf("Extension incorrecta (debe ser .m)");
            return EXIT_FAILURE;
        }

        yyin = fopen(filename, "r");
    }
    else
        yyin = stdin;

    inicializar_TS(); // Inicializa la tabla con todo en -1

    // Parser
    switch (yyparse()){
        case 0: printf("\n\nProceso de compilacion termino exitosamente");
        break;
        case 1: printf("\n\nErrores de compilacion");
        break;
        case 2: printf("\n\nNo hay memoria suficiente");
        break;
    }
    printf("\n\nErrores sintacticos: %i\tErrores lexicos: %i\n", yynerrs, yylexerrs);

    return 0;
}
