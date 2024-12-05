#pragma once
#include "Tablero.h"

class Minimax {
    public:
        int minimaxSinPoda(Tablero tablero, int profundidad, bool esMaximizador);
        int minimaxConPoda(Tablero tablero, int profundidad, int alfa, int beta, bool esMaximizador);
        int evaluarEstado(const Tablero& tablero); 
        int mejorMovimiento(Tablero tablero, int dificultad); 
};

