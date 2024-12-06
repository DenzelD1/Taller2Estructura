#pragma once
#include "Tablero.h"
#include "Minimax.h"

class Juego {
    private:
        Tablero tablero;
        Minimax ia;
        int turno; 

    public:
        Juego();
        void iniciar(); 
        void procesarMovimientoDeJugador(int columna);
        void procesarMovimientoDeIA(int dificultad);
        void reiniciarJuego();
};