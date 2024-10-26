/***************************************************************************//**
  @file     general.h
  @brief    Encabezado del tamaño de la matriz para el Juego de la Vida
  @author   Ana Destefano
 ******************************************************************************/
 
#ifndef GENERAL_H
#define GENERAL_H

/*******************************************************************************
 * CONSTANT DEFINITIONS USING #DEFINE
 ******************************************************************************/
 
#define CANT_FILS 33
#define CANT_COLS 33

/*checks*/
#ifndef CANT_COLS
	#error No definió la cantidad de columnas.
#endif
#ifndef CANT_FILS
	#error No definió la cantidad de filas.
#endif

#if (CANT_FILS)<=0 || (CANT_COLS)<=0
	#error Las filas y columnas deben ser positivas.
#elif (CANT_FILS)>50 || (CANT_COLS) > 50 || (CANT_FILS)*(CANT_COLS)>1000
	#warning El tamaño de la matriz es muy grande y podría ocasionar errores de impresión.
#endif


/*******************************************************************************
 ******************************************************************************/

#endif // GENERAL_H
