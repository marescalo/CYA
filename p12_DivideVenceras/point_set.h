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
//     16/12/2024 - Creacion (primera version) del codigo


#ifndef POINT_SET_H
#define POINT_SET_H

#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

namespace CyA {
    typedef std::pair<double, double> point;
    typedef std::pair<point, point> line;
    typedef std::vector<point> point_vector;

    enum side {
        LEFT = -1,
        CENTER,
        RIGHT
    };

    class point_set : public point_vector {
    private:
        point_vector hull_;

    public:
        point_set(const point_vector &points);
        ~point_set() = default;

        void quickHull();
        void write_hull(std::ostream &os) const;
        void write_dot(const std::string &filename) const;

        inline const point_vector& get_hull() const { return hull_; }

    private:
        void quickHull(const line &l, int side);
        double distance(const line &l, const point &p) const;
        int find_side(const line &l, const point &p) const;
        void x_bounds(point &min_x, point &max_x) const;
        double point_2_line(const line &l, const point &p) const;
        bool farthest_point(const line &l, int side, point &farthest) const;
    };
}

#endif