from time import time
from random import randint
from enum import Enum

class dirEnum(Enum):
    TERMINAR = 0
    ADELANTE = 1
    ATRAS = 2
    DERECHA = 3
    IZQUIERDA = 4

class Movil:
    # Constructor
    def __init__(self, nombre, limiteX, limiteY):
        self.tiempoInicial = int(time())
        self.nombre = nombre
        self.distanciaTotal = 0
        self.coordenadaX = randint(0, int(limiteX)-1)
        self.coordenadaY = randint(0, int(limiteY)-1)
        self.limiteX = limiteX
        self.limiteY = limiteY

    # Getters
    def getNombre(self):
        return self.nombre
    def getPosicionX(self):
        return self.coordenadaX
    def getPosicionY(self):
        return self.coordenadaY
    def getDistanciaRecorrida(self):
        return self.distanciaTotal

    # Métodos de movimiento
    def moverse(self, hacia):
        if hacia == dirEnum.ADELANTE.value:
            return self.haciaAdelante()
        elif hacia == dirEnum.ATRAS.value:
            return self.haciaAtras()
        elif hacia == dirEnum.DERECHA.value:
            return self.haciaDerecha()
        elif hacia == dirEnum.IZQUIERDA.value:
            return self.haciaIzquierda()
        elif hacia == dirEnum.TERMINAR.value:
            return self.terminar()
        else:
            return self.ninguna()

    def haciaAdelante(self):
        if self.getPosicionY() < (self.limiteY - 1):
            self.coordenadaY += 1
            self.distanciaTotal += 1
            return "Se movió hacia ADELANTE"
        else:
            return "No se puede mover hacia adelante, está en el límite"

    def haciaAtras(self):
        if self.getPosicionY() > 0:
            self.coordenadaY -= 1
            self.distanciaTotal += 1
            return "Se movió hacia ATRÁS"
        else:
            return "No se puede mover hacia atrás, está en el límite"

    def haciaDerecha(self):
        if self.getPosicionX() < (self.limiteX - 1):
            self.coordenadaX += 1
            self.distanciaTotal += 1
            return "Se movió hacia la DERECHA"
        else:
            return "No se puede mover hacia la derecha, está en el límite"

    def haciaIzquierda(self):
        if self.getPosicionX() > 0:
            self.coordenadaX -= 1
            self.distanciaTotal += 1
            return "Se movió hacia la IZQUIERDA"
        else:
            return "No se puede mover hacia la izquierda, está en el límite"

    def terminar(self):
        cadena = "Movimientos finalizados\n"
        tiempoFinal = int(time())
        diffTiempo = tiempoFinal - self.tiempoInicial
        cadena += "Tiempo total en movimiento: " + str(diffTiempo) + " segundos"
        return cadena

    def ninguna(self):
        return "No se movió hacia ninguna dirección"