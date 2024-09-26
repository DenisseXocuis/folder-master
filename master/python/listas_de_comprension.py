#crear listas basadas en una secuencia existente  en una sola linea de codigo

lista = [1,2,3,4,5]
cuadrados = [x ** 2 for x in lista if x % 2 == 0]
print(cuadrados)