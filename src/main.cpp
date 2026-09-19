#include <iostream>
#include <fstream>
#include <string>
#include "logica/SistemaImpl.h"
using namespace std;

bool esNumero(string texto) {
    if (texto == "") return false;
    for (char c : texto) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool dividir(string linea, string campos[]) {
    int cantidad = 0;
    string texto = "";
    for (char c : linea) {
        if (c == ';') {
            if (cantidad == 3) return false;
            campos[cantidad] = texto;
            cantidad++;
            texto = "";
        } else {
            texto += c;
        }
    }
    if (cantidad != 3) return false;
    campos[3] = texto;
    return true;
}

string validarLinea(Sistema* sistema, string linea, string campos[]) {
    if (!dividir(linea, campos)) return "se esperaban 4 campos separados por ;";
    if (campos[0] == "" || campos[1] == "") return "id o nombre vacio";
    if (!esNumero(campos[2]) || campos[2].size() > 3 || stoi(campos[2]) > 120) return "edad invalida";
    if (!sistema->servicioValido(campos[3])) return "servicio no valido (" + campos[3] + ")";
    if (sistema->existePaciente(campos[0])) return "paciente duplicado (id " + campos[0] + ")";
    return "";
}

bool leerArchivo(Sistema* sistema, string ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return false;
    }

    string linea;
    int numero = 0;
    int cargados = 0;
    int rechazados = 0;

    while (getline(archivo, linea)) {
        numero++;
        if (!linea.empty() && linea.back() == '\r') linea.pop_back();
        if (linea == "") continue;

        string campos[4];
        string error = validarLinea(sistema, linea, campos);
        if (error != "") {
            cout << "Linea " << numero << " ignorada: " << error << endl;
            rechazados++;
            continue;
        }

        sistema->agregarPaciente(campos[0], campos[1], stoi(campos[2]), campos[3]);
        cargados++;
    }
    archivo.close();

    cout << "Pacientes cargados: " << cargados << " | Lineas ignoradas: " << rechazados << endl;
    return true;
}

void menu(Sistema* sistema) {
    string opcion = "";
    while (opcion != "4") {
        cout << endl << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "5. Buscar paciente" << endl;
        cout << endl << "Seleccionar opcion: ";
        if (!(cin >> opcion)) break;

        if (opcion == "1") {
            sistema->mostrarCola();
            // pedir cuantos atender y llamar a sistema->atender(cantidad)
        } else if (opcion == "2") {
            sistema->mostrarServicios();
            // pedir cual ver y llamar a sistema->mostrarServicio(numero)
        } else if (opcion == "3") {
            sistema->mostrarHistorial();
        } else if (opcion == "5") {
            // pedir un id y llamar a sistema->buscarPaciente(id)
        } else if (opcion != "4") {
            cout << "Opcion invalida" << endl;
        }
    }
    cout << endl << "Hasta luego :D." << endl;
}

int main(int argc, char* argv[]) {
    string ruta = "pacientes.txt";
    if (argc > 1) ruta = argv[1];

    Sistema* sistema = new SistemaImpl();
    int resultado = 0;
    if (leerArchivo(sistema, ruta)) {
        menu(sistema);
    } else {
        resultado = 1;
    }
    delete sistema;
    return resultado;
}
