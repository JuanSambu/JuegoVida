#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "frontend.h"
#include "backend.h"

static void must_init (bool test, const char *description);
static void imprimir_display (char juego_vida[][CANT_COLS]);



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
	juego_vida[0][0]='*';
	juego_vida[0][2]='*';
	juego_vida[0][1]='*';
	juego_vida[1][0]='*';
	juego_vida[3][0]='*';
	juego_vida[2][0]='*';
	juego_vida[2][1]='*';

    bool flag = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    ALLEGRO_KEYBOARD_STATE ks;

    al_start_timer(timer);
    while(!flag)
    {
        al_wait_for_event(queue, &event);

        switch (event.type) {
        	case ALLEGRO_EVENT_DISPLAY_CLOSE:
				flag = true;
				break;

        	case ALLEGRO_EVENT_KEY_DOWN:
        		al_get_keyboard_state(&ks);

        		if(al_key_down(&ks, ALLEGRO_KEY_Q) || al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
        		    flag = true;
        		}
        		else {
        			redraw = true;
				//	char key = event.keyboard.unichar;
					generaciones = lectura();

					if (generaciones == -1) {
						flag = true;
					}
					else {
						for(i=0 ; i<generaciones ; i++) {
							copy(juego_vida,juego_vida_old);//Guarda el estado de la matriz en otra matriz auxiliar
							deadOrAlive(juego_vida,juego_vida_old);	//Modifica la matriz original, comparando los vecinos de cada célula con ayuda de la auxiliar
						}
					}
        		}
        		break;

        	/////////case mouse? TODO
        	default:
        		break;
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
        	printf("hola\n");
        	imprimir(font, alto_linea, ancho_caracter, juego_vida);

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




