## Taller2Estructura

* Integrantes

- Denzel Martín Delgado Urquieta, 21.401.250-2, denzel.delgado@alumnos.ucn.cl, C2
- Pablo Jesús Villarroel Rivera, 21.239.259-6, pablo.villarroel01@alumnos.ucn.cl , C2
- Darwin Mauricio Tapia Urrutia, 21.599.630-1, darwin.tapia@alumnos.ucn.cl, C2

* Ejecutar programa:

- Primero, se debe crear el ejecutable "g++ -std=c++11 main.cpp Juego.cpp Minimax.cpp Tablero.cpp -o main.exe". Luego, para ejecutar el programa debe escribir "./main.exe".

# Juego: Conecta 4

- Es un juego de mesa vertical para dos jugadores, el cual consta en formar una linea de 4 fichas del mismo color para la victoria.

- Reglas:
- Tienes que formar una linea de 4 fichas, ya sea horizontal, vertical o diagonal.
- Como jugador, tu fixha se representa con "X", mientras que la IA será el "O".
- Para ingresar una ficha tendrás que escribir la columna donde deseas colocarlo.

# Representación visual con árbol (primeros tres movimientos):
<p align="center"><img src="https://github.com/DenzelD1/Taller2Estructura/blob/main/arbol%20conecta%204.png"/></p> 

# Algoritmo Minimax
El algoritmo Minimax es una técnica utilizada en juegos de dos jugadores (por ejemplo, ajedrez o cuatro en raya) para tomar decisiones óptimas. Supone que ambos jugadores son perfectos y siempre toman la mejor decisión posible.

Funcionamiento:
- Cada nodo del árbol representa un estado del juego.
- Los nodos hijos representan todos los estados posibles a partir de un movimiento.
- Dos jugadores:
  MAX: Intenta maximizar el puntaje.
  MIN: Intenta minimizar el puntaje.
-Las hojas del árbol se evalúan con una función heurística que asigna un valor.
-El algoritmo recorre el árbol del juego de forma recursiva hasta llegar a las hojas.
MAX elige el valor máximo de sus hijos; MIN elige el valor mínimo.

#Poda alfa-beta
La poda alfa-beta es una optimización del algoritmo Minimax que reduce drásticamente el número de nodos evaluados, donde:
- Alfa (α): El mejor valor que el jugador MAX puede garantizar hasta ese punto.
- Beta (β): El mejor valor que el jugador MIN puede garantizar hasta ese punto.
-Poda: Si se encuentra una rama que no puede influir en la decisión final, se descarta, ahorrando tiempo.

Funcionamiento:
Durante la evaluación de un nodo, si:
- El valor de un nodo MIN es menor o igual a alfa (mejor opción de MAX), se detiene la evaluación.
- El valor de un nodo MAX es mayor o igual a beta (mejor opción de MIN), se detiene la evaluación.

#Complejidad temporal del algoritmo
- Minimax sin poda:
El algoritmo evalúa todos los nodos del árbol, y en cada nivel explora b=7 ramas. Por lo tanto, el número total de nodos explorados es: Nodos evaluados = 𝑏^𝑑 = 7^𝑑

Esto implica que la complejidad temporal es: 𝑂(7^𝑑)

- Minimax con poda:
Mejor Caso:
En el mejor caso, las ramas más prometedoras se evalúan primero, lo que permite maximizar la poda.
La complejidad temporal en el mejor caso es entonces: O(7^(d/2))

Peor Caso:
En el peor caso, las ramas menos prometedoras se evalúan primero, y la poda es ineficaz. Esto equivale a recorrer todo el árbol de juego, lo mismo que el Minimax sin poda: 𝑂(7^𝑑)
