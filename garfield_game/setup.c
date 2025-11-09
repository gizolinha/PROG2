#include <stdio.h> 
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "setup.h"
#include "game_def.h"
#include "resources.h"

ALLEGRO_DISPLAY* disp = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_EVENT_QUEUE* queue = NULL;

/* inicializa allegro */
int setup_init() {
    /* inicializa allegro*/
    if(!al_init()){
        perror("ERRO: falha ao iniciar allegro");
        return -1;
    }

    /* inicializa image addon para sprites*/
    if(!al_init_image_addon()) {
        perror("ERRO: falha ao iniciar image addon");
        return -1;
    }

    /* instala o teclado */
    if(!al_install_keyboard()) {
        perror("ERRO: falha ao instalar o teclado");
        return -1;
    }

    /* cria o display (tela) */
    disp = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!disp) {
        perror("ERRO: falha ao criar tela");
        return -1;
    }

    /*cria o relogio do jogo*/
    timer = al_create_timer(1.0/FPS);
    if(!timer) {
        perror("ERRO: falha ao criar relogio");
        return -1;
    }

    /* cria a fila de eventos do jogo */
    queue = al_create_event_queue();
    if(!queue) {
        perror("ERRO: falha ao criar fila de eventos");
        return -1;
    }

    /* carregamento global de rescursos*/
    if (!resources_load_all()) {
        perror("ERRO: Falha ao carregar recursos do jogo");
        return -1;
    }

    /* registra as fontes de eventos*/
    al_register_event_source(queue, al_get_display_event_source(disp)); //tela
    al_register_event_source(queue, al_get_timer_event_source(timer));	//timer
    al_register_event_source(queue, al_get_keyboard_event_source()); //teclado

    /* inicia o timer */
    // a partir desse momemtno os eventos passam a acontecer
    al_start_timer(timer);

    return 1;
}

/* destroi todos os recursos */
//conferir como funciona
void setup_end() {
    
    resources_unload_all();
    if (timer) al_destroy_timer(timer);
    if (queue) al_destroy_event_queue(queue);
    if (disp) al_destroy_display(disp);
    al_shutdown_image_addon();
    al_uninstall_system();
}