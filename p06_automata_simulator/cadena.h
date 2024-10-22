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

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Cadena
{
private:

  Alphabet alphabet_;
  std::vector<Symbol> cadena_;
  std::string string_;

public:
  /// Constructor
  Cadena(std::string& string);
  /// Getters
  Alphabet getAlphabet() const { return alphabet_; }; //Alfabeto de la secuencia (alphabet_)
  std::string getCadena() const; //Secuencia de símbolos (sequence_)
  std::string getString() const { return string_; }; //Cadena de la secuencia (string_)
  /// Funciones
  int length();
  std::string reverse();
  // Sequence reverse();
  std::string prefixes();
  std::string suffixes();
  std::string substrings();
  std::string non_used();

  friend std::ostream& operator<<(std::ostream& os, Cadena cadena) {
    os << cadena.getString();
    return os;
  }
};

#endif