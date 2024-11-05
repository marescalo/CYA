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

#include "alphabet.cc"
#include "symbol.cc"

typedef std::pair<Symbol, std::vector<Symbol>> pair;
typedef std::set<std::pair<Symbol, std::vector<Symbol>>> set_pair;

/** 
 *  @brief Esta clase se usa para guardar una gramática regular
 *         Guarda los siguientes datos:
 *            - Alfabeto de la gramática (terminales) (terminals_)
 *            - Conjunto de símbolos no terminales (non_terminals_)
 *            - No terminal inicial (initial_)
 *            - Producciones (productions_)
 */
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
  void setNonTerminals(const Alphabet& symbols) { non_terminals_ = symbols; };
  void setTerminals(const Alphabet& alphabet) { terminals_ = alphabet; };
  void setInitial(const Symbol initial) { initial_ = initial; };
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