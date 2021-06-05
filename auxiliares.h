#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

// Nuevas
#include <string>
#include <iostream>

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

// Nuevas
void tableroLindo(const posicion& p);
void tableroFeo(string tableroFEN);

int aparicionesEnTablero(tablero t, casilla p);

bool esTableroValido(const tablero& t);
bool esMatriz(tablero t);
bool casillasValidas(tablero t);
bool piezaValida(casilla c);
bool sinPeonesNoCoronados(tablero t);
bool cantidadValidaDePiezas(const tablero& t);
int aparicionesEnTablero(tablero t, casilla p);

#endif //AJEDREZLITE_AUXILIARES_H
