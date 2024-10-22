
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
#include "alphabet.h"
#include "symbol.h"

/// Constructor
Alphabet::Alphabet(std::string& string) {
  for (const auto& elem : string) {
    Symbol symbol = elem;
    add(symbol);
  }
}

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) { //sobrecarga operador <<
  out << "{ ";
  for (const auto& symbol : alphabet.getAlphabet()) {
    out << symbol.getSymbol() << SPACE;
  }
  out << "}";
  return out;
}

bool Alphabet::find(Symbol symbol) const { // comprobamos si un simbolo pertenece a un alfabeto
  bool found = false;
  for (const auto& elem : getAlphabet()) {
    if (symbol.getSymbol() == elem.getSymbol()) found = true;
  }
  return found;
}

void Alphabet::add(Symbol symbol) { //añade un simbolo al alfabeto si este no esta dentro ya
  if (!find(symbol)) {
    alphabet_.push_back(symbol);
  } 
}

Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2) { //sobrecarga de la suma
  Alphabet new_alphabet;
  for (const auto& elem : alphabet1.getAlphabet()) {
    new_alphabet.add(elem);
  }
  for (const auto& elem : alphabet2.getAlphabet()) {
    new_alphabet.add(elem);
  }
  return new_alphabet;
}