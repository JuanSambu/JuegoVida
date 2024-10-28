#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "frontend.h"
#include "backend.h"

static void must_init (bool test, const char *description);

int main() {

	srand(time(NULL));	//Semilla para función rand().

	/* Inicializo Allegro */
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");

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

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_mouse_event_source());

	/* Variables y Flags */
    char juego_vida [CANT_FILS] [CANT_COLS];		// Matriz principal.
	char juego_vida_old [CANT_FILS] [CANT_COLS];	// Matriz auxiliar.
	int i, p;	//auxiliares
	long int generaciones = 0;		//Generaciones a avanzar.

	char input[MAX_STRING] = {0};	// String para leer el input del teclado.
	int input_len = 0;				// Longitud del input actual.
	int enter_pressed = 0;			// Bandera de enter.
	ALLEGRO_EVENT event;			// Evento que ocurrió (ver switch).
	ALLEGRO_KEYBOARD_STATE ks;		// Registro del teclado.
	bool flag = false;				// Bandera para terminar programa.
	bool redraw = true;				// Bandera para dibujar la matriz principal.

	/* Inicialización de matriz */
	for(i=0 ; i<CANT_FILS ; i++) {
		for(p=0;p<CANT_COLS;p++) {
			juego_vida[i][p]=' ';
		}
	}

	/* Células iniciales */
	int inicio = 0;
	do {
		inicio = (rand()%CANT_COLS+1) * (rand()%CANT_FILS+1); // alto*ancho células como máximo
	} while(inicio == CANT_COLS*CANT_FILS);

	for (i=0 ; i<inicio ; i++) {
		juego_vida[rand()%CANT_FILS][rand()%CANT_COLS] = '*';
	}	// Elije aleatoriamente una cantidad de células iniciales y las coloca aleatoriamente en la matriz principal.

    /* Programa Principal */
    al_start_timer(timer);
    while(!flag)
    {
        al_wait_for_event(queue, &event);

        switch (event.type) {
        	case ALLEGRO_EVENT_DISPLAY_CLOSE:
				flag = true;	// Al cerrar el display, termina el programa.
				break;

        	case ALLEGRO_EVENT_KEY_CHAR:
        		al_get_keyboard_state(&ks);

        		if(al_key_down(&ks, ALLEGRO_KEY_Q) || al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
        		    flag = true;	// Si se aprieta Q o ENTER, termina el programa.
        		}
        		else {
        			redraw = true;
        			char key = event.keyboard.unichar;	// Registro el caracter presionado.
        			lectura(key, input, sizeof(input), &input_len, &enter_pressed);

        			if (enter_pressed) {
        				if (input_len == 0) {
							generaciones = 1;	// Si sólo se presionó ENTER, avanza una generación.
						}
						else {
							for (p=1, i = input_len-1 ; i>=0 ; p*=10, i--) {
								generaciones += (input[i]-'0')*p;	// Cambia orden de dígitos (menos significativo a más significativo).
							}
						}
        			}
        		}
        		break;

        	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				redraw = true;
				generaciones = 1;	// Si se presiona un botón del mouse, avanza una generación.
				break;

        	default:
        		break;
        }

        /* Rutina de Impresión */
        if(redraw && al_is_event_queue_empty(queue))
        {
        	redraw = false;
        	for (i=0 ; i<generaciones ; i++) {
				copy(juego_vida,juego_vida_old); // Guarda el estado de la matriz en otra matriz auxiliar
				deadOrAlive(juego_vida,juego_vida_old);	// Modifica la matriz original, comparando los vecinos de cada célula con ayuda de la auxiliar
        	}
        	generaciones = 0;

        	if (enter_pressed) {
				enter_pressed = 0;
				input_len = 0;
				input[0] = '\0';  // Reinicia la cadena
			}

        	imprimir(font, alto_linea, ancho_caracter, juego_vida, input); // Imprime en display.
        }
    }

    /* Finalización del Programa */
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

/* Reviso si Allegro se inicializó correctamente */
static void must_init(bool test, const char *description) {
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}




