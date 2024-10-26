#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "frontend.h"
#include "backend.h"

static void must_init (bool test, const char *description);
static void imprimir_display (char juego_vida[][CANT_COLS]);

#define DISPLAY_ANCHO 	1000
#define DISPLAY_ALTO 	350

int main() {

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(DISPLAY_ANCHO, DISPLAY_ALTO);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    /* Medir Ancho y Alto de Caracter y Línea, según la fuente */
    int alto_linea = al_get_font_line_height(font);
    int ancho_caracter = al_get_text_width(font, "*");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    int x = 0;
    int y = 0;

    char juego_vida [CANT_FILS] [CANT_COLS];
	char juego_vida_old [CANT_FILS] [CANT_COLS];

	int i, p, generaciones;

	/* Inicialización de matriz */
	for(i=0;i<CANT_FILS;i++) {
		for(p=0;p<CANT_COLS;p++) {
			juego_vida[i][p]=' ';
		}
	}
	/* Células iniciales */
	//Nota: La matriz debe ser lo suficientemente grande para ver los datos correctamente.
	printf("*Juego de la Vida*\n(Presione 'q' para salir)\n");
	juego_vida[0][0]='*';
	juego_vida[0][2]='*';
	juego_vida[0][1]='*';
	juego_vida[1][0]='*';
	juego_vida[3][0]='*';
	juego_vida[2][0]='*';
	juego_vida[2][1]='*';
	imprimir(juego_vida);	//Imprime la matriz en pantalla (Caso inicial).

    bool flag = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(!flag)
    {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_KEY_Q || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			flag = true;
        }
        else if (event.type == ALLEGRO_KEY_ENTER) {
        	redraw = true;
        	generaciones = 1;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
        	redraw = true;
        	char key = event.keyboard.unichar;

        	if (key >= '0' && key <= '9') {
        		redraw = true;
        		generaciones = lectura();

        	}
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
        	// En orden: fuente, color, x, y, alineación, texto, parámetro.
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_ANCHO/2.0, 20, ALLEGRO_ALIGN_CENTRE,
					"Juego de la Vida - Presione 'q' para salir");

			for(i=0;i<CANT_FILS;i++) {
				for(p=0;p<CANT_COLS;p++) {

					al_draw_textf(font, al_map_rgb(0, 255, 0),
					ancho_caracter*p*2+DISPLAY_ANCHO/4.0, alto_linea*i+50, 0,
					"|%c", juego_vida[i][p]);
				}

				al_draw_textf(font, al_map_rgb(0, 255, 0),
					ancho_caracter*p*2+DISPLAY_ANCHO/4.0, alto_linea*i+50, 0,
					"|", juego_vida[i][p]);
			}
			al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

static void must_init(bool test, const char *description) {
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
/*
static void imprimir_display (char juego_vida[][CANT_COLS]) {


}*/




