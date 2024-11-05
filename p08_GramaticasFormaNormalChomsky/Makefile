# Universidad de La Laguna
# Escuela Superior de Ingenierıa y Tecnologıa
# Grado en Ingenierıa Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 6: Automatas Finitios
# Autor: Margarita Blanca Escobar Alonso
# Correo: alu0101567211@ull.edu.es
# Fecha: 20/10/2024
# Archivo p06_automatas_finitos
# Referencias:
#     Enlaces de interes
#
# Historial de revisiones
#     20/10/2024- Creacion (primera version) del codigo

CXX = g++						             # The C++ compiler command
CXXFLAGS = -std=c++14 -g -Wall	 # The C++ compiler options (C++14, preserve debug symbols and warn all)
LDFLAGS =						             # The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: Grammar2CNF

Grammar2CNF: alphabet.o file_tools.o symbol.o grammar.o main.o
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
	rm -f *.o Grammar2CNF doc
	rm -rf a.out
	find . -name '*~' -exec rm {} \;