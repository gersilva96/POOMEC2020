from classes.Movil import Movil,dirEnum
from random import randint

class Autonomo(Movil):
    def __init__(self, nombre, limiteX, limiteY, capacidad, consumo):
        super().__init__(nombre, limiteX, limiteY)
        self.capacidadBateria = capacidad
        self.indicadorDeCarga = capacidad
        self.constanteDeDescarga = consumo

    def moverse(self):
        cadena = ""
        cadena += "La posición inicial de " + self.getNombre() + " es: (" + str(self.getPosicionX()) + "," + str(self.getPosicionY()) + ")\n"
        cadena += "La capacidad de " + self.getNombre() + " es de " + str(self.capacidadBateria) + " mAh\n"
        cadena += "Cada movimiento utiliza " + str(self.constanteDeDescarga) + " mAh\n\n"
        while (self.indicadorDeCarga >= self.constanteDeDescarga):
            hacia = randint(1, 4)
            direccion = super().moverse(hacia)
            self.indicadorDeCarga -= self.constanteDeDescarga
            cadena += direccion + "\n"
            cadena += "Las coordenadas de la posición actual de " + self.getNombre() + " son: (" + str(self.getPosicionX()) + "," + str(self.getPosicionY()) + ")\n"
            cadena += "Distancia recorrida hasta el momento: " + str(self.getDistanciaRecorrida()) + " unidades\n"
            cadena += "Carga restante: " + str(self.indicadorDeCarga) + " mAh\n\n"
        cadena += super().moverse(0) + "\n"
        cadena += "Las coordenadas de la posición final de " + self.getNombre() + " son: (" + str(self.getPosicionX()) + "," + str(self.getPosicionY()) + ")\n"
        cadena += "Distancia recorrida total: " + str(self.getDistanciaRecorrida()) + " unidades\n"
        cadena += "Carga restante final: " + str(self.indicadorDeCarga) + " mAh\n"
        return cadena