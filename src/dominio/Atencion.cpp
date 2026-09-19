#include "Atencion.h"

Atencion::Atencion(string id, string nombre, int edad, string servicio) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

string Atencion::getId() { return this->id; }
string Atencion::getNombre() { return this->nombre; }
int Atencion::getEdad() { return this->edad; }
string Atencion::getServicio() { return this->servicio; }

string Atencion::resumen() {
    return "Nombre: " + this->nombre + " | Edad: " + to_string(this->edad) + " | Departamento: " + this->servicio;
}

Atencion::~Atencion() {}
