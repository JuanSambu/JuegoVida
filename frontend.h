/***************************************************************************//**
  @file     frontend.h
  @brief    Encabezado del archivo frontend.c (Juego de la Vida)
  @author   Ana Destefano
 ******************************************************************************/

#ifndef FRONTEND_H
#define FRONTEND_H

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
 
int lectura(void);
/**
 * @brief lectura: Valida datos enteros de la entrada, o 'q' para finalizar. 
 * @return Generaciones que debe avanzar el juego, o -1 para finalizar. Si no se ingresó ningún caracter, devuelve 1.
*/
void imprimir(char juego_vida[][CANT_COLS]);
/**
 * @brief imprimir: Imprime toda la matriz.
 * @param juego_vida[][CANT_COLS]: Puntero a la primera fila, primera columna de la matriz.
*/


/*******************************************************************************
 ******************************************************************************/
 
#endif // FRONTEND_H
