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
#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <string>
#include "symbol.h"
#include <set>
#include <fstream> //flujo de ficheros
#include <istream>
#include <ostream>

class Alphabet{
  public:
    //constructores
    Alphabet(){};
    Alphabet(const std::set<Symbol>& alphabet){alphabet_ = alphabet; cardinal_ = alphabet.size();};
    Alphabet(const std::string string);

    //getters
    std::set<Symbol> getAlphabet() const{return alphabet_;};
    int getCardinal() const{return cardinal_;};

    //sobre carga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet){
      os << "{ ";
      for(auto& symbol:alphabet.getAlphabet()){
          os << symbol << ", ";
      }
      os << "}";
      return os;
    }

    //funciones
    bool find(Symbol symbol);
    void add(Symbol symbol);

  private:
    std::set<Symbol> alphabet_; 
    int cardinal_;
};

#endif