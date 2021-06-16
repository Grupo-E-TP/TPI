#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <utility>

using namespace std;


TEST(posicionValidaTEST, tableroVacio)
{
    tablero t = {{}};
    posicion p = make_pair(t, 1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroSinPiezas)
{
    tablero t = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, 1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroSoloReyes)
{
    tablero t = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, 1);
    EXPECT_TRUE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroInvalido)
{
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, make_pair(-1,0), cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, 1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroInvalido2)
{
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, make_pair(0,1), cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, 1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, jugadorInvalido)
{
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, make_pair(-1,0), cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, 6);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, peonDeMas)
{
    tablero t = {
            {cTORRE_N,cVACIA,cALFIL_N,cVACIA,cREY_N,cALFIL_N,cVACIA,cTORRE_N},
            {cPEON_N,cPEON_N,cPEON_N,cPEON_N,cPEON_N,cPEON_N,cPEON_N,cPEON_N},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cPEON_B},
            {cPEON_B,cPEON_B,cPEON_B,cPEON_B,cPEON_B,cPEON_B,cPEON_B,cPEON_B},
            {cTORRE_B,cVACIA,cALFIL_B,cVACIA,cREY_B,cALFIL_B,cVACIA,cTORRE_B},
    };
    posicion p = make_pair(t, 1);
    EXPECT_FALSE(posicionValida(p));
}