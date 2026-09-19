#pragma once
#include <string>
using namespace std;

class Atencion {
private:
    string id;
    string nombre;
    int edad;
    string servicio;
public:
    Atencion(string id, string nombre, int edad, string servicio);

    string getId();
    string getNombre();
    int getEdad();
    string getServicio();
    string resumen();

    ~Atencion();
};
