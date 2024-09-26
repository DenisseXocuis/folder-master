# args, recoge todos los argumentos que pasemos en una función y almacenarlos en una tupla, forma indeterminada de parámetros



def calcular_media(*numeros): 
    suma = sum(numeros)
    cant = len(numeros)
    media = suma / cant
    return media

print("Media :)", calcular_media(10,20,30,40))

def sum_3(x):
    return x + 3

sumar = lambda x: x + 3
print("Sumar 3 a un num:", sumar(5))