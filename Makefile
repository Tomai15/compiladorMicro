#COMPILADOR, HEADERS Y OBJETOS son "Variables" en el Makefile, se usan en el Detalle de Compilacion
COMPILADOR := gcc
EJECUTABLE := ccompilador
HEADERS := headers/
OBJETOS := compilador.o parser.o scanner.o rSemanticas.o funcionesUtiles.o


#ALL Instruccion para compilar todo
all: Compilador_compilador refresh


# Compilador_compilador (Detalle del proceso de compilacion)
Compilador_compilador: $(OBJETOS)
	$(COMPILADOR) -o $(EJECUTABLE) $(OBJETOS)

compilador.o: compilador.c $(HEADERS)compilador.h $(HEADERS)parser.h
	$(COMPILADOR) -c compilador.c

parser.o: parser.c $(HEADERS)parser.h $(HEADERS)rSemanticas.h $(HEADERS)funcionesUtiles.h $(HEADERS)compilador.h
	$(COMPILADOR) -c parser.c

scanner.o: scanner.c $(HEADERS)scanner.h $(HEADERS)compilador.h
	$(COMPILADOR) -c scanner.c

rSemanticas.o: rSemanticas.c $(HEADERS)rSemanticas.h $(HEADERS)funcionesUtiles.h $(HEADERS)compilador.h
	$(COMPILADOR) -c rSemanticas.c

funcionesUtiles.o: funcionesUtiles.c $(HEADERS)funcionesUtiles.h $(HEADERS)scanner.h $(HEADERS)compilador.h
	$(COMPILADOR) -c funcionesUtiles.c

refresh:
	-rm $(OBJETOS)
	
#CLEAN Instruccion para eliminar todo
clean:
	-rm $(EJECUTABLE)
#RUN Instruccion para ejecutar el programa con el archivo micro designado
run:
	./ccompilador programa3.m archSalida
