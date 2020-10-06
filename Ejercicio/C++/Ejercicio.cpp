#include <iostream>
#include <ctime>
#include <cmath>
#include "Ejercicio.h"

using namespace std;

void Ejercicio::setRadio() {
	int radioTemp;
	do {
		cout << "Ingrese el radio (entre 50 y 600): ";
		cin >> radioTemp;
	} while (radioTemp < 50 || radioTemp > 600);
	radio = radioTemp;
	cout << endl;
}

int Ejercicio::getRadio() {
	return radio;
}

void Ejercicio::setPorcentaje() {
	setRadio();
    srand(time(NULL));
	int suma = 0, circ, X[1000], Y[1000];
	for (int i = 0; i < 1000; i++) {
		X[i] = (rand() % width);
		Y[i] = (rand() % height);
		circ = sqrt((pow(X[i]-(width/2),2))+(pow(Y[i]-(height/2),2)));
		if (circ <= getRadio()) {
			suma++;
		}
	}
	porcentaje = (float(suma) / 1000.0) * 100.0;
}

float Ejercicio::getPorcentaje() {
    return porcentaje;
}