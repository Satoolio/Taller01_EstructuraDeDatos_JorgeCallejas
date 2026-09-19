#include "Persona.h"

Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

string Persona::getNombre() { return this->nombre; }
int Persona::getEdad() { return this->edad; }

string Persona::resumen() {
    return this->nombre + " (" + to_string(this->edad) + ")";
}

Persona::~Persona() {}
