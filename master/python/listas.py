#creación de listas

frutas = ["manzanita", "bananita", "naranjita"]

print(frutas)

#append - agrega un elemento al final de la lista
#insert - inserta en una posición específica
#remove - elimina la aparicion de un elemento
#pop - elimina y devuelve el elemento en una posición específica de la lista
#sort - ordena de forma ascendente
#reverse - invierte el orden

frutas.append("pera")
print("Función append:", frutas)

frutas.insert(2, "uva")
print("Función insert:", frutas)

frutas.remove("pera")
print("Función remove", frutas)

fruta_eliminada = frutas.pop(2)
print("Función pop", frutas)
print(fruta_eliminada)

frutas.sort()
print(frutas)

frutas.reverse()
print(frutas)