#pragma once
#include "Tablero.h"
#include "Minimax.h"

/**
 * @class Juego
 * @brief Coordina el flujo principal del juego Conecta 4.
 * 
 * Esta clase actúa como controlador del juego, manejando la interacción entre el
 * jugador, la IA y el tablero. Proporciona métodos para iniciar la partida, procesar
 * movimientos de los jugadores, y reiniciar el estado del juego.
 */

class Juego {
    private:
        Tablero tablero; ///< Objeto que representa el tablero del juego.
        Minimax ia; ///< Instancia del algoritmo Minimax para decisiones de la IA.
        int turno; ///< Indica el turno actual (1: jugador humano, 2: IA).

    public:

        /**
         * @brief Constructor por defecto.
         * 
         * Inicializa el tablero y establece que el jugador humano tendrá el primer turno.
         */

        Juego();

        /**
         * @brief Inicia el flujo principal del juego.
         * 
         * Este método gestiona los turnos alternados entre el jugador humano y la IA,
         * verifica el estado del juego tras cada movimiento, y declara un ganador
         * o empate cuando se alcanza una condición final.
         */

        void iniciar(); 

        /**
         * @brief Procesa un movimiento realizado por el jugador humano.
         * 
         * Valida el movimiento ingresado por el jugador. Si el movimiento es inválido
         * o la columna seleccionada está llena, solicita un nuevo intento.
         * 
         * @param columna Índice de la columna donde el jugador desea colocar su ficha (0-indexada).
         */

        void procesarMovimientoDeJugador(int columna);

        /**
         * @brief Procesa un movimiento realizado por la IA.
         * 
         * Utiliza el algoritmo Minimax para determinar la mejor jugada de la IA,
         * dependiendo del nivel de dificultad seleccionado.
         * 
         * @param dificultad Nivel de dificultad para la IA (1: fácil, 2: difícil).
         */

        void procesarMovimientoDeIA(int dificultad);

        /**
         * @brief Reinicia el estado del juego.
         * 
         * Restablece el tablero a su estado inicial (vacío) y asigna el turno
         * inicial al jugador humano.
         */

        void reiniciarJuego();
};