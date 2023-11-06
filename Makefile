#COMPILADOR, HEADERS Y OBJETOS son "Variables" en el Makefile, se usan en el Detalle de Compilacion
COMPILADOR := gcc
EJECUTABLE := cMicro
HEADERS := headers/
OBJETOS := micro.o parser.o scanner.o rSemanticas.o fAuxs.o


#ALL Instruccion para compilar todo
all: Compilador_Micro refresh


# Compilador_Micro (Detalle del proceso de compilacion)
Compilador_Micro: $(OBJETOS)
	$(COMPILADOR) -o $(EJECUTABLE) $(OBJETOS)

micro.o: micro.c $(HEADERS)micro.h $(HEADERS)parser.h
	$(COMPILADOR) -c micro.c

parser.o: parser.c $(HEADERS)parser.h $(HEADERS)rSemanticas.h $(HEADERS)fAuxs.h $(HEADERS)micro.h
	$(COMPILADOR) -c parser.c

scanner.o: scanner.c $(HEADERS)scanner.h $(HEADERS)micro.h
	$(COMPILADOR) -c scanner.c

rSemanticas.o: rSemanticas.c $(HEADERS)rSemanticas.h $(HEADERS)fAuxs.h $(HEADERS)micro.h
	$(COMPILADOR) -c rSemanticas.c

fAuxs.o: fAuxs.c $(HEADERS)fAuxs.h $(HEADERS)scanner.h $(HEADERS)micro.h
	$(COMPILADOR) -c fAuxs.c

refresh:
	-rm $(OBJETOS)
	
#CLEAN Instruccion para eliminar todo
clean:
	-rm $(EJECUTABLE)
# -rm $()