#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <utility>

using namespace std;

TEST(posicionSiguienteCorrectaTEST, adelantoPeon)
{
    tablero t_p = {
        {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
        {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };

    tablero t_q = {
        {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
        {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cPEON_B, cPEON_B, cVACIA, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(6, 2);
    coordenada d = setCoord(5, 2);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, peonHaceSaltoDelTigre)
{
    tablero t_p = {
        {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
        {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };

    tablero t_q = {
        {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
        {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
        {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cPEON_B, cPEON_B, cVACIA, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(6, 2);
    coordenada d = setCoord(2, 2);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, peonCoronado)
{
    tablero t_p = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cREY_N,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cPEON_N,cVACIA,cVACIA,cVACIA,cVACIA,cREY_B},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    tablero t_q = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cREY_N,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cREY_B},
            {cVACIA,cVACIA,cTORRE_N,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
    };

    posicion p = make_pair(t_p, NEGRO);
    posicion q = make_pair(t_q, BLANCO);

    coordenada o = setCoord(6, 2);
    coordenada d = setCoord(7, 2);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, nuevo)
{
    tablero t_p = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cTORRE_N,cVACIA,cTORRE_N,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cPEON_N,cREY_N,cVACIA,cVACIA},
            {cALFIL_B,cVACIA,cVACIA,cVACIA,cVACIA,cPEON_N,cPEON_N,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cREY_B,cVACIA,cTORRE_B,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    tablero t_q = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cALFIL_B,cVACIA,cTORRE_N,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cPEON_N,cREY_N,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cPEON_N,cPEON_N,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cREY_B,cVACIA,cTORRE_B,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    tableroFeo("8/8/2r1r3/r7/3K2k1/r7/8/8 w - - 0 1");
    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(4,0);
    coordenada d = setCoord(1,3);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}