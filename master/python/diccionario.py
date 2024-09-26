#estructura de datos MUTABLE y no ordenada que permite almacenar pares de CLAVE-VALOR

persona = {"nombre": "Juan", "edad": 25, "ciudad": "Madrid"}

print(persona["nombre"])

# keys(): devuelve una vista de todas las claves del diccionario.
# values(): devuelve una vista de todos los valores del diccionario.
# items(): devuelve una vista de todos los pares clave-valor del diccionario.
# update(otro_diccionario): actualiza el diccionario con los pares clave-valor de otro diccionario.

print(persona.keys())
print(persona.values())
print(persona.items())

persona.update({"profesion": "Ingeniero"})

print(persona)
