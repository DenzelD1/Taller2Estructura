#include "Juego.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    Juego juego;
    string jugar;
    int ronda = 1;
    cout << "************************************ Conecta 4 ************************************" << endl;
    cout << "ANTES DE EMPEZAR A JUGAR:" << endl;
    cout << "- Tienes que formar una linea de 4 fichas, ya sea horizontal, vertical o diagonal." << endl;
    cout << "- Como jugador, tu ficha se representa como X. Mientras que la IA sera el O." << endl;
    cout << "- Para ingresar una ficha tendras que escribir la columna donde deseas colocarlo." << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "                                     Ronda " << ronda << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    do {
        juego.iniciar();
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "¿Siguiente ronda? (Si/No)" << endl;
        cin >> jugar;

        transform(jugar.begin(), jugar.end(), jugar.begin(), ::tolower);

        if(jugar == "si") {
            cout << "-----------------------------------------------------------------------------------" << endl;
            ronda++;
            cout << "                                     Ronda " << ronda << endl;
        } else if (jugar != "no") {
            while(jugar == "si" || jugar == "no") { 
                cout << "Ingrese nuevamente su opcion: ";
                cin >> jugar;
                cout << endl;
            }
        }
    } while (jugar == "si");
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "Rondas jugadas contra la IA: " << ronda << endl;
    return 0;
}