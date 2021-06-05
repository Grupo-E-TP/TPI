#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int, int> mp(int a, int b)
{
    return make_pair(a, b);
}

// TEST
vector<pair<int, int>> ordenarVectorPares(vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j)
{
    return make_pair(i, j);
}

tablero tableroActual(posicion const &p)
{
    return p.first;
}

tablero inicializarTablero()
{
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

// Nuevas
string generarTableroFEN(const tablero &tab)
{
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

            // Si encuentra una pieza, agrega las casillas vacías previas si las hubiera
            if((pieza != '\0' || j == 7) && casillasVacias != 0)
            {
                fila += to_string(casillasVacias);
                casillasVacias = 0;
            }

            // Si es una pieza blanca, convierte pieza a mayúsculas
            if(!bool(c.second - 1))
            {
                pieza = char(toupper(pieza));
            }

            // Si encuentra una pieza, la agrega a la fila
            if(pieza != '\0')
            {
                fila += pieza;
            }
            pieza = 0;
        }

        // Agrega la fila al tablero FEN
        tableroFEN += !fila.empty() ? fila + "/" : "8/";
        fila = "";
        casillasVacias = 0;
    }
    return tableroFEN;
}
tablero generarTableroFeo(string tableroFEN)
{
    char casillaFEN;
    int casillasLlenas = 0, fila = 0;
    tablero tabRes(ANCHO_TABLERO);
    for(int i = 0; casillasLlenas < 64; ++i)
    {
        casillaFEN = char(tolower(tableroFEN[i]));
        int color;
        casilla c;
        if(isalpha(casillaFEN))
        {
            color = (casillaFEN == tableroFEN[i] ? NEGRO : BLANCO);
        }
        switch(casillaFEN)
        {
            case 'p':
                c = (color == BLANCO ? cPEON_B : cPEON_N);
                tabRes[fila].push_back(c);
                casillasLlenas++;
                break;
            case 'b':
                c = (color == BLANCO ? cALFIL_B : cALFIL_N);
                tabRes[fila].push_back(c);
                casillasLlenas++;
                break;
            case 'r':
                c = (color == BLANCO ? cTORRE_B : cTORRE_N);
                tabRes[fila].push_back(c);
                casillasLlenas++;
                break;
            case 'k':
                c = (color == BLANCO ? cREY_B : cREY_N);
                tabRes[fila].push_back(c);
                casillasLlenas++;
                break;
            case '/':
                fila++;
                break;
            default:
                casillasLlenas += int(casillaFEN) - 48;
                for(int j = 0; j < int(casillaFEN) - 48; ++j)
                {
                    c = cVACIA;
                    tabRes[fila].push_back(cVACIA);
                }
        }
    }
    return tabRes;
}

void validarConversion(const tablero &t, string tFEN)
{
    tablero tF = generarTableroFeo(tFEN);
    cout << "CONVERSIÓN ENTRE TABLEROS VÁLIDA: " << (t == tF ? "TRUE" : "FALSE") << endl;
}
void validarConversion(string tFEN, const tablero &t)
{
    bool iguales = true;
    int barras = 0;
    string tab = generarTableroFEN(t);
    for(int i = 0; i < min(tab.size(), tFEN.size()) && barras < 8; ++i)
    {
        iguales &= tab[i] == tFEN[i];
        barras += tab[i + 1] == '/' || tFEN[i + 1] == '/' ? 1 : 0;
    }
    cout << "CONVERSIÓN ENTRE TABLEROS VÁLIDA: " << (iguales ? "TRUE" : "FALSE") << endl;
}

void mostrarTableroFeo(const tablero &t)
{
    cout << "tablero t = {" << endl
         << "\t{";
    for(int i = 0; i < ANCHO_TABLERO; ++i)
    {
        for(int j = 0; j < ANCHO_TABLERO; ++j)
        {
            casilla c = t[i][j];
            switch(c.first)
            {
                case 1:
                    cout << "cPEON_";
                    break;
                case 2:
                    cout << "cALFIL_";
                    break;
                case 3:
                    cout << "cTORRE_";
                    break;
                case 4:
                    cout << "cREY_";
                    break;
                default:
                    cout << "cVACIA";
            }
            if(c.second != 0)
                cout << (c.second == 1 ? "B" : "N");
            if(j != 7)
                cout << ",";
        }
        if(i != 7)
            cout << "},\n\t{";
        else
            cout << "},\n};\n";
    }
}
void mostrarTableroFEN(const string &tableroFEN)
{
    cout << "https://lichess.org/editor/" + tableroFEN << endl;
}

void tableroLindo(const posicion &p)
{
    string tab = generarTableroFEN(p.first);
    validarConversion(p.first, tab);
    mostrarTableroFEN(tab);
}
void tableroLindo(const tablero &t)
{
    string tab = generarTableroFEN(t);
    validarConversion(t, tab);
    mostrarTableroFEN(tab);
}

void tableroFeo(const string &tableroFEN)
{
    tablero tab = generarTableroFeo(tableroFEN);
    validarConversion(tableroFEN, tab);
    mostrarTableroFeo(tab);
}

bool esTableroValido(const tablero &t)
{
    return esMatriz(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidaDePiezas(t);
}

bool esMatriz(tablero t)
{
    bool res = t.size() == ANCHO_TABLERO;
    for(int i = 0; i < ANCHO_TABLERO; ++i)
    {
        res &= t[i].size() == ANCHO_TABLERO;
    }
    return res;
}

bool casillasValidas(tablero t)
{
    bool res = true;
    for(int i = 0; i < ANCHO_TABLERO; ++i)
    {
        for(int j = 0; j < ANCHO_TABLERO; ++j)
        {
            casilla c = t[i][j];
            int c0 = c.first, c1 = c.second;
            res &= (c == cVACIA || (PEON <= c0 && c0 <= REY && BLANCO <= c1 && c1 <= NEGRO));
        }
    }
    return res;
}

bool sinPeonesNoCoronados(tablero t)
{
    bool res = true;
    for(int i = 0; i < ANCHO_TABLERO; ++i)
    {
        int pieza1 = t[0][i].first;
        int pieza2 = t[i][0].first;
        res &= pieza1 != PEON && pieza2 != PEON;
    }
    return res;
}

bool cantidadValidaDePiezas(const tablero &t)
{
    // Peones
    bool res = aparicionesEnTablero(t, cPEON_B) <= ANCHO_TABLERO;
    res &= aparicionesEnTablero(t, cPEON_N) <= ANCHO_TABLERO;

    // Alfiles
    res &= aparicionesEnTablero(t, cALFIL_B) <= 2;
    res &= aparicionesEnTablero(t, cALFIL_N) <= 2;

    // Torres
    res &= aparicionesEnTablero(t, cPEON_B) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_B) <= ANCHO_TABLERO);
    res &= aparicionesEnTablero(t, cPEON_N) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_N) <= ANCHO_TABLERO);

    // Reyes
    res &= aparicionesEnTablero(t, cREY_B) == 1;
    res &= aparicionesEnTablero(t, cREY_N) == 1;

    return res;
}

int aparicionesEnTablero(tablero t, casilla p)
{
    int apariciones = 0;
    for(int i = 0; i < ANCHO_TABLERO; ++i)
    {
        for(int j = 0; j < ANCHO_TABLERO; ++j)
        {
            apariciones += t[i][j] == p ? 1 : 0;
        }
    }
    return apariciones;
}