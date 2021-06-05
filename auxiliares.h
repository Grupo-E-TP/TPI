#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

// Nuevas
#include <iostream>
#include <string>

using namespace std;
// definir aqui las funciones
pair<int, int> mp(int a, int b);

vector<pair<int, int>> ordenarVectorPares(vector<pair<int, int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual(posicion const &p);

// Nuevas
void tableroLindo(const posicion &p);
void tableroLindo(const tablero &t);
void tableroFeo(const string &tableroFEN);

int aparicionesEnTablero(tablero t, casilla p);

bool esTableroValido(const tablero &t);
bool esMatriz(tablero t);
bool casillasValidas(tablero t);
bool sinPeonesNoCoronados(tablero t);
bool cantidadValidaDePiezas(const tablero &t);
int aparicionesEnTablero(tablero t, casilla p);

#endif //AJEDREZLITE_AUXILIARES_H
