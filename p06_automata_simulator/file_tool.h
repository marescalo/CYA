// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Automatas Finitios
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 20/10/2024
// Archivo p06_automatas_finitos
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     20/10/2024- Creacion (primera version) del codigo

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

class file_tool {
  private:
    /* data */
  public:
    file_tool(/* args */);
    ~file_tool();
    int count_lines(std::string& file);
    Alphabet line_to_alphabet(std::string& line);
    void line_to_transitions(std::string& line, std::vector<Transition>& transitions)

};

file_tool::file_tool(/* args */)
{
}

file_tool::~file_tool()
{
}
