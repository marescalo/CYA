# Universidad de La Laguna
# Escuela Superior de Ingenierıa y Tecnologıa
# Grado en Ingenierıa Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Cadenas y lenguajes
# Autor: Margarita Blanca Escobar Alonso
# Correo: alu0101567211@ull.edu.es
# Fecha: 20/09/2024
# Archivo cya-P02-strings.cc: programa cliente.
#    Contiene la funcion main del proyecto que usa las clases X e Y
#     para ... (indicar brevemente el objetivo)
# Referencias:
#     Enlaces de interes
#
# Historial de revisiones
#     17/09/2024- Creacion (primera version) del codigo


# Set especifications
cmake_minimum_required(VERSION 3.1)

project(p02_strings
        VERSION 1.0
        DESCRIPTION ""
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake to put binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Tell CMake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIRECTORY}/src)

# Add executable "circulo" to be built from source files (*.h, *.cc)
add_executable(p02_strings
               chain.h
               chain.cpp
               symbol.h
               symbol.cpp
               alphabet.h
               alphabet.cpp
               main.cpp)

# Add expected compiler features to target
target_compile_features(p02_strings PRIVATE cxx_std_17)

# Add compile options to target
target_compile_options(p02_strings PRIVATE -Wall -Wpedantic)