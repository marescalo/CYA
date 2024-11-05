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
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "file_tools.cc"
#include "grammar.cc"

const std::string kHelpText = "Modo de empleo: ./Grammar2CNF input.gra output.gra \n\
Pruebe 'Grammar2CNF --help' para mas informacion. \n\
      (input.gra) \n\
          Fichero de especificacion de una gramatica: \n\
              1: Simbolos terminales (alfabeto). \n\
              2: Simbolos no terminales. \n\
              3: Simbolo de arranque. \n\
              4: Producciones. \n";

/// Mensaje de error para cuando no se usan parámetros
void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cout << argv[0] << ": Ha introducido mas de 2 parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}



int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kInputFileName = argv[1];
  FileExist(kInputFileName);
  std::string kOutputFileName = argv[2];
  FileExist(kOutputFileName);
  /// Llamamos al programa
  Grammar grammar(kInputFileName);
  grammar.check();
  // std::cout << grammar << std::endl;
  Grammar grammar_CNF = grammar.ConvertToCNF();
  // std::cout << grammar_CNF << std::endl;
  grammar_CNF.write(kOutputFileName);
  // grammar_CNF.productions();
  return 0;
}