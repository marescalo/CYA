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

#include "point_types.h"

namespace EMST{
    class sub_tree{
        
    private:
        CyA::tree arcs_;
        CyA::point_collection points_;
        double cost_;

    public:
        sub_tree(void);
        ~sub_tree(void);

        void add_arc(const CyA::arc &a);
        void add_point(const CyA::point &p);
        bool contains(const CyA::point &p) const;
        void merge(const sub_tree &st, const CyA::weigthed_arc &a);

        inline const CyA::tree& get_arcs(void) const { return arcs_; }
        inline double get_cost(void) const { return cost_; }
    };

    typedef std::vector<sub_tree> sub_tree_vector;
}