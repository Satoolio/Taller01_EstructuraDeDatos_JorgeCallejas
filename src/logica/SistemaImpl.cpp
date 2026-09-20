#include "SistemaImpl.h"
#include <iostream>
#include <cctype>

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

int SistemaImpl::cantidadEnEspera() {
    return this->cola.getSize();
}

Servicio* SistemaImpl::buscarServicio(string nombre) {
    for (int i = 0; i < this->servicios.getSize(); i++) {
        if (this->servicios.get(i)->getNombre() == nombre) return this->servicios.get(i);
    }
    return nullptr;
}

void SistemaImpl::mostrarCola() {
    cout << endl << "=== PACIENTES EN ESPERA ===" << endl;
    if (this->cola.isEmpty()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }
    for (int i = 0; i < this->cola.getSize(); i++) {
        Paciente* p = this->cola.get(i);
        cout << (i + 1) << ". " << p->getId() << " - " << p->getNombre() << endl;
    }
}

void SistemaImpl::atender(int cantidad) {
    if (this->cola.isEmpty()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }
    if (cantidad > this->cola.getSize()) {
        cout << "Solo hay " << this->cola.getSize() << " pacientes en espera, se atenderan todos." << endl;
        cantidad = this->cola.getSize();
    }

    cout << endl << "=== ATENDIENDO PACIENTES ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (i > 0) cout << endl;
        Paciente* p = this->cola.front();
        this->cola.pop();

        Servicio* s = this->buscarServicio(p->getServicio());
        s->agregarPaciente(p);
        this->historial.push(Atencion(p->getId(), p->getNombre(), p->getEdad(), s->getNombre()));

        cout << "ID: " << p->getId() << endl;
        cout << "Nombre: " << p->getNombre() << endl;
        cout << "Edad: " << p->getEdad() << endl;
        cout << "Servicio: " << p->getServicio() << endl << endl;
        cout << "Paciente enviado a " << s->getNombre() << "." << endl;
    }
}

void SistemaImpl::mostrarServicios() {
    cout << endl << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    for (int i = 0; i < this->servicios.getSize(); i++) {
        cout << (i + 1) << ". " << this->servicios.get(i)->getNombre() << endl;
    }
}

void SistemaImpl::mostrarServicio(int numero) {
    if (numero < 1 || numero > this->servicios.getSize()) {
        cout << "Departamento invalido" << endl;
        return;
    }

    Servicio* s = this->servicios.get(numero - 1);
    string titulo = s->getNombre();
    for (char& c : titulo) c = toupper(c);

    cout << endl << "=== ESTADO " << titulo << " ===" << endl;
    cout << "Pacientes en el departamento de " << s->getNombre() << ": " << s->getCantidadPacientes() << endl;
    for (int i = 0; i < s->getCantidadPacientes(); i++) {
        Paciente* p = s->getPaciente(i);
        cout << p->getNombre() << " (" << p->getEdad() << ")" << endl;
    }
}

void SistemaImpl::mostrarHistorial() {
    cout << endl << "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << endl << endl;
    if (this->historial.isEmpty()) {
        cout << "No hay atenciones registradas todavia." << endl;
        return;
    }
    for (int i = 0; i < this->historial.getSize(); i++) {
        cout << this->historial.get(i).resumen() << endl;
    }
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
