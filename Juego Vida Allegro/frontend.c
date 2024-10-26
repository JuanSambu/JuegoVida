/***************************************************************************//**
  @file     frontend.c
  @brief    Interacciones con el usuario en el Juego de la Vida
  @author   Augusto Milani
 ******************************************************************************/

#include <stdio.h>
#include "frontend.h"

/* Lectura de Entrada */
int lectura() {
	int entrada, generaciones, auxiliar, i, digito;
	int flag, exit;
	char c;
	
	do {
		c = getchar();
		flag=0;
		exit = 0;
		entrada = 0;
		for (i=1 ; c != '\n' ; i*=10) {
			if (c == 'q' || c == 'Q') {
				exit=1;
			}
			else if ((c > '9' || c < '0')) {
				printf("Error en la carga de datos. Ingrese un número natural: ");
				flag=1;
			}
			else {
				entrada += (c-'0')*i;		// Al multiplicar por potencias de 10, permite conseguir números de varias cifras.
			}
			c = getchar();
		}
	} while (flag != 0);	// Al detectar un caracter no numérico, vuelve a pedir los datos.
	
	if(exit == 1) {		// Si se presionó q, se finalizará el programa.
		generaciones = -1;
	}
	
	else if (i == 1) {	// Si el usuario presiona enter sin ingresar ningún número, avanza una generación. 
		generaciones = 1;
	}
	
	else {
		/* Intercambio orden de dígitos (menos significativo a más significativo) */
		i/=10;
		generaciones=0;
		
		for (auxiliar=entrada ; i>=1 ; auxiliar/=10, i/=10) {
			digito = auxiliar%10;
			generaciones = generaciones*10 + digito;
		}
	}
	return generaciones;
}

/* Impresión de la Matriz Principal */
void imprimir(char juego_vida[][CANT_COLS]) {
	int i,p;
	for(i=0;i<CANT_FILS;i++) {
		for(p=0;p<CANT_COLS;p++) {
			printf("|");
			printf("%c", juego_vida[i][p]);
		}
	printf("|\n");
	}
}
