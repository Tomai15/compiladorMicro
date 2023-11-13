#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TablaDeSimbolos.h"


SIMBOLO TS[TAMANIO_TS]; 

// Inicializa cada elemento en la tabla de símbolos TS estableciendo el campo val en -1.
void inicializar_TS(){
    for(int i=0; i < TAMANIO_TS;  i++){
        TS[i].valor = -1;
    }
}

// Retorna valor de un ID si está en la TS, de lo contrario termina el programa
int valor_simbolo(char* id){
    int indice = indice_TS(id);
    if (indice < 0){
        printf("Error: No hay valor asignado para '%s'\n",id);
        exit(EXIT_FAILURE);
    }
    return TS[indice].valor;
}

// Retorna el índice de un ID si está, o -1 si no
int indice_TS(char* id){
    for (int i = 0; i < TAMANIO_TS; i++){
        if (!strcmp(TS[i].id, id)){
             return i;
        }
    }
    return -1;
}

// Si el simbolo a escribir ya está en la tabla lo actualiza, si no, crea una entrada nueva
void escribir_en_TS(char* s, int v){
    int indice = indice_TS(s);
    
    // No está en la TS
    if (indice == -1){
        int i=0;
        for (i; (i < TAMANIO_TS && TS[i].valor != -1); i++){ // busca la primera entrada vacía

            if (i > TAMANIO_TS-1){
                printf("No hay mas espacio en la TS.\n");
                return;
            }
        }
        sprintf(TS[i].id, s);
        TS[i].valor = v;
    }

    else
        TS[indice].valor = v;
}

// Para la estructura Leer(IDs);

// Retorna el número que representa si la cadena es numérica, o -1 caso contrario
static int numerico(char* s){
    for(int i=0; i<strlen(s); i++)
        if (!isdigit(s[i])) return -1;
    return atoi(s);
}

// Va asignando a cada entrada leida con Leer(IDs); el valor y después se escribe a la tabla
// Si se intenta asignar un dato no numerico, tira error
void cargar_entradas(char* p1){
    int valor;
    char temp[15];
    printf("Ingresa el valor de %s: ", p1);
    fscanf(stdin, "%s", temp);

    if((valor = numerico(temp)) == -1){
        printf("Error: El valor '%s' no es un numero\n", temp);
        exit(EXIT_FAILURE);
    }
    escribir_en_TS(p1, valor);
}