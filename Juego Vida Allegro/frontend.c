/***************************************************************************//**
  @file     frontend.c
  @brief    Interacciones con el usuario en el Juego de la Vida
  @author   Augusto Milani
 ******************************************************************************/

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "frontend.h"

/* Lectura de Entrada */
void lectura (char key, char input[], int tamaño, int *input_len, int *enter_pressed) {

	// Si es un número:
	if (key >= '0' && key <= '9' && *input_len < tamaño-1) {
		input[(*input_len)++] = key;
		input[*input_len] = '\0';  // Asegura el final de la cadena
	}

	// Si se presiona Backspace:
	else if (key == '\b' && *input_len > 0) {
		input[--(*input_len)] = '\0';
	}

	// Si se presiona Enter
	else if (key == '\n' || key == '\r') {
		*enter_pressed = 1;
	}
}


/* Impresión de la Matriz Principal */
void imprimir(const ALLEGRO_FONT* font, int alto, int ancho, char juego_vida[][CANT_COLS], char input[]) {

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
			"|");
	}
	al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_ANCHO/2.0, alto*(i+1)+50, ALLEGRO_ALIGN_CENTRE,
			"Ingrese cuántas generaciones avanzar: %s", input);

	al_flip_display();
}
