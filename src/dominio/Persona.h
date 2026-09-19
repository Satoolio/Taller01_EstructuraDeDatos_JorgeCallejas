#pragma once
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad);

    string getNombre();
    int getEdad();
    virtual string resumen();

    virtual ~Persona();
};
