#pragma once
#include <string>
#include "Persona.h"
using namespace std;

class Paciente : public Persona {
private:
    string id;
    string servicio;
public:
    Paciente(string id, string nombre, int edad, string servicio);

    string getId();
    string getServicio();
    string resumen();

    ~Paciente();
};
