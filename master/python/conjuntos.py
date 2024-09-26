#set, estructura de datos mutable y no ordenada para almacenar una colección de elementos únicos


set1 = {1,2,3}
set2 = {3,4,5}

# unión |
# intersección &
# diferencia -
# diferencia simétrica ^

union = set1 | set2 
print(union)

inter = set1 & set2
print(inter)

diff = set1 - set2
print(diff)

diff_s = set1 ^ set2
print(diff_s)

#métodos
# add(elemento): agrega un elemento al conjunto.
# remove(elemento): elimina un elemento del conjunto. Si el elemento no existe, genera un error.
# discard(elemento): elimina un elemento del conjunto si está presente. Si el elemento no existe, no hace nada.
# clear(): elimina todos los elementos del conjunto.
