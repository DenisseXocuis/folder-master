import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# velocidades
velocidades = [102, 98, 105, 99, 100, 97, 101, 96, 103, 98]

# calcular la media y la desviación estándar de las velocidades
media = np.mean(velocidades)
desviacion_estandar = np.std(velocidades)

# definir el valor crítico y el valor de la hipótesis nula
valor_critico = 100
hipotesis_nula = 100

# establecer el estilo de la gráfica
sns.set(style="whitegrid")

# definir la distribución gaussiana
x = np.linspace(80, 120, 1000)
y = (1 / (desviacion_estandar * np.sqrt(2 * np.pi))) * np.exp(-0.5 * ((x - media) / desviacion_estandar) ** 2)

# graficar la distribución gaussiana
plt.figure(figsize=(10, 6))
plt.plot(x, y, color='skyblue', label='Distribución Gaussiana')
plt.fill_between(x, y, where=(x <= valor_critico), color='skyblue', alpha=0.5)

plt.axvline(x=valor_critico, color='green', linestyle='dashed', linewidth=1, label='Valor Crítico')
plt.axvline(x=hipotesis_nula, color='red', linestyle='dashed', linewidth=1, label='Hipótesis Nula')

plt.xlabel('Velocidad (Mbps)', fontsize=14)
plt.ylabel('Densidad de Probabilidad', fontsize=14)
plt.title('Gráfica de Gauss y datos de la Hipótesis Nula', fontsize=16)
plt.legend(fontsize=12)

# mostrar la gráfica
plt.show()