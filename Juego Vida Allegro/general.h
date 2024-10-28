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
 
#define CANT_FILS 30
#define CANT_COLS 30
#define DISPLAY_ANCHO 	1000
#define DISPLAY_ALTO 	350
#define MAX_STRING 4	//Cantidad de caracteres que pueden ingresarse (menos uno para el \0)

/*checks*/
#ifndef CANT_COLS
	#error No definió la cantidad de columnas.
#endif
#ifndef CANT_FILS
	#error No definió la cantidad de filas.
#endif

#ifndef DISPLAY_ANCHO
	#error No definió el ancho del display.
#endif
#ifndef DISPLAY_ALTO
	#error No definió el alto del display.
#endif

#ifndef MAX_STRING
	#error No definió largo de string para toma de datos.
#endif

#if (CANT_FILS)<=0 || (CANT_COLS)<=0
	#error Las filas y columnas deben ser positivas.
#elif (CANT_FILS)>50 || (CANT_COLS) > 50 || (CANT_FILS)*(CANT_COLS)>1000
	#warning El tamaño de la matriz es muy grande y podría ocasionar errores de impresión.
#endif

#if (MAX_STRING)<=1
	#error No se podrán ingresar datos por teclado.
#endif

/*******************************************************************************
 ******************************************************************************/

#endif // GENERAL_H
