#include "Minimax.h"
#include <limits> 
using namespace std;

int Minimax::evaluarEstado(const Tablero& tablero, bool dificil) {
    int estado = tablero.verificarEstado();
    if (estado == 1) return 100;  
    if (estado == 2) return -100; 
    if (estado == 3) return 0;

    if(!dificil) return 0;
    // SOLAMENTE PARA DIFICULTAD EN DIFICIL
    int puntuacion = 0;

    for (int fila = 0; fila < tablero.tablero.size(); ++fila) {
        for (int col = 0; col < tablero.tablero[0].size(); ++col) {
            if (tablero.tablero[fila][col] == 1) { // JUGADOR
                puntuacion -= evaluarLinea(tablero, fila, col, 1);
            } else if (tablero.tablero[fila][col] == 2) { // IA
                puntuacion += evaluarLinea(tablero, fila, col, 2);
            }
        }
    }
    return puntuacion; 
}   

int Minimax::evaluarLinea(const Tablero& tablero, int fila, int col, int jugador) {
    int puntuacion = 0;

    // HORIZONTAL
    if (col + 3 < tablero.tablero[0].size()) {
        int count = 0, empty = 0;
        for (int i = 0; i < 4; ++i) {
            if (tablero.tablero[fila][col + i] == jugador) count++;
            else if (tablero.tablero[fila][col + i] == 0) empty++;
        }
        puntuacion += calcularPuntuacion(count, empty);
    }

    // VERTICAL
    if (fila + 3 < tablero.tablero.size()) {
        int count = 0, empty = 0;
        for (int i = 0; i < 4; ++i) {
            if (tablero.tablero[fila + i][col] == jugador) count++;
            else if (tablero.tablero[fila + i][col] == 0) empty++;
        }
        puntuacion += calcularPuntuacion(count, empty);
    }

    // DIAGONAL HACIA ABAJO
    if (fila + 3 < tablero.tablero.size() && col + 3 < tablero.tablero[0].size()) {
        int count = 0, empty = 0;
        for (int i = 0; i < 4; ++i) {
            if (tablero.tablero[fila + i][col + i] == jugador) count++;
            else if (tablero.tablero[fila + i][col + i] == 0) empty++;
        }
        puntuacion += calcularPuntuacion(count, empty);
    }

    // DIAGONAL HACIA ARRIBA
    if (fila - 3 >= 0 && col + 3 < tablero.tablero[0].size()) {
        int count = 0, empty = 0;
        for (int i = 0; i < 4; ++i) {
            if (tablero.tablero[fila - i][col + i] == jugador) count++;
            else if (tablero.tablero[fila - i][col + i] == 0) empty++;
        }
        puntuacion += calcularPuntuacion(count, empty);
    }

    return puntuacion;
}

int Minimax::calcularPuntuacion(int count, int empty) {
    if (count == 3 && empty == 1) return 50; // Amenaza inmediata o oportunidad de ganar
    if (count == 2 && empty == 2) return 10; // Posición favorable
    return 0;
}

//-----------------------------------------------------------------------------------------------
//                                     SIN PODA
//-----------------------------------------------------------------------------------------------
int Minimax::minimaxSinPoda(Tablero tablero, int profundidad, bool esMaximizador, bool dificil) {
    int estado = tablero.verificarEstado();
    if (estado != 0 || profundidad == 0) {
        return evaluarEstado(tablero, dificil); 
    }

    if (esMaximizador) {
        int mejorValor = numeric_limits<int>::min();
        for (int col = 0; col < 7; ++col) { 
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 1)) {
                int valor = minimaxSinPoda(copia, profundidad - 1, false, dificil);
                mejorValor = max(mejorValor, valor);
            }
        }
        return mejorValor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        for (int col = 0; col < 7; ++col) {
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 2)) {
                int valor = minimaxSinPoda(copia, profundidad - 1, true, dificil);
                mejorValor = min(mejorValor, valor);
            }
        }
        return mejorValor;
    }
}

//-----------------------------------------------------------------------------------------------
//                                     CON PODA
//-----------------------------------------------------------------------------------------------
int Minimax::minimaxConPoda(Tablero tablero, int profundidad, int alfa, int beta, bool esMaximizador, bool dificil) {
    int estado = tablero.verificarEstado();
    if (estado != 0 || profundidad == 0) {
        return evaluarEstado(tablero, dificil);
    }

    if (esMaximizador) {
        int mejorValor = numeric_limits<int>::min();
        for (int col = 0; col < 7; ++col) {
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 1)) {
                int valor = minimaxConPoda(copia, profundidad - 1, alfa, beta, false, dificil);
                mejorValor = max(mejorValor, valor);
                alfa = max(alfa, mejorValor);
                if (beta <= alfa) break; 
            }
        }
        return mejorValor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        for (int col = 0; col < 7; ++col) {
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 2)) {
                int valor = minimaxConPoda(copia, profundidad - 1, alfa, beta, true, dificil);
                mejorValor = min(mejorValor, valor);
                beta = min(beta, mejorValor);
                if (beta <= alfa) break; 
            }
        }
        return mejorValor;
    }
}

int Minimax::mejorMovimiento(Tablero tablero, int dificultad) {
    int mejorColumna = -1;
    int mejorValor = numeric_limits<int>::min();
    bool dificil = (dificultad == 2);

    for (int col = 0; col < 7; ++col) {
        Tablero copia = tablero;
        if (copia.insertarFicha(col, 1)) {
            int valor = (dificil) 
                        ? minimaxSinPoda(copia, 4, false, dificil) // Profundidad de la IA en Facil
                        : minimaxConPoda(copia, 10, numeric_limits<int>::min(), numeric_limits<int>::max(), false, dificil); //Profundidad de la IA en Dificil

            if (valor > mejorValor) {
                mejorValor = valor;
                mejorColumna = col;
            }
        }
    }
    return mejorColumna;
}