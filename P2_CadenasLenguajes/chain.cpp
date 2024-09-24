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

#include "chain.h"
#include <iostream>
#include <string>
#include <vector>


const char EMPTY = '&';
const std::string EMPTYCHAIN = "&";
const std::string SPACE = ", ";

Chain::Chain(std::string& string){

    int spaces = 0;
    for(const auto& symbol : string){
        if(symbol == SPACE) ++spaces;
    }

    std::string chain_string;
    if(spaces > 0){
        int last_space = string.find_last_of(SPACE);
        int length = string.length();
        for(int i = last_space + 1; i < length; i++){
            chain_string += string[i];
        }

        std::string aux_string;
        for(int i = 0; i <= last_space; i++){
            if(string[i] == SPACE){
                alphabet_.add(aux_string);
                aux_string.erase();
            }
            else {
                aux_string += string[1];
            }
        }
    }
    else{
        chain_string = string;
        alphabet_ = string;
    }

    string_ = chain_string;
    std::string aux_string;
    for(const auto& symbol : chain_string){
        aux_string += symbol;
        if(alphabet_.find(aux_string)){
            chain_.push_back(aux_string);
            aux_string.erase();
        }
    }
}

int Chain::Longitud(){
    return chain_.size();
}

std::string Chain::Inversa(){
    std::string aux;
    for(const Symbol& simbolo : chain_) {
        aux = simbolo.getSymbol() + aux;
    }
    return aux;
}

std::string Chain::Prefijo(){
    std::string aux,prefijos {EMPTY};
    for(const Symbol& simbolo : chain_) {
        aux += simbolo.getSymbol();
        prefijos += SPACE + aux;
    }
    return prefijos;
}

std::string Chain::Sufijo(){
    std::string aux, sufijos{EMPTY};
    for(int i = ((chain_.size()) - 1); i >= 0; i--){
        aux = chain_[i].getSymbol() + aux;
        sufijos += SPACE + aux;
    }
    return sufijos;
}
/*
std::string Chain::getChain(){
    std::string chain = space;
    for(const Symbol& simbolo : chain){
        chain += SPACE + simbolo.getSymbol();
    }
    chain += SPACE;
    return chain;
}*/