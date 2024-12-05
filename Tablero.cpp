#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    tablero = vector<vector<int>>(filas, vector<int>(columnas, 0));
}

bool Tablero::insertarFicha(int columna, int jugador) {
    if (columna < 0 || columna >= columnas) return false;

    for (int fila = filas - 1; fila >= 0; --fila) {
        if (tablero[fila][columna] == 0) {
            tablero[fila][columna] = jugador;
            return true;
        }
    }
    return false; 
}

int Tablero::verificarEstado() const {
    for (int fila = 0; fila < filas; ++fila) {
        for (int col = 0; col < columnas; ++col) {
            int jugador = tablero[fila][col];
            if (jugador == 0) continue;

            if (col + 3 < columnas &&
                jugador == tablero[fila][col + 1] &&
                jugador == tablero[fila][col + 2] &&
                jugador == tablero[fila][col + 3])
                return jugador;

            if (fila + 3 < filas &&
                jugador == tablero[fila + 1][col] &&
                jugador == tablero[fila + 2][col] &&
                jugador == tablero[fila + 3][col])
                return jugador;

            if (fila + 3 < filas && col + 3 < columnas &&
                jugador == tablero[fila + 1][col + 1] &&
                jugador == tablero[fila + 2][col + 2] &&
                jugador == tablero[fila + 3][col + 3])
                return jugador;

            if (fila - 3 >= 0 && col + 3 < columnas &&
                jugador == tablero[fila - 1][col + 1] &&
                jugador == tablero[fila - 2][col + 2] &&
                jugador == tablero[fila - 3][col + 3])
                return jugador;
        }
    }

    for (const vector<int>& fila : tablero) {
        for (int celda : fila) {
            if (celda == 0) return 0; 
        }
    }

    return 3; 
}

void Tablero::imprimirTablero() {
    for (vector<int>& fila : tablero) {
        for (int celda : fila) {
            if (celda == 0) cout << ". ";
            else if (celda == 1) cout << "X ";
            else if (celda == 2) cout << "O ";
        }
        cout << endl;
    }
    cout << endl;
}

void Tablero::reiniciarTablero() {
    for (vector<int>& fila : tablero) {
        fill(fila.begin(), fila.end(), 0);
    }
}
