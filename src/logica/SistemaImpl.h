#pragma once
#include <string>
#include "Sistema.h"
#include "../dominio/Paciente.h"
#include "../dominio/Servicio.h"
#include "../dominio/Atencion.h"
#include "../estructuras/List.h"
#include "../estructuras/Queue.h"
#include "../estructuras/Stack.h"
using namespace std;

class SistemaImpl : public Sistema {
private:
    string nombres[8];
    List<Servicio*> servicios;
    Queue<Paciente*> cola;
    Stack<Atencion> historial;
public:
    SistemaImpl();

    bool servicioValido(string nombre);
    bool existePaciente(string id);
    void agregarPaciente(string id, string nombre, int edad, string servicio);

    void mostrarCola();
    void atender(int cantidad);
    void mostrarServicios();
    void mostrarServicio(int numero);
    void mostrarHistorial();
    void buscarPaciente(string id);

    ~SistemaImpl();
};
