#pragma once
#include <vector>
using namespace std;

class Tablero {
    private:
        vector<vector<int>> tablero;
        int filas, columnas;

    public:
        Tablero(int filas = 6, int columnas = 7);

        bool insertarFicha(int columna, int jugador);
        int verificarEstado();
        void imprimirTablero();
        void reiniciarTablero();
};