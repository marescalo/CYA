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

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <string>


class State {
 private:
  std::string name_ = "";
  unsigned int id_;
  bool final_ = false;

 public:
  /// Constructores
  State() {};
  State(const State& state);
  State(std::string name, unsigned int id, bool final);

  /// Getters y setters
  bool getFinal() const { return final_; }; //Indica si es de aceptación (final_)
  void setFinal(bool final) { final_ = final; };
  std::string getName() const { return name_; }; // Nombre del estado (name_)
  void setName(std::string name) { name_ = name; };
  unsigned int getID() const { return id_; }; //Identificador del estado (id_)
  void setID(unsigned int id) { id_= id; };
  
  /// Sobrecargas
  void operator=(const State& state);
  friend bool operator==(const State& state1, const State& state2);
  friend bool operator!=(const State& state1, const State& state2);
  friend bool operator<(const State& state1, const State& state2);
  friend bool operator>(const State& state1, const State& state2);
  friend std::ostream& operator<<(std::ostream& out, const State& state);

};

#endif