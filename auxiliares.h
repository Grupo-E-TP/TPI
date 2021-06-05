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

#endif //AJEDREZLITE_AUXILIARES_H
