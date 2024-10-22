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
#include <vector>
#include "NFA.h"

NFA::NFA(const NFA& nfa) { //constructor de copia
  alphabet_ = nfa.getAlphabet();
  states_ = nfa.getStates();
  num_ = nfa.getNum();
  initial_ = nfa.getInitial();
  finals_ = nfa.getFinals();
  transitions_ = nfa.getTransitions();
}

std::ostream& operator<<(std::ostream& out, const NFA& nfa) { //sobrecarga operador <<
  out << "Alfabeto: " << nfa.getAlphabet() << std::endl;
  out << "Num: " << nfa.getNum() << std::endl;
  out << "Inicial: " << nfa.getInitial() << std::endl;
  out << "Estados: " << std::endl;
  for (const auto& elem : nfa.getStates()) out << elem << std::endl;
  out << "Finales: " << std::endl;
  for (const auto& elem : nfa.getFinals()) out << elem << std::endl;
  out << "Transiciones: " << std::endl;
  for (const auto& elem : nfa.getTransitions()) out << elem << std::endl;
  return out;
}

State NFA::find_state(unsigned int id) { //busca y devuelve el estado con ese id
  State state;
  for (const auto& elem : states_) {
    if (elem.getID() == id) state = elem;
  }
  return state;
}


//añade un estado el nfa
void NFA::epsilon_transition(std::vector<State>& states) {
  bool flag = true;
  std::vector<State> saved = states;
  while (flag) {
    flag = false;
    std::vector<State> next_state;
    for (const auto& elem : states) {
      // std::cout << elem << std::endl;
      for (const auto& transition : transitions_) {
        if (transition.getActualState() == elem.getID()) {
          // std::cout << transition << std::endl;
          if (transition.getSymbol() == '&') {
            // std::cout << transition << std::endl;
            next_state.push_back(find_state(transition.getNextState()));
            saved.push_back(find_state(transition.getNextState()));
            // std::cout << find_state(transition.getNextState()) << std::endl;
            flag = true;
          }
        }
      }
    }
    states = next_state;
  }
  states = saved;
}

bool NFA::accepted(const Cadena& cadena) { // Comprueba si la cadena es aceptada por el automata
  std::string string = cadena.getString();
  /// Comprobamos la cadena vacía
  if (string == "&") return initial_.getFinal();
  /// El vector de momento solo tiene el estado inicial
  std::vector<State> states;
  states.push_back(getInitial());
  /// Recorremos la cadena
  for (const auto& elem : string) {
    std::vector<State> new_states;
    Symbol symbol = elem;
    /// Buscamos las E-transiciones
    epsilon_transition(states);
    /// Para cada estado del vector
    for (const auto& state : states) {
      /// Buscamos las transiciones
      for (const auto& transition : transitions_) {
        if (transition.getActualState() == state.getID()) {
          /// Buscamos las que nos permiten transitar
          if (transition.getSymbol() == symbol) {
            State new_state = find_state(transition.getNextState());
            new_states.push_back(new_state);
          }
        }
      }
    }
    for (const auto& elem : new_states) {
      states.push_back(elem);
    }
    
  }
  /// Comprobamos si son de aceptación
  State stateFinal = states.back();
  for (const auto& elem : finals_) {
    if (elem == stateFinal) return true;
  }
  return false;
}