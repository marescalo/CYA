 // Universidad de La Laguna
 // Escuela Superior de Ingenierıa y Tecnologıa
 // Grado en Ingenierıa Informatica
 // Asignatura: Computabilidad y Algoritmia
 // Curso: 2º
 // Practica 2: Cadenas y lenguajes
 // Autor: Margarita Blanca Escobar Alonso
 // Correo: alu0101567211@ull.edu.es
 // Fecha: 20/09/2024
 // Archivo cya-P02-strings.cc: programa cliente.
 //     Contiene la funcion main del proyecto que usa las clases X e Y
 //     para ... (indicar brevemente el objetivo)
 // Referencias:
 //     Enlaces de interes
 //
 // Historial de revisiones
 //     17/09/2024- Creacion (primera version) del codigo

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol{
    
    public:
      //contructores
      Symbol(){};
      Symbol(const char& symbol){symbol_ = symbol;};

      //getter
      char getSymbol() const {return symbol_;}

      //sobrecarga del operador de salida
      friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol){
        os << symbol.getSymbol();
        return os;
      }

      //sobrecarga operador de comparacion
      friend bool operator<(const Symbol& a, const Symbol& b) { return a.getSymbol() < b.getSymbol(); }

    private:
      char symbol_;
};

#endif