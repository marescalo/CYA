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

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

// #include "state.cc"
// #include "alphabet.cc"
#include "cadena.h"
#include "transition.h"

class NFA {
    private:
      Alphabet alphabet_;
      std::set<State> states_;
      unsigned int num_;
      State initial_;
      std::set<State> finals_;
      std::vector<Transition> transitions_;

    public:
        //constructores
        NFA() {};   
        NFA(const NFA& nfa);

        //Getter y Setters
        Alphabet getAlphabet() const {return alphabet_; }; // Alfabeto del NFA (alphabet_)
        void setAlphabet(const Alphabet& alphabet) {alphabet_ = alphabet; };
        std::set<State> getStates() const { return states_; }; //Conjunto de estados (states_)
        void setStates(std::set<State> states) { states_ = states; };
        unsigned int getNum() const { return num_; }; //Número de estados (num_)
        void setNum(unsigned int num) { num_ = num; }; 
        State getInitial() const { return initial_; }; //Estado inicial (initial_)
        void setInitial(State initial) { initial_ = initial; };
        std::set<State> getFinals() const { return finals_; }; //Conjunto de estados de aceptación (finals_)
        void setFinals(std::set<State> finals) { finals_ = finals; };
        std::vector<Transition> getTransitions() const { return transitions_; }; //Función de transición (transitions_)
        void setTransitions(std::vector<Transition> transitions) { transitions_ = transitions; };
        
        //Funciones
        bool accepted(const Cadena& cadena);
        State find_state(unsigned int id);
        void epsilon_transition(std::vector<State>& states);

        //sobrecarga
        friend std::ostream& operator<<(std::ostream& out, const NFA& nfa);
        
};

#endif
