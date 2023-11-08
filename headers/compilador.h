#ifndef COMPILADOR_H_
#define COMPILADOR_H_
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
#endif