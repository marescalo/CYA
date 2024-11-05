/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 05 Nov 2022
 * @brief Archivo: state.h
 *        Definición de la clase estado
 * 
 * @details 
 *    05/11/2022 - Creación del fichero
 *    05/11/2022 - Añadidos los constructores
 *    05/11/2022 - Añadidos los getters y setters
 *    05/11/2022 - Añadidas las sobrecargas
 */

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "transition.cc"

/** 
 *  @brief Esta clase se usa para guardar los estados
 *         Guarda los siguientes datos:
 *            - Nombre del estado (name_)
 *            - Identificador del estado (id_)
 *            - Indica si es de aceptación (final_)
 */
class State {
 private:
  std::string name_ = "";
  unsigned int id_;
  bool final_ = false;
  std::vector<Transition> transitions_;

 public:
  /// Constructores
  State() {};
  State(const State& state);
  State(std::string name, unsigned int id, bool final, std::vector<Transition> transitions);

  /// Getters y setters
  bool getFinal() const { return final_; };
  void setFinal(bool final) { final_ = final; };
  std::string getName() const { return name_; };
  void setName(std::string name) { name_ = name; };
  unsigned int getID() const { return id_; };
  void setID(unsigned int id) { id_= id; };
  std::vector<Transition> getTransitions() const { return transitions_; };
  void setTranstions(std::vector<Transition> transitions) { transitions_ = transitions; };
  
  /// Sobrecargas
  void operator=(const State& state);
  friend bool operator==(const State& state1, const State& state2);
  friend bool operator!=(const State& state1, const State& state2);
  friend bool operator<(const State& state1, const State& state2);
  friend bool operator>(const State& state1, const State& state2);
  friend std::ostream& operator<<(std::ostream& out, const State& state);

};

#endif