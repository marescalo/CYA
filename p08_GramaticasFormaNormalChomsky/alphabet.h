// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 3/11/2024
// Archivo p08_GramaticasFormaNormalChomskys
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     3/11/2024- Creacion (primera version) del codigo

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "symbol.h"

const char SPACE = ' ';
/// Para comprobaciones
const std::vector<char> kAlphabet = {'S', 'A', 'B', 'C', 'D', 'E', 'F' , 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'K', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<bool> Used = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Alphabet {
 private:
  std::set<Symbol> alphabet_;

 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& string);

  /// Getters
  std::set<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return alphabet_.size(); };

  /// Funciones
  bool find(Symbol symbol) const;
  void add(Symbol symbol);

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2);
};

#endif