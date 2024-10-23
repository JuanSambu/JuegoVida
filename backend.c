/***************************************************************************//**
  @file     backend.c
  @brief    Cálculos que no interactúan con el usuario en el Juego de la Vida
  @author   Juan Sambucetti
 ******************************************************************************/

#include <stdio.h>
#include "general.h"
#include "backend.h"

/* Matriz Auxiliar */
void copy (char juego_vida[][CANT_COLS], char juego_vida_old[][CANT_COLS]) { //guardamos la matriz antes de calcular la siguiente generación, para evitar leer información erronea.
	for (int i = 0; i < CANT_FILS; i++) {
		for (int j = 0; j < CANT_COLS; j++) { 
			juego_vida_old[i][j] = juego_vida[i][j];
		}
	}
}	


/* Modificación de la Matriz Principal */
void deadOrAlive (char juego_vida[][CANT_COLS], char juego_vida_old[][CANT_COLS]) {
	int i = 0, j = 0, k, l, casillasConVida;
	
	for (i = 0; i < CANT_FILS; i++) {
		for (j = 0; j < CANT_COLS; j++) { //primeros dos for avanzan por la matriz general
		
			casillasConVida = 0;
			for (k = MAX(i-1, 0); k <= MIN(i+1, (CANT_FILS-1)); k++) {
				for (l = MAX(j-1, 0); l <= MIN(j+1, (CANT_COLS-1)); l++) {
					/* printf("%d, %d\n", j, l); // estos for escanean una matriz suplementaria 3*3 alrededor de cada punto que se analiza
						pero se usan macros min y max para evitar que estos loops lean valores externos a la matriz, (-1;-1) por ej. */
						
					if (juego_vida_old[k][l] == '*') {
						casillasConVida++;
					}
				}
			}

			if (juego_vida_old[i][j] == '*') { //Una vez que se contaron la cantidad de casillas vivas en la submatriz, descontamos la casilla
												//de la propia célula ya que esta no cuenta para las reglas.
				casillasConVida--;
			}
			
			#ifdef DEBUG
				printf("Finished checking (%d, %d). Live cell count: %d\n", i, j, casillasConVida);
			#endif
			
			/* Veredicto para cada celda */
			if((casillasConVida == 2 || casillasConVida == 3) && juego_vida_old[i][j] == '*') {
				juego_vida[i][j] = '*'; // Condición para celda viva.
			}
			else if (casillasConVida == 3 && juego_vida_old[i][j] == ' ') {
				juego_vida[i][j] = '*'; // Condición para celda muerta.
			}
			else {
				juego_vida[i][j] = ' '; // Si no cumplió condiciones, muere.
			}
		}
	}
}	
