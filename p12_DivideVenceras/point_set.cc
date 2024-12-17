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

// point_set.cpp
#include "point_set.h"
#include <fstream>

namespace CyA {

    point_set::point_set(const point_vector &points) : point_vector(points) {}

    void point_set::quickHull() {
        hull_.clear();
        point min_x_point, max_x_point;
        x_bounds(min_x_point, max_x_point);

        quickHull(line(min_x_point, max_x_point), side::LEFT);
        quickHull(line(min_x_point, max_x_point), side::RIGHT);

        std::sort(hull_.begin(), hull_.end());
        hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
    }

    void point_set::quickHull(const line &l, int side) {
        point farthest;
        if (farthest_point(l, side, farthest)) {
            quickHull(line(l.first, farthest), -find_side(line(l.first, farthest), l.second));
            quickHull(line(farthest, l.second), -find_side(line(farthest, l.second), l.first));
        } else {
            hull_.push_back(l.first);
            hull_.push_back(l.second);
        }
    }

    double point_set::distance(const line &l, const point &p) const {
        return std::abs(point_2_line(l, p));
    }

    int point_set::find_side(const line &l, const point &p) const {
        double val = point_2_line(l, p);
        return (val > 0) ? side::LEFT : (val < 0) ? side::RIGHT : side::CENTER;
    }

    void point_set::x_bounds(point &min_x, point &max_x) const {
        min_x = max_x = this->at(0);
        for (const auto &p : *this) {
            if (p.first < min_x.first) min_x = p;
            if (p.first > max_x.first) max_x = p;
        }
    }

    double point_set::point_2_line(const line &l, const point &p) const {
        const point &p1 = l.first;
        const point &p2 = l.second;
        return (p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first);
    }

    bool point_set::farthest_point(const line &l, int side, point &farthest) const {
        double max_dist = 0;
        bool found = false;
        for (const auto &p : *this) {
            if (find_side(l, p) == side) {
                double dist = distance(l, p);
                if (dist > max_dist) {
                    max_dist = dist;
                    farthest = p;
                    found = true;
                }
            }
        }
        return found;
    }

    void point_set::write_hull(std::ostream &os) const {
        for (const auto &p : hull_) {
            os << p.first << " " << p.second << "\n";
        }
    }

    void point_set::write_dot(const std::string &filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "graph ConvexHull {\n";
        
            // Escribir nodos con posiciones
            for (size_t i = 0; i < this->size(); ++i) {
                const auto &p = (*this)[i];
                file << "  " << i << " [pos =\"" << p.first << "," << p.second << "!\"];\n";
            }

            // Escribir aristas del convex hull
            for (size_t i = 0; i < hull_.size(); ++i) {
                size_t idx1 = std::distance(this->begin(), std::find(this->begin(), this->end(), hull_[i]));
                size_t idx2 = std::distance(this->begin(), std::find(this->begin(), this->end(), hull_[(i + 1) % hull_.size()]));
                file << "  " << idx1 << " -- " << idx2 << ";\n";
            }

            file << "}\n";
        }
    }

}