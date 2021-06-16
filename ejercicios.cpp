#include "ejercicios.h"
#include <algorithm>

// EJERCICIO 1
bool posicionValida(pair<tablero,int> const &p)
{
    return esJugadorValido(jugador(p)) && esTableroValido(tableroActual(p));
}
// EJERCICIO 2
bool posicionInicial(posicion const &p)
{
    return piezasEnCoordenadas(p.first) && cantidadPiezasAlInicio(p.first) && jugador(p) == BLANCO;
}
// EJERCICIO 3
vector<coordenada> casillasAtacadas(posicion const &p, int j)
{
    vector<coordenada> atacadas;
    vector<coordenada> piezas = obtenerPiezas(p, j);
    for(int i = 0; i < piezas.size(); ++i)
    {
        coordenada o = piezas[i];
        vector<coordenada> posibles = obtenerPosiblesDestinos(p.first, o);
        for(int k = 0; k < posibles.size(); ++k)
        {
            coordenada d = posibles[k];
            if(casillaAtacada(p.first, o, d) && cantidadAparicionesVector(d, atacadas) == 0)
            {
                atacadas.push_back(d);
            }
        }
    }
    return atacadas;
}
// EJERCICIO 4
bool posicionSiguienteCorrecta(posicion const &p1, posicion const &p2, coordenada o, coordenada d)
{
    return posicionSiguiente(p1, p2, o, d);
}
// EJERCICIO 5
void ordenarTablero(posicion &p)
{
    ordenarFilas(p.first);
}
// EJERCICIO 6
bool finDeLaPartida(posicion const &p, int &j)
{
    bool empate = esEmpate(p);
    j = empate ? 0 : contrincante(p.second);
    return empate || esJaqueMate(p);
}
// EJERCICIO 7
bool hayJaqueDescubierto(posicion const &p)
{
    bool res = false;
    vector<coordenada> piezas = obtenerPiezas(p, jugador(p));
    for(int i = 0; i < piezas.size(); ++i)
    {
        coordenada o = piezas[i];
        vector<coordenada> jugadas = jugadasDisponibles(p, o);
        for(int k = 0; k < jugadas.size(); ++k)
        {
            res |= esJaqueDescubierto(p, o, jugadas[k]);
        }
    }
    return res;
}
// EJERCICIO 8
void ejecutarSecuenciaForzada(posicion &p, secuencia s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        ejecutarMovimiento(p, s[i].first, s[i].second);
        pair<coordenada,coordenada> forzada = jugadaForzada(p);
        ejecutarMovimiento(p, forzada.first, forzada.second);
    }
}
// EJERCICIO 9
int seVieneElJaqueEn(posicion const &p)
{
    int res = 3, k = 1;
    cuantoParaElMate(p, k, res);
    return res;
}
