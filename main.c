<<<<<<< HEAD
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>
#include <stdio.h>  // Incluimos stdio.h para fprintf y stderr
=======
/***************************************************************************//**
  @file     main.c
  @brief    Programa principal del Juego de la Vida
  @author   Franco Bringas
 ******************************************************************************/
>>>>>>> branch 'main' of https://github.com/JuanSambu/JuegoVida.git

<<<<<<< HEAD
int main() {
    // Inicializar Allegro
    if (!al_init()) {
        fprintf(stderr, "Error: no se pudo inicializar Allegro.\n");
        return -1;
    }
=======
#include <stdio.h>
#include "general.h"
#include "frontend.h"
#include "backend.h"
>>>>>>> branch 'main' of https://github.com/JuanSambu/JuegoVida.git

<<<<<<< HEAD
    // Inicializar teclado
    if (!al_install_keyboard()) {
        fprintf(stderr, "Error: no se pudo instalar el teclado.\n");
        return -1;
    }

    // Crear el display con un tamaño más manejable
    int display_width = 1280;  // Resolución horizontal común
    int display_height = 720;  // Resolución vertical común

    al_set_new_display_flags(ALLEGRO_WINDOWED); // Configurar para usar ventana con bordes (no pantalla completa)
    ALLEGRO_DISPLAY* disp = al_create_display(display_width, display_height);
    if (!disp) {
        fprintf(stderr, "Error: no se pudo crear el display.\n");
        return -1;
    }

    // Crear el temporizador
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    if (!timer) {
        fprintf(stderr, "Error: no se pudo crear el temporizador.\n");
        al_destroy_display(disp);
        return -1;
    }

    // Crear la cola de eventos
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if (!queue) {
        fprintf(stderr, "Error: no se pudo crear la cola de eventos.\n");
        al_destroy_timer(timer);
        al_destroy_display(disp);
        return -1;
    }
=======
int main(void) {
>>>>>>> branch 'main' of https://github.com/JuanSambu/JuegoVida.git

<<<<<<< HEAD
    // Crear la fuente
    ALLEGRO_FONT* font = al_create_builtin_font();
    if (!font) {
        fprintf(stderr, "Error: no se pudo crear la fuente.\n");
        al_destroy_event_queue(queue);
        al_destroy_timer(timer);
        al_destroy_display(disp);
        return -1;
    }

    // Registrar las fuentes de eventos en la cola
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    // Empezar el temporizador
    al_start_timer(timer);

    // Bucle de eventos
    bool redraw = true;
    ALLEGRO_EVENT event;

    while (1) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if ((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)) {
            break;
        }

        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0, "Hello world!");
            al_flip_display();

            redraw = false;
        }
    }

    // Liberar recursos
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
=======
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
>>>>>>> branch 'main' of https://github.com/JuanSambu/JuegoVida.git
}

