/***************************************************************************//**
  @file     frontend.c
  @brief    Interacciones con el usuario en el Juego de la Vida
  @author   Augusto Milani
 ******************************************************************************/

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

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
void imprimir(const ALLEGRO_FONT* font, int alto, int ancho, char juego_vida[][CANT_COLS]) {
	int i,p;

	al_clear_to_color(al_map_rgb(0, 0, 0));		// Limpio pantalla con negro.

	// En orden: fuente, color, x, y, alineación, texto.
	al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_ANCHO/2.0, 20, ALLEGRO_ALIGN_CENTRE,
			"Juego de la Vida - Presione 'q' para salir");

	/* Imprimo Matriz */
	for(i=0;i<CANT_FILS;i++) {
		for(p=0;p<CANT_COLS;p++) {

			al_draw_textf(font, al_map_rgb(0, 255, 0),
			ancho*p*2+DISPLAY_ANCHO/4.0, alto*i+50, 0,
			"|%c", juego_vida[i][p]);
		}

		al_draw_textf(font, al_map_rgb(0, 255, 0),
			ancho*p*2+DISPLAY_ANCHO/4.0, alto*i+50, 0,
			"|", juego_vida[i][p]);
	}
	al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_ANCHO/2.0, alto*(i+1)+50, ALLEGRO_ALIGN_CENTRE,
			"Ingrese cuántas generaciones avanzar: ");

	al_flip_display();
}
