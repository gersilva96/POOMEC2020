#include <iostream>
#include <ctime>
#include "classes/Grilla.h"
#include "classes/Movil.h"
#include "classes/Autonomo.h"
using namespace std;

enum numeroAleatorio {
    CAPACIDAD,
    CONSUMO
};

int numeroAleatorio(int tipo);

int main() {
    srand(time(NULL));
    //Genero la grilla plana
    int ancho, alto;
    cout << "Ingrese el ancho deseado de la grilla: ";
    cin >> ancho;
    cout << "Ingrese el alto deseado de la grilla: ";
    cin >> alto;
    cout << endl;
    Grilla *grilla = new Grilla(ancho, alto);
    int anchoGrilla = grilla ->getAncho();
    int altoGrilla = grilla->getAlto();

    // Generación del móvil manual
    string nombreMovilManual;
    cout << "Ingrese el nombre del móvil manual: ";
    cin >> nombreMovilManual;
    cout << endl;
    Movil* movilManual = new Movil(nombreMovilManual, anchoGrilla, altoGrilla);

    // Movimientos del móvil manual
    cout << "La posición inicial de " << movilManual->getNombre() << " es: (" << movilManual->getPosicionX() << "," << movilManual->getPosicionY() << ")" << endl << endl;
    int movimiento;
    string direccionMovimiento;
    bool seguirMoviendo = true;
    while (seguirMoviendo) {
        cout << "Ingrese la dirección de movimiento:" << endl
        << ADELANTE << ": mover hacia ADELANTE" << endl
        << ATRAS << ": mover hacia ATRÁS" << endl
        << DERECHA << ": mover hacia la DERECHA" << endl
        << IZQUIERDA << ": mover hacia la IZQUIERDA" << endl
        << TERMINAR << ": Terminar" << endl << endl;
        cout << "Movimiento: ";
        cin >> movimiento;
        direccionMovimiento = movilManual->moverse(movimiento);
        cout << endl << direccionMovimiento << endl;
        cout << "Las coordenadas de la posición actual de " << movilManual->getNombre() << " son: (" << movilManual->getPosicionX() << "," << movilManual->getPosicionY() << ")" << endl;
        cout << "Distancia recorrida hasta el momento: " << movilManual->getDistanciaRecorrida() << " unidades" << endl << endl;
        (movimiento == 0) && (seguirMoviendo = false);
    };

    cout << "----------------------------------------" << endl << endl;

    // Generación de los móviles autónomo
    Autonomo* movilesAutonomos[3];
    for (int i = 0; i < 3; i++) {
        string nombreMovilAutonomo;
        cout << "Ingrese el nombre del " << (i+1) << "° móvil autónomo: ";
        cin >> nombreMovilAutonomo;
        cout << endl;
        movilesAutonomos[i] = new Autonomo(nombreMovilAutonomo, anchoGrilla, altoGrilla, numeroAleatorio(CAPACIDAD), numeroAleatorio(CONSUMO));
        movilesAutonomos[i]->moverse();
        cout << "----------------------------------------" << endl << endl;
    }

    return 0;
};

int numeroAleatorio(int tipo) {
    switch (tipo) {
        case CAPACIDAD:
            return rand() % 100 + 200;
            break;
        case CONSUMO:
            return rand() % 20 + 20;
            break;
        default:
            return 0;
            break;
    };
};