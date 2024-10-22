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
#include "state.h"

// Constructor de copia
State::State(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}

// Constructor con parámetros
State::State(std::string name, unsigned int id, bool final) {
  name_ = name;
  id_ = id;
  final_ = final;
}

// Sobrecarga del operador =
void State::operator=(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}

// Sobrecarga del operador ==
bool operator==(const State& state1, const State& state2) {
  bool equal = true;
  if (state1.getID() != state2.getID()) equal = false;
  return equal;
}

// Sobrecarga del operador !=
bool operator!=(const State& state1, const State& state2) {
  return !(state1 == state2);
}

// Sobrecarga del operador <
bool operator<(const State& state1, const State& state2) {
  return (state1.getID() < state2.getID());
}

// Sobrecarga del operador >
bool operator>(const State& state1, const State& state2) {
  return !(state1 < state2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.getName() << "(" << state.getID() << ")";
  out << "(" << state.getFinal() << ")";
  return out;
}