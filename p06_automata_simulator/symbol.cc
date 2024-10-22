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
#include "symbol.h"

//Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.getSymbol();
  return out;
}

// Sobrecarga del operador ==
bool operator==(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() == symbol2.getSymbol();
}

// Sobrecarga del operador !=
bool operator!=(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() != symbol2.getSymbol();
}

// Sobrecarga del operador <
bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() < symbol2.getSymbol();
}