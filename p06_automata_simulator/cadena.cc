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
#include "cadena.h"
#include "alphabet.h"


const char EMPTY = '&';
const std::string EMPTY_STR = "&";
const std::string MARKS = "'";
const std::string SPACE_STR = " ";

// Constructor
Cadena::Cadena(std::string& string) {
  // Primero, contamos la cantidad de espacios de la línea
  int spaces = 0;
  for (const auto& elem : string) {
    if (elem == SPACE) ++spaces;
  }
  // Si hay más de un espacio, tenemos cadena y alfabeto
  std::string cadena_string;
  if (spaces > 0) {
    // Lo último es la cadena
    int last_space = string.find_last_of(SPACE);
    int length = string.length();
    for (int i = last_space + 1; i < length; ++i) {
      cadena_string += string[i];
    }
    // El resto es el alfabeto
    std::string aux_string;
    for (int i = 0; i <= last_space; ++i) {
      if (string[i] == SPACE) {
        alphabet_.add(aux_string);
        aux_string.erase();
      } else aux_string += string[i];
    }
  } 
  else { 
    // Si no, solo tenemos cadena
    cadena_string = string;
    alphabet_ = string;
  }
  
  // Por último, separamos y comprobamos que pertenece al alfabeto dado
  string_ = cadena_string;
  std::string aux_string;
  for (const auto& elem : cadena_string) {
    aux_string += elem;
    if (alphabet_.find(aux_string)) {
      cadena_.push_back(aux_string);
      aux_string.erase();
    }
  }
  if (aux_string != "") {
    std::cout << "Cadena incorrecta. Revise el fichero de entrada." << std::endl;
    exit(EXIT_SUCCESS); 
  }
}

// Getter de la cadena
std::string Cadena::getCadena() const {
  std::string cadena = MARKS;
  for (const auto& symbol : cadena_) {
    cadena += SPACE + symbol.getSymbol();
  }
  cadena += SPACE + MARKS;
  return cadena;
}

int Cadena::length() {  //calcula la cantidad de simbolos que tiene una cadena
  return cadena_.size();
}

std::string Cadena::reverse() { //calcula la cadena al reves
  std::string reverse_string;
  for (const auto& elem : cadena_) {
    reverse_string = elem.getSymbol() + reverse_string;
  }
  return reverse_string;
}

std::string Cadena::prefixes() { //calcula los prefijos de una cadena
  std::string aux_string, prefixes{EMPTY};
  for (const auto& elem : cadena_) {
    aux_string += elem.getSymbol();
    prefixes += SPACE + aux_string;
  }
  return prefixes;
}

std::string Cadena::suffixes() { //calcula los sufijos de una cadena
  std::string aux_string, suffixes{EMPTY};
  for (int i = cadena_.size() - 1;  i >= 0 ; --i) {
    aux_string = cadena_
    [i].getSymbol() + aux_string;
    suffixes += SPACE + aux_string;
  }
  return suffixes;
}

bool find(std::vector<std::string> vector, std::string string) { //comprueba si la string ertenece al vector que determina la aceptacion
  bool found = false;
  for (const auto& elem : vector) {
    if (elem == string) found = true;
  }
  return found;
}

std::string vector_to_string(std::vector<std::string> vector) { //pasar de vector<string> a una sola string
  std::string string_vector;
  for (const auto& elem : vector) string_vector += elem + SPACE;
  return string_vector;
}

std::string Cadena::substrings() { //calcula las subcadenas de una cadena
  std::vector<std::string> substrings;
  substrings.push_back(EMPTY_STR);
  std::string aux_string;
  int size = cadena_.size();
  for (int i = 0; i < size; ++i) {
    for (int j = i; j < size; ++j) {
      aux_string += cadena_[j].getSymbol();
      if (!find(substrings, aux_string)) substrings.push_back(aux_string);
    }
    aux_string.erase();
  } 
  return vector_to_string(substrings) + SPACE;
}

std::ostream& operator<<(std::ostream& out, const Cadena& Cadena) { //sobrecarga de operador
  out << "'";
  
  out << "'";
  return out;
}

std::string Cadena::non_used() { //comprobacion de los simblos no utilizados
  std::string non_used;
  for (int i = 0; i < getAlphabet().getSize(); ++i) {
    if (string_.find(getAlphabet().getAlphabet()[i].getSymbol()) == std::string::npos) {
      non_used += getAlphabet().getAlphabet()[i].getSymbol();
    }
  }
  return non_used;
}

