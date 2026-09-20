# Taller 1 - Estructura de Datos

## Integrante
Jorge Enrique Callejas Olivares | 21.926.182-9 | Satoolio | ICI

## Descripción
Sistema de gestión de pacientes del Hospital Marmaja, hecho en C++. Lee los pacientes
desde un archivo de texto, los deja en una cola (FIFO), los deriva al servicio que
corresponde y guarda cada atención en un historial (pila, LIFO). La lista enlazada,
la cola y la pila están hechas a mano con nodos y punteros, sin usar la STL.

## Estructura del proyecto
```
Taller01_EstructuraDeDatos_JorgeCallejas/
├── pacientes.txt
└── src/
    ├── main.cpp                 (lectura del archivo y menú)
    ├── dominio/                 Persona, Paciente, Servicio, Atencion
    ├── estructuras/             Node.h, List.h, Queue.h, Stack.h
    └── logica/                  Sistema.h, SistemaImpl.h / SistemaImpl.cpp
```

## Compilar y ejecutar
```bash
git clone https://github.com/Satoolio/Taller01_EstructuraDeDatos_JorgeCallejas
cd Taller01_EstructuraDeDatos_JorgeCallejas
g++ -std=c++17 src/main.cpp src/dominio/Persona.cpp src/dominio/Paciente.cpp src/dominio/Servicio.cpp src/dominio/Atencion.cpp src/logica/SistemaImpl.cpp -o hospital
./hospital
```
En Windows se ejecuta con `.\hospital.exe`. El programa se corre desde la carpeta raíz
(ahí está `pacientes.txt`), o se le pasa otra ruta: `./hospital otro_archivo.txt`.

## Archivo de entrada
Una línea por paciente: `ID;Nombre;Edad;Servicio`, por ejemplo `001;Juan Perez;25;Cardiologia`.
Se ignora la línea (avisando su número) si no tiene 4 campos, si el id o el nombre están
vacíos, si la edad no es un número entre 0 y 120, si el servicio no existe o si el id ya
está repetido. Si el archivo no existe, el programa avisa y termina.

## Menú
1. Atender pacientes: muestra la cola y pide cuántos atender; cada uno pasa de la cola a su servicio y al historial.
2. Ver departamento: lista los 8 servicios y muestra los pacientes del elegido.
3. Revisar historial de atención: de la última atención a la primera.
4. Salir: termina el programa y libera la memoria.
5. Buscar paciente: por id, en la cola o en los servicios.

## Estructuras hechas a mano
- `Node<T>` y `List<T>`: lista de servicios y lista de pacientes de cada servicio.
- `Queue<T>`: pacientes en espera.
- `Stack<T>`: historial de atenciones.

## POO y punteros
- Herencia: `Persona` (base) y `Paciente` (derivada). `Sistema` es una clase abstracta que implementa `SistemaImpl`.
- Aritmética de punteros: en `SistemaImpl`, al crear los 8 servicios y al validar el
  servicio de cada línea, se recorre el arreglo de nombres con `*p` y `p++`.
- Cada clase libera su memoria dinámica en su destructor.

## Servicios
Urgencias, Medicina General, Cardiologia, Neurologia, Traumatologia, Cirugia, Pediatria, Hospitalizacion.
