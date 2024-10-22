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
#include <string>
#include <fstream>
#include <sstream> // stringstream
#include "file_tool.h"

int count_lines(std::string& file) { //Cuenta lasa lineas de un fichero
  std::ifstream input_file{file, std::ios_base::in};
  std::string line;
  int num_lines = 0;
  while (getline(input_file, line)) {
    ++num_lines;
  }
  return num_lines;
}
 
Alphabet line_to_alphabet(std::string& line) { //convierte una linea del fichero en un alfabeto
  Alphabet alphabet;
  for (const auto& elem : line) {
    if (elem != ' ') alphabet.add(elem);
  }
  return alphabet;
}


// Convierte una línea del fichero en transiciones
void line_to_transitions(std::string& line, std::vector<Transition>& transitions) {
  std::string elem;
  std::stringstream new_line(line);
  /// Necesitamos el id
  getline(new_line, elem, ' ');
  unsigned int id = stoi(elem);
  /// No necesitamos si es de aceptación o no
  getline(new_line, elem, ' ');
  /// Extraemos el número de transiciones
  getline(new_line, elem, ' ');
  unsigned int num = stoi(elem);
  for (int i = 0; i < int(num); ++i) {
    /// Símbolo 
    getline(new_line, elem, ' ');
    Symbol symbol = elem;
    /// Estado origen 
    getline(new_line, elem, ' ');
    Transition transition(symbol, id, stoi(elem));
    transitions.push_back(transition);
  }
}

// Convierte una línea del fichero en estado
State line_to_state(std::string& line) {
  State state;
  std::string elem;
  std::stringstream new_line(line);
  /// Extraemos el id
  getline(new_line, elem, ' ');
  state.setID(stoi(elem));
  /// Extraemos si es de aceptacion
  getline(new_line, elem, ' ');
  state.setFinal(stoi(elem) == 1);
  return state;
}

// @brief Muestra el mensaje de error de formato
void error_formato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

//Pasa de un fichero .fa a NFA
NFA FileToNFA(std::string& file_name) {
  std::ifstream input_file{file_name, std::ios_base::in};
  std::string line;
  /// Comprobamos que tiene al menos las 2 líneas obligatorias 
  int num_lines = count_lines(file_name);
  if (num_lines < 2) error_formato();
  /// Extraemos el alfabeto
  getline(input_file, line);
  Alphabet alphabet(line_to_alphabet(line));
  /// Extraemos el número de estados
  getline(input_file, line);
  int num_states = stoi(line);
  /// Comprobamos que, si tiene al menos un estado, están definidos
  if (num_lines != num_states + 3)  error_formato();
  /// Extraemos el estado inicial
  getline(input_file, line);
  int initial_state = stoi(line);
  State initial;
  /// Extraemos los estados y las transiciones
  std::set<State> states;
  std::set<State> finals;
  std::vector<Transition> transitions;
  while (getline(input_file, line)) {
    State state(line_to_state(line));
    line_to_transitions(line, transitions);
    states.insert(state);
    if (state.getFinal()) finals.insert(state);
    if (int(state.getID()) == initial_state) initial = state;
  }
  /// Creamos el NFA
  NFA nfa;
  nfa.setAlphabet(alphabet);
  nfa.setStates(states);
  nfa.setNum(num_states);
  nfa.setInitial(initial);
  nfa.setFinals(finals);
  nfa.setTransitions(transitions);
  return nfa;
}

// Pasa de un fichero .fa a NFA
void CheckStrings(std::string& kStringsFileName, NFA& nfa) {
  std::ifstream input_file{kStringsFileName};
  std::string line;
  
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << kStringsFileName << std::endl;
    return;
  }

  while (getline(input_file, line)) {
    // Imprimimos la línea para ver qué contiene
    if (!line.empty()) {
      Cadena cadena{line};
      std::cout << line << " --- ";
      // Comprobamos si la secuencia es aceptada
      if (nfa.accepted(cadena)) {
        std::cout << "Accepted" << std::endl;
      } else {
        std::cout << "Rejected" << std::endl;
      }
    } else {
      std::cout << "[línea vacía]" << std::endl;
    }
  }
}