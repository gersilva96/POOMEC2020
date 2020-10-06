from random import randint
from math import sqrt, pow

class Ejercicio:
    def __init__(self):
        self.radio = 0
        self.height = 768
        self.width = 1024
        self.porcentaje = 0

    def setRadio(self):
        radioTemp = 0
        while (radioTemp < 50 or radioTemp > 600):
            radioTemp = int(input("Ingrese el radio (entre 50 y 600): "))
        self.radio = radioTemp

    def setPorcentaje(self):
        self.setRadio()
        suma = 0
        count = 0
        X = []
        Y = []
        while count < 1000:
            X.append(randint(0, self.width-1))
            Y.append(randint(0, self.height-1))
            circ = sqrt((pow(X[count]-(self.width/2),2))+(pow(Y[count]-(self.height/2),2)))
            if circ <= self.getRadio():
                suma += 1
            count += 1
        self.porcentaje = (suma / 1000) * 100

    def getRadio(self):
        return self.radio

    def getPorcentaje(self):
        return self.porcentaje