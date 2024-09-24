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

#include "alphabet.h"
#include <iostream>
const char COMA = ',';
const char SPACE = ' ';

//constructor
Alphabet::Alphabet(const std::string string){
    for(const auto symbol : string){
        alphabet_.insert(Symbol{symbol});
    }
}

//metodo para comprobar si esta dentro del alfabeto el simbolo
bool Alphabet::find(Symbol symbol){
    bool found = false;
    for(const auto& elem : getAlphabet()){
        if (symbol.getSymbol() == elem.getSymbol()) found = true;
    }
    return found;
}

//metodo para añadir un simbolo en caso de que no pertenezca al alfabeto
void Alphabet::add(Symbol symbol) {
    if(!find(symbol)) {
        alphabet_.insert(symbol);
        ++cardinal_;
    }
}