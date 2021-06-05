#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

// Nuevas
void tableroLindo(const posicion &p)
{
    tablero tab = p.first;
    string tableroFEN, fila;
    int casillasVacias = 0;
    char pieza;
    for(int i = 0; i < tab.size(); ++i)
    {
        for(int j = 0; j < tab[0].size(); ++j)
        {
            casilla c = tab[i][j];

            // Identifica la pieza
            switch(c.first)
            {
                case VACIO:
                    casillasVacias++;
                    break;
                case PEON:
                    pieza = 'p';
                    break;
                case ALFIL:
                    pieza = 'b';
                    break;
                case TORRE:
                    pieza = 'r';
                    break;
                case REY:
                    pieza = 'k';
            }
            if(pieza != '\0' && casillasVacias != 0)
            {
                fila += to_string(casillasVacias);
                casillasVacias = 0;
            }
            if(!bool(c.second - 1))
            {
                pieza = char(toupper(pieza));
            }
            if(pieza != '\0')
            {
                fila += pieza;
            }
            pieza = 0;
        }
        tableroFEN += !fila.empty() ? fila + "/" : "8/";
        fila = "";
        casillasVacias = 0;
    }
    cout << "https://lichess.org/editor/" + tableroFEN << endl;
}

int aparicionesEnTablero(tablero const& t, casilla const& c)
{
    int res = 0;
    for (int i = 0; i < t.size(); ++i)
    {
        for (int j = 0; j < t[0].size() ; ++j)
        {
           if (t[i][j]==c)
           {
               res = res + 1;
           }
        }
    }
    return res;
}

int jugador(posicion const& p)
{
    return p.second;
}



casilla setCasilla(int i, int j)
{
    return make_pair(i,j);
}

bool esJugadorValido(int const j)
{
    return j== BLANCO || j==NEGRO;
}

bool esMatriz(tablero const& t)
{
    bool res = true;
    res = (t.size()==ANCHO_TABLERO)&&res;
    for (int f = 0; f < t.size(); ++f)
    {
        res = (t[f].size()==ANCHO_TABLERO)&&res;
    }
    return res;
}

bool casillaVacia(tablero const& t, coordenada const c)
{
    return (t[c.first][c.second].first == VACIO)&&(t[c.first][c.second].second == VACIO);
}

bool coordenadaEnRango(coordenada const c)
{
    return ((0<=c.first)&&(c.first<ANCHO_TABLERO))&&((0<=c.second)&&(c.second<ANCHO_TABLERO));
}

int pieza(tablero const& t, coordenada const c)
{
    return t[c.first][c.second].first;
}

int color(tablero const& t, coordenada const c)
{
    return t[c.first][c.second].second;
}

bool casillasValidas(tablero const& t)
{
    bool res = true;
    for (int i = 0; i < ANCHO_TABLERO; ++i)
    {
        for (int j = 0; j < ANCHO_TABLERO; ++j)
        {
            casilla c = setCasilla(i,j);
            res = res && (casillaVacia(t,c)||((PEON<=pieza(t,c)&& pieza(t,c)<=REY)&&(BLANCO<= color(t,c)&& color(t,c)<=NEGRO)));
        }
    }
    return res;
}

bool sinPeonesNoCoronados(tablero const& t)
{
    bool res = true;
    for (int i = 0; i <ANCHO_TABLERO ; ++i)
    {
        casilla c = setCoord(0,i);
        res = res && (pieza(t,c)!=PEON);
        c = setCoord(ANCHO_TABLERO-1,i);
        res = res && (pieza(t,c)!=PEON);
    }
    return res;
}

bool piezasAlfilesValidas(tablero const& t)
{
    return (aparicionesEnTablero(t, setCasilla(ALFIL,BLANCO))<=2)&&(aparicionesEnTablero(t, setCasilla(ALFIL,NEGRO))<=2);
}

bool piezasPeonesValidas(tablero const& t)
{
    return (aparicionesEnTablero(t, setCasilla(PEON,BLANCO))<=ANCHO_TABLERO)&&(aparicionesEnTablero(t, setCasilla(PEON,NEGRO))<=ANCHO_TABLERO);
}

bool piezasReyesValidas(tablero const& t)
{
    return (aparicionesEnTablero(t, setCasilla(REY,BLANCO))==1)&&(aparicionesEnTablero(t, setCasilla(REY,NEGRO))==1);
}

bool piezasTorresValidas(tablero const& t)
{
    bool tB;
    tB = aparicionesEnTablero(t, setCasilla(TORRE,BLANCO))<= (2+ANCHO_TABLERO - aparicionesEnTablero(t,setCasilla(PEON,BLANCO)));
    bool tN;
    tN = aparicionesEnTablero(t, setCasilla(TORRE,NEGRO))<= (2+ANCHO_TABLERO - aparicionesEnTablero(t,setCasilla(PEON,NEGRO)));
    return tB && tN;
}

bool cantidadValidaDePiezas(tablero const& t)
{
    return (piezasTorresValidas(t)&& piezasPeonesValidas(t))&& (piezasAlfilesValidas(t)&& piezasReyesValidas(t));
}

bool esTableroValido(tablero const& t)
{
    bool res = false;
    if (esMatriz(t))
    {
        res = casillasValidas(t)&& sinPeonesNoCoronados(t)&& cantidadValidaDePiezas(t);
    }
    return res;
}

bool esPosicionValida(posicion const& p)
{
    return esJugadorValido(jugador(p))&& esTableroValido(tableroActual(p));
}