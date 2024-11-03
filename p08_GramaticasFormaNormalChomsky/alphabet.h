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
#include "symbol.h"

const char SPACE = ' ';

class Alphabet {
 private:
  std::vector<Symbol> alphabet_;

 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& string);

  /// Getters
  std::vector<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return alphabet_.size(); };

  /// Funciones
  bool find(Symbol symbol) const; //mira si un simbolo es parte del alfabeto
  void add(Symbol symbol); //añade un simbolo al alfabeto si este no existia ya en el

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2);
};

#endif