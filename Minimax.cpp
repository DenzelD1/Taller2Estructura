#include "Minimax.h"
#include <limits> 
using namespace std;

int Minimax::evaluarEstado(const Tablero& tablero) {
    int estado = tablero.verificarEstado();
    if (estado == 1) return 100;  
    if (estado == 2) return -100; 
    if (estado == 3) return 0;    
    return 0; 
}

int Minimax::minimaxSinPoda(Tablero tablero, int profundidad, bool esMaximizador) {
    int estado = tablero.verificarEstado();
    if (estado != 0 || profundidad == 0) {
        return evaluarEstado(tablero); 
    }

    if (esMaximizador) {
        int mejorValor = numeric_limits<int>::min();
        for (int col = 0; col < 7; ++col) { 
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 1)) {
                int valor = minimaxSinPoda(copia, profundidad - 1, false);
                mejorValor = max(mejorValor, valor);
            }
        }
        return mejorValor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        for (int col = 0; col < 7; ++col) {
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 2)) {
                int valor = minimaxSinPoda(copia, profundidad - 1, true);
                mejorValor = min(mejorValor, valor);
            }
        }
        return mejorValor;
    }
}

int Minimax::minimaxConPoda(Tablero tablero, int profundidad, int alfa, int beta, bool esMaximizador) {
    int estado = tablero.verificarEstado();
    if (estado != 0 || profundidad == 0) {
        return evaluarEstado(tablero);
    }

    if (esMaximizador) {
        int mejorValor = numeric_limits<int>::min();
        for (int col = 0; col < 7; ++col) {
            Tablero copia = tablero;
            if (copia.insertarFicha(col, 1)) {
                int valor = minimaxConPoda(copia, profundidad - 1, alfa, beta, false);
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
                int valor = minimaxConPoda(copia, profundidad - 1, alfa, beta, true);
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

    for (int col = 0; col < 7; ++col) {
        Tablero copia = tablero;
        if (copia.insertarFicha(col, 1)) {
            int valor = (dificultad == 1) 
                        ? minimaxSinPoda(copia, 4, false) 
                        : minimaxConPoda(copia, 6, numeric_limits<int>::min(), numeric_limits<int>::max(), false);

            if (valor > mejorValor) {
                mejorValor = valor;
                mejorColumna = col;
            }
        }
    }
    return mejorColumna;
}