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
  std::string getSymbol() const { return symbol_; }; // Símbolo (symbol_)
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