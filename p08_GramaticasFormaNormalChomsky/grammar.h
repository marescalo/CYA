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

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <utility>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <set>

#include "alphabet.h"
#include "symbol.h"

typedef std::pair<Symbol, std::vector<Symbol>> pair;
typedef std::set<std::pair<Symbol, std::vector<Symbol>>> set_pair;

class Grammar {
 private:
  Alphabet non_terminals_;
  Alphabet terminals_;
  Symbol initial_;
  set_pair productions_;

 public:
  /// Constructores
  Grammar() {};
  Grammar(const Grammar& grammar);
  Grammar(const std::string& file);

  /// Getters y setters
  // - Conjunto de símbolos no terminales (non_terminals_)
  void setNonTerminals(const Alphabet& symbols) { non_terminals_ = symbols; };
  // - Alfabeto de la gramática (terminales) (terminals_)
  void setTerminals(const Alphabet& alphabet) { terminals_ = alphabet; };
  // - No terminal inicial (initial_)
  void setInitial(const Symbol initial) { initial_ = initial; };
  // - Producciones (productions_)
  void setProductions(const set_pair& productions) { productions_ = productions; };
  Alphabet getNonTerminals() const { return non_terminals_; };
  Alphabet getTerminals() const { return terminals_; };
  Symbol getInitial() const { return initial_; };
  set_pair getProductions() const { return productions_; };

  /// Funciones
  void write(const std::string& kFileName);
  void productions();
  bool accepted(const std::string& sequence);
  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);
  Grammar ConvertToCNF();
  void check();

};

#endif