// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 3/11/2024
// Archivo p11_AlgoritmosVoraces
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     8/12/2024- Creacion (primera version) del codigo

#include "point_types.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps){
    os << ps.size() << std::endl;

    for (const CyA::point &p : ps){
        os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" 
           << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second << std::endl;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::point& p){
    os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first 
       << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;
    return os;
}

std::istream& operator>>(std::istream& is, CyA::point_vector& ps){
    int n;
    is >> n;
    ps.clear();

    for (int i = 0; i < n; ++i){
        CyA::point p;
        is >> p.first >> p.second;
        ps.push_back(p);
    }

    return is;
}

std::istream& operator>>(std::istream& is, CyA::point& p){
    is >> p.first >> p.second;
    return is;
}