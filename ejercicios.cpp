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
    for(int i = 0; i < ANCHO_TABLERO; i++)
    {
        for(int u = 0; u < ANCHO_TABLERO; u++)
        {
            coordenada o = setCoord(i,u);
            if(color(p.first,o) == j)
            {
                for(int k = 0; k < ANCHO_TABLERO; k++)
                {
                    for(int l = 0; l < ANCHO_TABLERO; l++)
                    {
                        coordenada d = setCoord(k,l);
                        if(casillaAtacada(p.first,o,d) && cantidadAparicionesVector(d,cA) == 0)
                        {
                            cA.push_back(d);
                        }
                    }
                }
            }
        }
    }
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
    bool empate = esEmpate(p);
    j = empate ? 0 : 3 - p.second;
    bool mate = esJaqueMate(p);
    return empate || esJaqueMate(p);
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
