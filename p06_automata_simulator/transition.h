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

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include "symbol.h"
#include "state.h"

class Transition {
 private:
  Symbol symbol_;
  unsigned int actual_state_;
  unsigned int next_state_;

 public:
  /// Constructores
  Transition() {};
  Transition(const Transition& transition);
  Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state);

  /// Getters y setters
  void setSymbol(Symbol symbol) { symbol_ = symbol; }; // Símbolo con el que se transita (symbol_)
  Symbol getSymbol() const { return symbol_; };
  void setActualState(unsigned int state) { actual_state_ = state; }; // Estado actual (actual_state_)
  unsigned int getActualState() const { return actual_state_; }; 
  void setNextState(unsigned int states) { next_state_ = states; }; // Siguientes estados (next_state_)
  unsigned int getNextState() const { return next_state_; };

  /// Sobrecargas
  friend bool operator==(const Transition& transition1, const Transition& transition2);
  friend bool operator!=(const Transition& transition1, const Transition& transition2);
  friend bool operator<(const Transition& transition1, const Transition& transition2);
  friend bool operator>(const Transition& transition1, const Transition& transition2);
  friend std::ostream& operator<<(std::ostream& out, const Transition& transition);
};

#endif