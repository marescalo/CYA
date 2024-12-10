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

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <utility>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA{

    typedef std::pair<double, double> point;

    typedef std::pair<point, point> line;
    typedef std::vector<point> point_vector;

    typedef std::pair<point, point> arc;
    typedef std::pair<double, arc> weigthed_arc;
    typedef std::vector<weigthed_arc> arc_vector;

    typedef std::set<point> point_collection;

    typedef std::vector<arc> tree;
}

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);
std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);