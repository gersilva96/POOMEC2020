#ifndef MOVIL_H
#define MOVIL_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum direccion {    // Enumeración de las direcciones
    TERMINAR,
    ADELANTE,
    ATRAS,
    DERECHA,
    IZQUIERDA
};

class Movil {
    // Inicializo los atributos como protegidos para poder ser accedidos desde las clases derivadas
    protected:
        string nombre;  // Inicializo el nombre, no se puede resetear, solo se define en el constructor
        int coordenadaX, coordenadaY, distanciaTotal;    // Inicializo las coordenadas, la distancia total recorrida y el contador de la cantidad de órdenes recibidas
        int limiteX, limiteY;   // Inicializo los límites recibidos de la grilla
        int tiempoInicial;

    // Métodos públicos
    public:
        // Constructor único
        Movil(string nombre, int limiteX, int limiteY) {
            srand(time(NULL));
            this->tiempoInicial = time(NULL);
            this->nombre = nombre;
            this->distanciaTotal = 0;
            this->coordenadaX = rand() % (limiteX - 1);
            this->coordenadaY = rand() % (limiteY - 1);
            this->limiteX = limiteX;
            this->limiteY = limiteY;
        };

        // Getters
        string getNombre() {
            return this->nombre;
        };
        int getPosicionX() {
            return this->coordenadaX;
        };
        int getPosicionY() {
            return this->coordenadaY;
        };
        int getDistanciaRecorrida() {
            return this->distanciaTotal;
        }

        // Métodos de movimiento
        string moverse(int hacia) {
            switch (hacia) {
                case ADELANTE:
                    return this->haciaAdelante();
                    break;
                case ATRAS:
                    return this->haciaAtras();
                    break;
                case DERECHA:
                    return this->haciaDerecha();
                    break;
                case IZQUIERDA:
                    return this->haciaIzquierda();
                    break;
                case TERMINAR:
                    return this->terminar();
                    break;
                default:
                    return this->ninguna();
                    break;
            };
        };
        string haciaAdelante() {
            if (this->getPosicionY() < (this->limiteY - 1)) {
                this->coordenadaY++;
                this->distanciaTotal++;
                return "Se movió hacia ADELANTE";
            } else {
                return "No se puede mover hacia adelante, está en el límite";
            }
        };
        string haciaAtras() {
            if (this->getPosicionY() > 0) {
                this->coordenadaY--;
                this->distanciaTotal++;
                return "Se movió hacia ATRÁS";
            } else {
                return "No se puede mover hacia atrás, está en el límite";
            }
        };
        string haciaDerecha() {
            if (this->getPosicionX() < (this->limiteX - 1)) {
                this->coordenadaX++;
                this->distanciaTotal++;
                return "Se movió hacia la DERECHA";
            } else {
                return "No se puede mover hacia la derecha, está en el límite";
            }
        };
        string haciaIzquierda() {
            if (this->getPosicionX() > 0) {
                this->coordenadaX--;
                this->distanciaTotal++;
                return "Se movió hacia la IZQUIERDA";
            } else {
                return "No se puede mover hacia la izquierda, está en el límite";
            }
        };
        string terminar() {
            string cadena = "Movimientos finalizados\n";
            int tiempoFinal = time(NULL);
            int diffTiempo = tiempoFinal - this->tiempoInicial;
            cadena += "Tiempo total en movimiento: " + to_string(diffTiempo) + " segundos";
            return cadena;
        };
        string ninguna() {
            return "No se movió hacia ninguna dirección";
        };
};
#endif