#pragma once
#include "Tablero.h"

/**
 * @class Minimax
 * @brief Implementa el algoritmo Minimax para la toma de decisiones de la IA en el juego Conecta 4.
 * 
 * Esta clase proporciona métodos para ejecutar el algoritmo Minimax con y sin poda alfa-beta,
 * evaluar el estado del tablero, y determinar la mejor jugada para la IA según el nivel de dificultad.
 */

class Minimax {
    public:

        /**
         * @brief Ejecuta el algoritmo Minimax sin poda alfa-beta.
         * 
         * Este método calcula el mejor puntaje posible para la IA
         * o el jugador humano dependiendo del turno actual, explorando
         * todas las posibles jugadas sin optimización.
         * 
         * @param tablero Estado actual del tablero.
         * @param profundidad Límite de profundidad de búsqueda en el árbol de decisiones.
         * @param esMaximizador Indica si el turno actual es del jugador maximizador (IA).
         * @return El puntaje calculado para la posición actual.
         */

        int minimaxSinPoda(Tablero tablero, int profundidad, bool esMaximizador);

        /**
         * @brief Ejecuta el algoritmo Minimax con poda alfa-beta.
         * 
         * Este método mejora el rendimiento de Minimax al descartar ramas
         * innecesarias en el árbol de decisiones mediante los valores alfa y beta.
         * 
         * @param tablero Estado actual del tablero.
         * @param profundidad Límite de profundidad de búsqueda en el árbol de decisiones.
         * @param alfa Valor alfa para la poda (mejor opción garantizada del maximizador).
         * @param beta Valor beta para la poda (mejor opción garantizada del minimizador).
         * @param esMaximizador Indica si el turno actual es del jugador maximizador (IA).
         * @return El puntaje calculado para la posición actual.
         */

        int minimaxConPoda(Tablero tablero, int profundidad, int alfa, int beta, bool esMaximizador);

         /**
         * @brief Evalúa el estado actual del tablero.
         * 
         * Asigna un puntaje al tablero basado en el estado actual del juego:
         * - 100: La IA ha ganado.
         * - -100: El jugador humano ha ganado.
         * - 0: Empate o estado intermedio sin ganador.
         * 
         * @param tablero Referencia constante al tablero que se evalúa.
         * @return Un puntaje que representa el estado actual del tablero.
         */

        int evaluarEstado(const Tablero& tablero); 

        /**
         * @brief Determina la mejor jugada para la IA.
         * 
         * Este método utiliza Minimax (con o sin poda alfa-beta según la dificultad)
         * para calcular la columna óptima en la que la IA debe colocar su ficha.
         * 
         * @param tablero Estado actual del tablero.
         * @param dificultad Nivel de dificultad (1: fácil, 2: difícil).
         * @return El índice de la columna recomendada para la jugada.
         */

        int mejorMovimiento(Tablero tablero, int dificultad); 
};

