//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );
int aparicionesEnTablero(tablero const& t, casilla const& c);
int jugador(posicion const& p);
casilla setCasilla(int i, int j);
bool esJugadorValido(int const j);
bool esMatriz(tablero const& t);
bool casillaVacia(tablero const& t, coordenada const c);
bool coordenadaEnRango(coordenada const c);
int pieza(tablero const& t, coordenada const c);
int color(tablero const& t, coordenada const c);
bool casillasValidas(tablero const& t);
bool sinPeonesNoCoronados(tablero const& t);
bool piezasAlfilesValidas(tablero const& t);
bool piezasPeonesValidas(tablero const& t);
bool piezasReyesValidas(tablero const& t);
bool piezasTorresValidas(tablero const& t);
bool cantidadValidaDePiezas(tablero const& t);
bool esTableroValido(tablero const& t);
bool esPosicionValida(posicion const& p);


#endif //AJEDREZLITE_AUXILIARES_H
