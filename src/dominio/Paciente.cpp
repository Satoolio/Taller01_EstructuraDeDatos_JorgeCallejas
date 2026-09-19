#include "Paciente.h"

Paciente::Paciente(string id, string nombre, int edad, string servicio) : Persona(nombre, edad) {
    this->id = id;
    this->servicio = servicio;
}

string Paciente::getId() { return this->id; }
string Paciente::getServicio() { return this->servicio; }

string Paciente::resumen() {
    return this->id + " - " + Persona::resumen();
}

Paciente::~Paciente() {}
