# Universidad de La Laguna
# Escuela Superior de Ingenierıa y Tecnologıa
# Grado en Ingenierıa Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Cadenas y lenguajes
# Autor: Margarita Blanca Escobar Alonso
# Correo: alu0101567211@ull.edu.es
# Fecha: 20/09/2024
# Archivo cya-P02-strings.cc: programa cliente.
#     Contiene la funcion main del proyecto que usa las clases X e Y
#     para ... (indicar brevemente el objetivo)
# Referencias:
#     Enlaces de interes
#
# Historial de revisiones
#     17/09/2024- Creacion (primera version) del codigo

CXX = g++						             # The C++ compiler command
CXXFLAGS = -std=c++14 -g -Wall	 # The C++ compiler options (C++14, preserve debug symbols and warn all)
LDFLAGS =						             # The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: main

main: main.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
# hello_world.o: hello_world.cc
	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
# We can use it for additional housekeeping purposes
clean :
	rm *.o main doc
	rm -r a.out
	find . -name '*~' -exec rm {} \;