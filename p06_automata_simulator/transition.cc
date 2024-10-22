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
#include "transition.h"

// Constructor de copia
Transition::Transition(const Transition& transition) {
  symbol_ = transition.getSymbol();
  next_state_ = transition.getNextState();
  actual_state_ = transition.getActualState();
}

// Constructor con parámetros
Transition::Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state) {
  symbol_ = symbol;
  next_state_ = next_state;
  actual_state_ = actual_state;
}

// Sobrecarga del operador ==
bool operator==(const Transition& transition1, const Transition& transition2) {
  bool equal = true;
  if (transition1.getActualState() != transition2.getActualState()) equal = false;
  if (transition1.getNextState() != transition2.getNextState()) equal = false;
  if (transition1.getSymbol() != transition2.getSymbol()) equal = false;
  return equal;
}

// Sobrecarga del operador !=
bool operator!=(const Transition& transition1, const Transition& transition2) {
  return !(transition1 == transition2);
}

// Sobrecarga del operador <
bool operator<(const Transition& transition1, const Transition& transition2) {
  return transition1.getActualState() < transition2.getActualState();
}

// Sobrecarga del operador >
bool operator>(const Transition& transition1, const Transition& transition2) {
  return !(transition1 < transition2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Transition& transition) {
  out << transition.getActualState();
  out << "(" << transition.getSymbol() << "): ";
  out << transition.getNextState();
  return out;
}