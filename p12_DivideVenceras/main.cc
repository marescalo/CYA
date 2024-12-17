// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 12: Divide y Vencerás
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 16/12/2024
// Archivo p12_DivideVenceras
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     16/12/2024- Creacion (primera version) del codigo


// main.cpp
#include <iostream>
#include "point_set.h"

int main() {
    std::vector<CyA::point> points;
    double x, y;

    while (std::cin >> x >> y) {
        points.emplace_back(x, y);
    }

    CyA::point_set ps(points);
    ps.quickHull();

    ps.write_hull(std::cout);
    ps.write_dot("hull_output.dot");

    return 0;
}