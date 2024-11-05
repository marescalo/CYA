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

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] alphabet
 */
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "{ ";
  for (const auto& symbol : alphabet.getAlphabet()) {
    out << symbol.getSymbol() << SPACE;
  }
  out << "}";
  return out;
}

/** 
 *  @brief Comprueba si un símbolo pertenece a un alfabeto
 *  @param[in] symbol
 *  @return True si pertenece, false si no
 */
bool Alphabet::find(Symbol symbol) const {
  bool found = false;
  for (const auto& elem : getAlphabet()) {
    if (symbol.getSymbol() == elem.getSymbol()) found = true;
  }
  return found;
}

/** 
 *  @brief Añade un símbolo a un alfabeto (si no lo contiene ya)
 *  @param[in] symbol
 */
void Alphabet::add(Symbol symbol) {
  alphabet_.insert(symbol);
}

/** 
 *  @brief Sobrecarga de la suma (unión)
 *  @param[in] alphabet1
 *  @param[in] alphabet2
 *  @return Alfabeto suma (unión)
 */
Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2) {
  Alphabet new_alphabet;
  for (const auto& elem : alphabet1.getAlphabet()) {
    new_alphabet.add(elem);
  }
  for (const auto& elem : alphabet2.getAlphabet()) {
    new_alphabet.add(elem);
  }
  return new_alphabet;
}