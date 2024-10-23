/***************************************************************************//**
  @file     main.c
  @brief    Programa principal del Juego de la Vida
  @author   Franco Bringas
 ******************************************************************************/

#include <stdio.h>
#include "general.h"
#include "frontend.h"
#include "backend.h"

int main(void) {

	char juego_vida [CANT_FILS] [CANT_COLS];
	char juego_vida_old [CANT_FILS] [CANT_COLS];

	printf("*Juego de la Vida*\n(Presione 'q' para salir)\n");
	int i, p, generaciones;
	
	/* Inicialización de matriz */
	for(i=0;i<CANT_FILS;i++) {
		for(p=0;p<CANT_COLS;p++) {
			juego_vida[i][p]=' ';
		}
	}
	/* Células iniciales */
	//Nota: La matriz debe ser lo suficientemente grande para ver los datos correctamente.
	juego_vida[0][0]='*';
	juego_vida[0][2]='*';
	juego_vida[0][1]='*';
	juego_vida[1][0]='*';
	juego_vida[3][0]='*';
	juego_vida[2][0]='*';
	juego_vida[2][1]='*';
	imprimir(juego_vida);	//Imprime la matriz en pantalla (Caso inicial).
	
	/* Ciclo de Impresión */
	do {
		printf("Ingrese cuántas generaciones avanzar: ");
		generaciones = lectura();
		if (generaciones != -1) {
			for(i=0 ; i<generaciones ; i++) {
				copy(juego_vida,juego_vida_old);//Guarda el estado de la matriz en otra matriz auxiliar
				deadOrAlive(juego_vida,juego_vida_old);	//Modifica la matriz original, comparando los vecinos de cada célula con ayuda de la auxiliar
			}
			imprimir(juego_vida);
		}
	} while (generaciones != -1);
	
	return 0;
}

