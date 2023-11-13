#ifndef TABLA_DE_SIMBOLOS
#define TABLA_DE_SIMBOLOS

#define TAMANIO_TS 100 //arbitrario

typedef struct {
    char id[32]; 
    int valor;
} SIMBOLO;

void inicializar_TS();
int valor_simbolo(char* id);
int indice_TS(char* id);
void escribir_en_TS(char* s, int v);
void cargar_entradas(char* p1); // para Leer(IDs);
static int numerico(char* s);


#endif