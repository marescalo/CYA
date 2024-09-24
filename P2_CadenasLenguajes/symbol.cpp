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

 #include "symbol.h"
 #include <iostream>

std::ostream& operator<<(std::ostream out, const Symbol& symbol){
    out << symbol.getSymbol();
    return out;
}
