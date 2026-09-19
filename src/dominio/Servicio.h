#pragma once
#include <string>
#include "Paciente.h"
#include "../estructuras/List.h"
using namespace std;

class Servicio {
private:
    string nombre;
    List<Paciente*> pacientes;
public:
    Servicio(string nombre);

    string getNombre();
    int getCantidadPacientes();
    Paciente* getPaciente(int index);
    Paciente* buscarPaciente(string id);
    void agregarPaciente(Paciente* paciente);

    ~Servicio();
};
