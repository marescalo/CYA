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

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol {
 private:
  std::string symbol_;

 public:
  /// Constructores
  Symbol() {};
  Symbol(const std::string& symbol) { symbol_ = symbol; };
  Symbol(const char symbol) { symbol_ = symbol; };
  
  /// Getters
  std::string getSymbol() const { return symbol_; };
  char getChar() const { return symbol_[0]; };
  int getLength() const { return symbol_.length(); };
  /// Setter
  void setSymbol(std::string& symbol) { symbol_ = symbol; };

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend bool operator==(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator!=(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator<(const Symbol& symbol1, const Symbol& symbol2);
};

#endif