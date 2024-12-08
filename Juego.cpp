#include "Juego.h"
#include <iostream>
#include <chrono>
using namespace std;

Juego::Juego() : tablero(6, 7), turno(1) {}

void Juego::iniciar() {
    int dificultad;
    cout << "Selecciona una dificultad para la IA:" << endl;
    cout << "1. Facil" << endl;
    cout << "2. Dificil" << endl;
    cin >> dificultad;

    while(dificultad != 1 && dificultad != 2) {
        cout << "Ingrese nuevamente su opcion: ";
        cin >> dificultad;
        cout << endl;
    }

    while (true) {
        tablero.imprimirTablero();
        if (turno == 1) {
            int columna;
            cout << "Turno del Jugador. Ingrese columna (0-6): ";
            cin >> columna;
            procesarMovimientoDeJugador(columna);
        } else {
            cout << "Turno de la IA.\n";
            procesarMovimientoDeIA(dificultad);
        }

        int estado = tablero.verificarEstado();
        if (estado == 1) {
            tablero.imprimirTablero();
            cout << "Jugador gana!\n";
            break;
        } else if (estado == 2) {
            tablero.imprimirTablero();
            cout << "La IA gana!\n";
            break;
        } else if (estado == 3) {
            tablero.imprimirTablero();
            cout << "Empate!\n";
            break;
        }

        turno = (turno == 1) ? 2 : 1;
    }
}

void Juego::procesarMovimientoDeJugador(int columna) {
    while (!tablero.insertarFicha(columna, 1)) {
        cout << "Movimiento invalido o columna sin espacio. Intente nuevamente: ";
        cin >> columna;
    }
}

void Juego::procesarMovimientoDeIA(int dificultad) {
    auto inicio = chrono::high_resolution_clock::now(); //TOMA EL TIEMPO INICIAL
    int columnaIA = ia.mejorMovimiento(tablero, dificultad);
    auto fin = chrono::high_resolution_clock::now(); //TOMA EL TIEMPO FINAL

    chrono::duration<double> duracion = fin - inicio; //DURACION

    if (columnaIA != -1) {
        tablero.insertarFicha(columnaIA, 2);
        cout << "La IA eligio la columna: " << columnaIA << endl;
        cout << "Tiempo de respuesta de la IA: " << duracion.count() << " segundos." << endl;
    } else {
        cout << "Error: La IA no pudo determinar un movimiento valido.\n";
    }
}

void Juego::reiniciarJuego() {
    tablero.reiniciarTablero();
    turno = 1;
}