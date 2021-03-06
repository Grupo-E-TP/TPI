#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <utility>

using namespace std;

TEST(seVieneElJaqueEnTEST, hayMateEn2)
{
    tablero t = {
        // tablero de ejercicio 17 del TPE
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
        {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
        {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, mateEn2)
{
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cREY_N,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cTORRE_B,cVACIA,cVACIA,cPEON_N,cREY_B,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cALFIL_B,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cALFIL_B,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cPEON_B,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    posicion p = make_pair(t, BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, mateEn3)
{
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cTORRE_B,cVACIA,cVACIA,cPEON_N,cVACIA,cPEON_B},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cALFIL_B,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cREY_N,cVACIA,cVACIA,cREY_B,cVACIA,cPEON_B,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    posicion p = make_pair(t, BLANCO);

    int K_esperado = 3;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, mateEn2_)
{
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cREY_B},
            {cVACIA,cVACIA,cVACIA,cVACIA,cTORRE_N,cVACIA,cVACIA,cPEON_N},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cALFIL_N,cVACIA,cREY_N},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    posicion p = make_pair(t, NEGRO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, mateEn1)
{
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cTORRE_N,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cREY_N},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cALFIL_N,cVACIA,cVACIA},
            {cVACIA,cALFIL_N,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA,cREY_B,cVACIA,cVACIA,cVACIA,cVACIA},
    };
    posicion p = make_pair(t, NEGRO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}