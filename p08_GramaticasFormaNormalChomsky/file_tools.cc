// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 3/11/2024
// Archivo p08_GramaticasFormaNormalChomskys
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     3/11/2024- Creacion (primera version) del codigo

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream
#include "file_tools.h"

/** 
 *  @brief Muestra el mensaje de error de formato
 *  @return void, pero termina el programa
 */
void ErrorFormato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** 
 *  @brief Comprueba si un fichero existe
 *  @param[in] name_of_file
 *  @return (void) Pero termina el programa si no existe
 */
void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}