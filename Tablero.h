#pragma once
#include <vector>
using namespace std;

/**
 * @class Tablero
 * @brief Representa el tablero del juego Conecta 4.
 * 
 * Esta clase proporciona las estructuras y funciones necesarias para gestionar
 * el estado del tablero, insertar fichas, verificar el estado del juego
 * (victoria, empate, o juego en curso), imprimir el tablero y reiniciarlo.
 */

class Tablero {
    private:

        int filas; ///< Número de filas del tablero.
        int columnas; ///< Número de columnas del tablero.

    public:
        vector<vector<int>> tablero; ///< Matriz que representa el estado del tablero. Cada celda puede contener: 0 (vacía), 1 (jugador humano), o 2 (IA).
        
         /**
         * @brief Constructor de la clase Tablero.
         * 
         * Inicializa un tablero con el tamaño especificado.
         * Por defecto, el tablero tiene 6 filas y 7 columnas.
         * 
         * @param filas Número de filas del tablero (por defecto 6).
         * @param columnas Número de columnas del tablero (por defecto 7).
         */

        Tablero(int filas = 6, int columnas = 7);

        /**
         * @brief Inserta una ficha en una columna específica.
         * 
         * Intenta colocar la ficha del jugador en la primera posición vacía de la columna.
         * 
         * @param columna Índice de la columna donde se quiere insertar la ficha (0-indexado).
         * @param jugador Identificador del jugador (1 para humano, 2 para IA).
         * @return `true` si la ficha se inserta con éxito, `false` si la columna está llena o es inválida.
         */

        bool insertarFicha(int columna, int jugador);

        /**
         * @brief Verifica el estado actual del juego.
         * 
         * Evalúa el tablero para determinar si hay un ganador, un empate, o si el juego continúa.
         * 
         * @return 
         * - `1`: El jugador humano ha ganado.
         * - `2`: La IA ha ganado.
         * - `3`: Empate.
         * - `0`: El juego sigue en curso.
         */

        int verificarEstado() const; 

        /**
         * @brief Imprime el tablero en la consola.
         * 
         * Representa visualmente el estado del tablero, donde:
         * - `.`: Celda vacía.
         * - `X`: Ficha del jugador humano.
         * - `O`: Ficha de la IA.
         */

        void imprimirTablero();

        /**
         * @brief Reinicia el tablero.
         * 
         * Limpia todas las celdas del tablero, volviéndolas al estado inicial (vacías).
         */

        void reiniciarTablero();
};