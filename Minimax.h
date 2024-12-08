#pragma once
#include "Tablero.h"

/**
 * @class Minimax
 * @brief Implementa el algoritmo Minimax para la toma de decisiones de la IA en el juego Conecta 4.
 * 
 * Proporciona métodos para ejecutar el algoritmo Minimax con y sin poda alfa-beta, evaluar el estado
 * del tablero, calcular puntajes para líneas específicas, y determinar la mejor jugada para la IA 
 * según el nivel de dificultad.
 */

class Minimax {
    public:

        /**
         * @brief Ejecuta el algoritmo Minimax sin poda alfa-beta.
         * 
         * Calcula el mejor puntaje posible para la IA o el jugador humano dependiendo del turno actual,
         * explorando todas las posibles jugadas sin optimización mediante poda.
         * 
         * @param tablero Estado actual del tablero.
         * @param profundidad Límite de profundidad de búsqueda en el árbol de decisiones.
         * @param esMaximizador Indica si el turno actual es del jugador maximizador (IA).
         * @param dificil Indica si se debe aplicar una evaluación más detallada (nivel difícil).
         * @return El puntaje calculado para la posición actual.
         */

        int minimaxSinPoda(Tablero tablero, int profundidad, bool esMaximizador, bool dificil);

        /**
         * @brief Ejecuta el algoritmo Minimax con poda alfa-beta.
         * 
         * Mejora el rendimiento de Minimax al descartar ramas innecesarias en el árbol de decisiones
         * mediante los valores alfa y beta.
         * 
         * @param tablero Estado actual del tablero.
         * @param profundidad Límite de profundidad de búsqueda en el árbol de decisiones.
         * @param alfa Valor alfa para la poda (mejor opción garantizada del maximizador).
         * @param beta Valor beta para la poda (mejor opción garantizada del minimizador).
         * @param esMaximizador Indica si el turno actual es del jugador maximizador (IA).
         * @param dificil Indica si se debe aplicar una evaluación más detallada (nivel difícil).
         * @return El puntaje calculado para la posición actual.
         */

        int minimaxConPoda(Tablero tablero, int profundidad, int alfa, int beta, bool esMaximizador, bool dificil);

        /**
         * @brief Evalúa el estado actual del tablero.
         * 
         * Asigna un puntaje al tablero basado en el estado actual del juego y el nivel de dificultad:
         * - 100: La IA ha ganado.
         * - -100: El jugador humano ha ganado.
         * - 0: Empate o estado intermedio sin ganador.
         * En nivel difícil, también evalúa posiciones estratégicas para anticipar posibles jugadas.
         * 
         * @param tablero Referencia constante al tablero que se evalúa.
         * @param dificil Indica si se debe aplicar una evaluación más detallada (nivel difícil).
         * @return Un puntaje que representa el estado actual del tablero.
         */

        int evaluarEstado(const Tablero& tablero, bool dificil = true); 

        /**
         * @brief Determina la mejor jugada para la IA.
         * 
         * Utiliza Minimax (con o sin poda alfa-beta según la dificultad) para calcular la columna óptima
         * en la que la IA debe colocar su ficha.
         * 
         * @param tablero Estado actual del tablero.
         * @param dificultad Nivel de dificultad (1: fácil, 2: difícil).
         * @return El índice de la columna recomendada para la jugada.
         */

        int mejorMovimiento(Tablero tablero, int dificultad); 

        /**
         * @brief Evalúa una línea de 4 posiciones en el tablero.
         * 
         * Calcula un puntaje basado en la cantidad de fichas del jugador y celdas vacías en la línea.
         * 
         * @param tablero Referencia constante al tablero que se evalúa.
         * @param fila Índice de la fila inicial de la línea.
         * @param columna Índice de la columna inicial de la línea.
         * @param jugador Identificador del jugador (1 para humano, 2 para IA).
         * @return El puntaje calculado para la línea evaluada.
         */

        int evaluarLinea(const Tablero& tablero, int fila, int columna, int jugador);

        /**
         * @brief Calcula el puntaje de una línea específica.
         * 
         * Asigna un valor a la línea evaluada según el número de fichas del jugador
         * y las celdas vacías disponibles.
         * 
         * @param count Cantidad de fichas del jugador en la línea.
         * @param empty Cantidad de celdas vacías en la línea.
         * @return El puntaje asociado a la línea.
         */

        int calcularPuntuacion(int count, int empty);
};

