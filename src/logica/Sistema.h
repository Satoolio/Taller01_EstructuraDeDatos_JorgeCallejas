#pragma once
#include <string>
using namespace std;

class Sistema {
public:
    virtual bool servicioValido(string nombre) = 0;
    virtual bool existePaciente(string id) = 0;
    virtual void agregarPaciente(string id, string nombre, int edad, string servicio) = 0;
    virtual int cantidadEnEspera() = 0;

    virtual void mostrarCola() = 0;
    virtual void atender(int cantidad) = 0;

    // lo de abajo se implementa en el proximo commit
    virtual void mostrarServicios() = 0;
    virtual void mostrarServicio(int numero) = 0;
    virtual void mostrarHistorial() = 0;
    virtual void buscarPaciente(string id) = 0;

    virtual ~Sistema() {}
};
