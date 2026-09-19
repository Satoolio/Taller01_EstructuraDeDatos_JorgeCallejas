#include "Servicio.h"

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

string Servicio::getNombre() { return this->nombre; }
int Servicio::getCantidadPacientes() { return this->pacientes.getSize(); }
Paciente* Servicio::getPaciente(int index) { return this->pacientes.get(index); }

Paciente* Servicio::buscarPaciente(string id) {
    for (int i = 0; i < this->pacientes.getSize(); i++) {
        Paciente* actual = this->pacientes.get(i);
        if (actual->getId() == id) return actual;
    }
    return nullptr;
}

void Servicio::agregarPaciente(Paciente* paciente) {
    this->pacientes.insertLast(paciente);
}

Servicio::~Servicio() {
    for (int i = 0; i < this->pacientes.getSize(); i++) {
        delete this->pacientes.get(i);
    }
}
