[![Fecha de Vencimiento de la Asignación](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Abrir en Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13628923)

# Práctica 4: Algoritmos de ordenamiento

## Resumen de los resultados (paso 5 del Procedimiento)

El paso No.5 de la práctica nos dice: "Para cada valor de n y algoritmo, calcula el promedio y la desviación estándar del tiempo de ejecución. Escribe en una tabla estos resultados."

Al comenzar a calcular estos resultados para cada valor de n, nos podemos dar cuenta de que, si bien la computadora es capaz de hacer los ordenamientos rápidamente, llega un punto donde simplemente no da para más y termina cancelando el proceso. En el caso de mi computadora, no fue capaz de pasar del valor de 50,000 en n. Podemos observar los tiempos en la siguiente tabla con los resultados de tiempo y desviación estándar de cada tipo de ordenamiento:

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/2863c145-bdb4-4d59-970b-2b5d3ecd4614)

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/c7b0ba8f-ae47-403b-9039-5c6fc1fb9836)

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/ac1f5512-9393-45be-b471-61cd61cb5e90)

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/37213a21-e3f2-447d-8b92-3ace59c201e5)

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/13c45171-8e6a-4095-8d0d-d4969bcfc9f5)

En general, podemos observar cómo en los resultados los tiempos de ejecución van aumentando poco a poco, esto es debido a que el programa tiene que ejecutar una mayor cantidad de algoritmos de ordenamiento, causando que se demore más cada vez.

## Gráficas del resumen de los resultados (paso 6 del Procedimiento)

El paso No.6 de la práctica nos dice: "Para tener más información, es conveniente graficar los resultados anteriores, comparando el tiempo de ejecución de cada algoritmo."

n=5
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/cf688de8-70a3-4fe1-a2ff-5fefa942e3d7)

n=1000
![GrafiaTiempos](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/ca84951a-48c0-42f6-a191-822d3a89ae5d)

No incluyo gráficas con un n mayor a 10000 porque mi computadora no fue capaz de realizar los ordenamientos.

## Análisis de los resultados obtenidos

Pude darme cuenta de que después de realizar los ordenamientos con todos los algoritmos, el algoritmo llamado "Bubble sort" tarda más que los demás ordenamientos, mientras que "Quick sort" es el que tarda menos de todos. Me parece curioso cómo puede cambiar tanto el tiempo que tardan estos algoritmos considerando que en la programación siempre se busca la mayor eficacia posible.

![GraficaPromDesv](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-Shadic1212/assets/89264651/1b5a19dc-2392-4ade-b0df-c484a9129c5e)

Asimismo, con el pasar del tiempo y observando los resultados de las ejecuciones, llegué a la conclusión de que si el algoritmo no es eficaz, no debería ser usado, ya que esto puede causar problemas con la ejecución del programa.

## Conclusiones

Después de llevar a cabo esta práctica, puedo concluir que los algoritmos de ordenamiento que nos dan son para darnos cuenta de que hay algoritmos más eficaces que otros para este tipo de ejercicios. Esto me lleva a pensar que al realizar un proyecto de programación siempre se debe buscar la mayor eficacia posible para evitar que las computadoras se estanquen buscando la máxima eficacia posible, hablo de la famosa "optimización".

