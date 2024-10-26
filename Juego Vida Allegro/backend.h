/***************************************************************************//**
  @file     backend.h
  @brief    Encabezado del archivo backend.c (Juego de la Vida)
  @author   Ana Destefano
 ******************************************************************************/

#ifndef BACKEND_H
#define BACKEND_H

#include "general.h"

/*******************************************************************************
 * MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
 
void copy(char juego_vida[][CANT_COLS], char juego_vida_old[][CANT_COLS]);
/**
 * @brief copy: Guarda la matriz en otra matriz auxiliar.
 * @param juego_vida[][CANT_COLS]: Puntero a la primera fila, primera columna de la matriz.
 * @param juego_vida_old[][CANT_COLS]: Puntero a la primera fila, primera columna de la matriz auxiliar.
*/
void deadOrAlive(char juego_vida[][CANT_COLS], char juego_vida_old[][CANT_COLS]);
/**
 * @brief deadOrAlive: Sobreescribe la matriz original en base a las reglas del juego de la vida.
 * @param juego_vida[][CANT_COLS]: Puntero a la primera fila, primera columna de la matriz.
 * @param juego_vida_old[][CANT_COLS]: Puntero a la primera fila, primera columna de la matriz auxiliar.
*/

/*******************************************************************************
 ******************************************************************************/

#endif // BACKEND_H
