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

#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <string>
#include <vector>
#include "symbol.h"
#include "alphabet.h"

class Chain{
  public:
  //constructores
    Chain(){};
    //Chain(const std::vector<Symbol>& chain){chain_ = chain;};
    Chain(std::string& string);

    //getter
    std::vector<Symbol> getChain() const{return chain_;};
    Alphabet getAlphabet() const{return alphabet_;};

    //funciones
    int Longitud();
    std::string Inversa();
    std::string Prefijo();
    std::string Sufijo();

  private:
    std::vector<Symbol> chain_;
    Alphabet alphabet_;
    std::string string_;
};

#endif