#include <algorithm>
#include "ejercicios.h"

// EJERCICIO 1
bool posicionValida(pair<tablero, int> const &p)
{
    return esPosicionValida(p);
}

// EJERCICIO 2
bool posicionInicial(posicion const &p)
{
    return piezasEnCoordenadas(p.first) && cantidadPiezasAlInicio(p.first) && jugador(p) == BLANCO;

}
// EJERCICIO 3
vector<coordenada> casillasAtacadas(posicion const &p, int j)
{
    vector<coordenada> cA;
    // completar codigo
    return cA;
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
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 7
bool hayJaqueDescubierto(posicion const &p)
{
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 8
void ejecutarSecuenciaForzada(posicion &p, secuencia s)
{
    // completar codigo
    return;
}
// EJERCICIO 9
int seVieneElJaqueEn(posicion const &p)
{
    int resp = -1;
    // completar codigo
    return resp;
}
