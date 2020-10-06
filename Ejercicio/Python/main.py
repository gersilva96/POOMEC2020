from ejercicio import Ejercicio

ejercicio = Ejercicio()

ejercicio.setPorcentaje()
radio = ejercicio.getRadio()
porcentaje = ejercicio.getPorcentaje()
print("\nEl porcentaje de aciertos dentro del círculo de radio " + str(radio) + " es de " + str(porcentaje) + "%")