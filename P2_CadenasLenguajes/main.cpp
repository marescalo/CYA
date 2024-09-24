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

#include <iostream>
#include "chain.h"
#include "symbol.h"
#include "alphabet.h"
#include "chain.cpp"

void Error(){
    std::cout << "Error, no se han introducido los parametros necesarios" << std::endl;
    std::cout << "o se han introducido mas de los necesarios." << std::endl;
    std::cout << "Para mas informacion pruebe --help" << std::endl;
    exit(1);
}

void Usage(int argc, char* argv[]){
    std::string helper = argv[1]; //ayuda si q necesito yo :')
    if(helper == "--help"){
        std::cout << "Uso: ./p01_string fileon.txt fileout.txt opcode \n Opciones válidas para el opcode: \n 1) Alphabeto \n 2) Longitud \n 3) Inversa \n 4) Prefijos \n 5) Sufijos ";
    }
    else if(argc != 4){
        Error();
        exit(1);
    }
    else if((argc == 4) & ((std::stoi(argv[3]) > 5) | (std::stoi(argv[3]) < 0))){
        Error();
        exit(1);
    }
}

int main(int argc, char* argv[]){
  if(argc == 1){
    Error();
  }
  Usage (argc, argv);

  std::string kInputFileName = argv[1];
  std::string kOutputFileName = argv[2];
  std::string opecode = argv[3];
  const int kOpecode = std::stoi(opecode);

  std::ifstream input_file{kInputFileName, std::ios_base::in};
  if (!input_file){
    std::cout << "No se ha podido abrir el archivo" << kOpecode << " sobre el fichero de entrada." << std::endl;
    exit(1);
  }
  std::string line;
  std::ofstream output_file{kOutputFileName};

  while(getline(input_file, line)){

    Chain new_sequence = line;

    switch (kOpecode) {
    case 1: //alfabeto
        output_file << new_sequence.getAlphabet() << std::endl;
        break;
    case 2: //longitud
        output_file << new_sequence.Longitud() << std::endl;
        break;
    case 3: //inversa
        output_file << new_sequence.Inversa() << std::endl;
        break;
    case 4: //prefijo
        output_file << new_sequence.Prefijo() << std::endl;
        break;
    case 5: //sufijo
        output_file << new_sequence.Sufijo() << std::endl;
        break;
    default:
        break;
    }
  }

  return 0;

}