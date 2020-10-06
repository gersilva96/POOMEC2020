#include <iostream>
#include <string>
#include <ctime>
#include "Movil.h"
using namespace std;

class Autonomo : public Movil {
    // Inicializo los atributos como privados
    private:
        int capacidadBateria, indicadorDeCarga, constanteDeDescarga;

    //Métodos públicos
    public:
        // Constructor único
        Autonomo(string nombre, int limiteX, int limiteY, int capacidad, int consumo) : Movil(nombre, limiteX, limiteY) {
            this->capacidadBateria = capacidad;
            this->indicadorDeCarga = capacidad;
            this->constanteDeDescarga = consumo;
        };

        // Función moverse de la clase derivada
        void moverse() {
            srand(time(NULL));
            cout << "La posición inicial de " << this->getNombre() << " es: (" << this->getPosicionX() << "," << this->getPosicionY() << ")" << endl;
            cout << "La capacidad de " << this->getNombre() << " es de " << this->capacidadBateria << " mAh" << endl;
            cout << "Cada movimiento utiliza " << this->constanteDeDescarga << " mAh" << endl << endl;
            while (this->indicadorDeCarga >= this->constanteDeDescarga) {
                int hacia = rand() % 4 + 1;
                string direccion = Movil::moverse(hacia);
                this->indicadorDeCarga -= this->constanteDeDescarga;
                cout << direccion << endl;
                cout << "Las coordenadas de la posición actual de " << this->getNombre() << " son: (" << this->getPosicionX() << "," << this->getPosicionY() << ")" << endl;
                cout << "Distancia recorrida hasta el momento: " << this->getDistanciaRecorrida() << " unidades" << endl;
                cout << "Carga restante: " << this->indicadorDeCarga << " mAh" << endl << endl;
            };
            cout << Movil::moverse(TERMINAR) << endl;
            cout << "Las coordenadas de la posición final de " << this->getNombre() << " son: (" << this->getPosicionX() << "," << this->getPosicionY() << ")" << endl;
            cout << "Distancia recorrida total: " << this->getDistanciaRecorrida() << " unidades" << endl;
            cout << "Carga restante final: " << this->indicadorDeCarga << " mAh" << endl << endl;
        };
};