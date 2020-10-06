from enum import Enum
from classes.Grilla import Grilla
from classes.Movil import Movil,dirEnum
from classes.Autonomo import Autonomo
from random import randint

class randEnum(Enum):
    CAPACIDAD = 0
    CONSUMO = 1

def numeroAleatorio(tipo):
    if tipo == randEnum.CAPACIDAD.value:
        return randint(200, 300)
    elif tipo == randEnum.CONSUMO.value:
        return randint(20, 40)
    else:
        return 0

# Genero la grilla plana
ancho = int(input("Ingrese el ancho deseado de la grilla: "))
alto = int(input("Ingrese el alto deseado de la grilla: "))
grilla = Grilla(ancho, alto)
anchoGrilla = grilla.getAncho()
altoGrilla = grilla.getAlto()

# Generación del móvil manual
nombreMovilManual = input("\nIngrese el nombre del móvil manual: ")
movilManual = Movil(nombreMovilManual, anchoGrilla, altoGrilla)

# Movimientos del móvil manual
print("\nLa posición inicial de", movilManual.getNombre(), "es: (" + str(movilManual.getPosicionX()) + "," + str(movilManual.getPosicionY()) + ")\n")
seguirMoviendo = True
while seguirMoviendo:
    print("Ingrese la dirección de movimiento:")
    print(str(dirEnum.ADELANTE.value) + ": mover hacia ADELANTE")
    print(str(dirEnum.ATRAS.value) + ": mover hacia ATRÁS")
    print(str(dirEnum.DERECHA.value) + ": mover hacia la DERECHA")
    print(str(dirEnum.IZQUIERDA.value) + ": mover hacia la IZQUIERDA")
    print(str(dirEnum.TERMINAR.value) + ": terminar\n")
    movimiento = int(input("Movimiento: "))
    direccionMovimiento = movilManual.moverse(movimiento)
    print("")
    print(direccionMovimiento)
    print("Las coordenadas de la posición actual de", movilManual.getNombre(), "son: (" + str(movilManual.getPosicionX()) + "," + str(movilManual.getPosicionY()) + ")")
    print("Distancia recorrida hasta el momento:", movilManual.getDistanciaRecorrida(), "unidades\n")
    if (movimiento == dirEnum.TERMINAR.value):
        seguirMoviendo = False

print("----------------------------------------\n")

movilesAutonomos = []
for i in range(3):
    nombreMovilAutonomo = input("Ingresá el nombre del " + str(i+1) + "° móvil autónomo: ")
    print("")
    movilesAutonomos.append(Autonomo(nombreMovilAutonomo, anchoGrilla, altoGrilla, numeroAleatorio(randEnum.CAPACIDAD.value), numeroAleatorio(randEnum.CONSUMO.value)))
    print(movilesAutonomos[i].moverse())
    print("----------------------------------------\n")