#include "SistemaImpl.h"

SistemaImpl::SistemaImpl() {
    this->nombres[0] = "Urgencias";
    this->nombres[1] = "Medicina General";
    this->nombres[2] = "Cardiologia";
    this->nombres[3] = "Neurologia";
    this->nombres[4] = "Traumatologia";
    this->nombres[5] = "Cirugia";
    this->nombres[6] = "Pediatria";
    this->nombres[7] = "Hospitalizacion";

    for (string* p = this->nombres; p < this->nombres + 8; p++) {
        this->servicios.insertLast(new Servicio(*p));
    }
}

bool SistemaImpl::servicioValido(string nombre) {
    for (string* p = this->nombres; p < this->nombres + 8; p++) {
        if (*p == nombre) return true;
    }
    return false;
}

bool SistemaImpl::existePaciente(string id) {
    for (int i = 0; i < this->cola.getSize(); i++) {
        if (this->cola.get(i)->getId() == id) return true;
    }
    for (int i = 0; i < this->servicios.getSize(); i++) {
        if (this->servicios.get(i)->buscarPaciente(id) != nullptr) return true;
    }
    return false;
}

void SistemaImpl::agregarPaciente(string id, string nombre, int edad, string servicio) {
    this->cola.push(new Paciente(id, nombre, edad, servicio));
}

void SistemaImpl::mostrarCola() {
    // mostrar los pacientes en espera con su numero, id y nombre
}

void SistemaImpl::atender(int) {
    // sacar cantidad pacientes de la cola, mandarlos a su servicio y guardar cada atencion en el historial
}

void SistemaImpl::mostrarServicios() {
    // mostrar la lista numerada de los 8 servicios
}

void SistemaImpl::mostrarServicio(int) {
    // mostrar cuantos pacientes tiene el servicio numero y sus nombres con edad
}

void SistemaImpl::mostrarHistorial() {
    // mostrar las atenciones desde la ultima a la primera
}

void SistemaImpl::buscarPaciente(string) {
    // buscar el id en la cola y en los servicios y mostrar sus datos
}

SistemaImpl::~SistemaImpl() {
    while (!this->cola.isEmpty()) {
        delete this->cola.front();
        this->cola.pop();
    }
    for (int i = 0; i < this->servicios.getSize(); i++) {
        delete this->servicios.get(i);
    }
}
