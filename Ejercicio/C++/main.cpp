#include <iostream>
#include "Ejercicio.h"

using namespace std;

int main(){
    Ejercicio* ejercicio = new Ejercicio();
    ejercicio->setPorcentaje();
    float porcentaje = ejercicio->getPorcentaje();
    cout << "El porcentaje de aciertos dentro del círculo de radio " << ejercicio->getRadio() << " es de " << porcentaje << "%" << endl;
    return 0;
}