#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"
#include <iostream>
#include <string>

using namespace std;

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
coordenada setCoord(int i, int j);
bool coordenadaEnRango(coordenada c);
tablero tableroActual(posicion const &p);
int aparicionesEnTablero(tablero t, casilla p);
int jugador(posicion const &p);
int contrincante(int j);
int pieza(tablero const &t, coordenada c);
int color(tablero const &t, coordenada c);

void tableroLindo(const posicion &p);
void tableroLindo(const tablero &t);
void tableroFeo(const string &tableroFEN);

casilla setCasilla(int i, int j);
bool casillaVacia(tablero const &t, coordenada c);
vector<coordenada> jugadasDisponibles(const posicion &p, coordenada o);
vector<coordenada> obtenerPosiblesDestinos(const tablero &t, coordenada o);

// Ejercicio 1
bool esPosicionValida(posicion const &p);
bool esJugadorValido(int j);
bool esTableroValido(const tablero &t);
bool esMatriz(tablero t);
bool casillasValidas(tablero t);
bool sinPeonesNoCoronados(tablero t);

// Ejercicio 2
bool piezasEnCoordenadas(tablero const &t);
bool piezaEnCoordenada(tablero const &t, coordenada c, int pza, int col);
bool cantidadPiezasAlInicio(tablero const &t);
bool cantidadValidaDePiezas(const tablero &t);

// Ejercicio 3
bool movimientoPiezaValido(tablero const &t, coordenada o, coordenada d);
int cantidadAparicionesVector(coordenada c, vector<coordenada> v);

// Ejercicio 4
bool posicionSiguiente(posicion const &p1, posicion const &p2, coordenada o, coordenada d);
bool posicionesIgualesExceptoEn(posicion const &p1, posicion const &p2, coordenada o, coordenada d);
bool esMovimientoValido(const posicion &p, coordenada o, coordenada d);
bool esCapturaValida(const posicion &p, coordenada o, coordenada d);
bool casillaAtacada(const tablero &t, coordenada o, coordenada d);
bool capturaPeonValida(const tablero &t, coordenada o, coordenada d);
bool piezaCorrectaEnDestino(const posicion &p, const posicion &q, coordenada o, coordenada d);
bool enLineaFinalInicial(coordenada d);

// Ejecicio 5
void ordenarFilas(tablero &t);

// Ejercicio 6
bool esEmpate(const posicion &p);
bool esJaqueMate(const posicion &p);
bool soloHayReyes(const tablero &t);
bool jugadorEnJaque(const posicion &p);
vector<coordenada> cualesAtacanAlRey(const posicion &p);
coordenada dondeEstaElRey(const tablero &t, int jugador);
bool atacaAlRey(const posicion &p, coordenada o);
bool hayMovimientosLegales(const posicion &p);
bool existeMovimientoParaSalirDelJaque(const posicion &p);
bool esJugadaLegal(const posicion &p, coordenada o, coordenada d);
bool loPoneEnJaque(posicion p, coordenada o, coordenada d);
void ejecutarMovimiento(posicion &p, coordenada o, coordenada d);
casilla obtenerCasilla(const tablero &t, coordenada o);

// Ejercicio 7
bool esJaqueDescubierto(posicion p, coordenada o, coordenada d);

// Ejercicio 8
void cambiarJugador(posicion &p);

// Ejercicio 9
pair<coordenada,coordenada> jugadaForzada(const posicion &p);
void cuantoParaElMate(const posicion &p, int k, int &res);
vector<coordenada> obtenerPiezas(const posicion &p, int j);

#endif //AJEDREZLITE_AUXILIARES_H
