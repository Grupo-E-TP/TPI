#include "definiciones.h"
#include "auxiliares.h"

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

            // Si encuentra una pieza, agrega las casillas vacías previas si las hubiera
            if(pieza != '\0' && casillasVacias != 0)
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
    cout << "https://lichess.org/editor/" + tableroFEN << endl;
}

void tableroFeo(string tableroFEN)
{
    char proximaCasilla;
    char casillaFEN;
    int casillasLlenas = 0;
    cout << "tablero t = {" << endl
         << "\t{";
    for(int i = 0; casillasLlenas < 64; ++i)
    {
        casillaFEN = tolower(tableroFEN[i]);
        string casillaTPI;
        switch(casillaFEN)
        {
            case 'p':
                cout << "cPEON_";
                casillasLlenas++;
                break;
            case 'b':
                cout << "cALFIL_";
                casillasLlenas++;
                break;
            case 'r':
                cout << "cTORRE_";
                casillasLlenas++;
                break;
            case 'k':
                cout << "cREY_";
                casillasLlenas++;
                break;
            default:
                casillasLlenas += int(casillaFEN) - 48;
                for(int j = 0; j < int(casillaFEN) - 48; ++j)
                {
                    cout << "cVACIA";
                    cout << (j != int(casillaFEN) - 49 ? "," : "");
                }
        }
        if(isalpha(casillaFEN))
        {
            cout << (casillaFEN == tableroFEN[i] ? "N" : "B");
        }

        proximaCasilla = tableroFEN[i + 1];
        if(proximaCasilla == '/')
        {
            i++;
            cout << "},\n\t{";
        } else if(casillasLlenas < 64)
        {
            cout << ",";
        }
    }
    cout << "},\n};\n";
}
