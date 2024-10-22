// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Automatas Finitios
// Autor: Margarita Blanca Escobar Alonso
// Correo: alu0101567211@ull.edu.es
// Fecha: 20/10/2024
// Archivo p06_automatas_finitos
// Referencias:
//     Enlaces de interes
//
// Historial de revisiones
//     20/10/2024- Creacion (primera version) del codigo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

#include "file_tools.cc"

const std::string kHelpText = "Modo de empleo: ./p06_automata_simulator input.fa input.txt \n\
  Pruebe 'p06_automata_simulator --help' para mas informacion. \n\
      (input.fa) \n\
          Automata finito definido de la siguiente forma: \n\
              Linea 1: Simbolos del alfabeto separados por espacios. \n\
              Linea 2: Numero total de estados del automata. \n\
              Linea 3: Estado de arranque. \n\
              El resto de lineas contendran los detalles de cada estado. \n\
      (input.txt) \n\
          Cadenas para probar en el automata.";

void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

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

void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char* argv[]){

    if (argc == 1) { 
        Error(argv[0]); 
    }
    Usage(argc, argv);

    /// Preparamos el fichero
    std::string kNFAFileName = argv[1];
    FileExist(kNFAFileName);
    std::string kStringsFileName = argv[2];
    FileExist(kStringsFileName);

    /// Llamamos al programa
    NFA nfa(FileToNFA(kNFAFileName));
    std::cout << nfa << std::endl;
    CheckStrings(kStringsFileName, nfa);
    return 0;
}