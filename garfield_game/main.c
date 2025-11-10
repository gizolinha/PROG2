#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <math.h> 
#include <stdbool.h>
#include <string.h>
#include "game.h"
#include "game_def.h"
#include "setup.h"


int main () {
    /* inicia o ambiente */
    if(!setup_init()) {
        perror("não foi possível iniciar o jogo");
        setup_end();
        return -1;
    }   

    /* inicia os recursos do jogo (player, estados) */
    if(!game_init()) {
        setup_end();
        return -1;
    }

    ALLEGRO_EVENT event;
    //talvez depois trocar para bool pra ser mais intuitivo
    while(1) {
        /* espera por um evento */
        al_wait_for_event(queue, &event);

        /* 30 indica um evento de relogio, verificacao se a tela deve ser atualizada*/
        if(event.type == 30) {
            game_update(); //logica do jogo

            game_input(event);
            al_clear_to_color(al_map_rgb(0, 0, 0)); // tela preta
            game_draw(); //desenho do jogo
            al_flip_display(); //insere as modificacoes
        }
        /* fechar a janela */
        else if (event.type == 42) 
            break;
    }

    /* destroi o sistema */
    game_end();
    setup_end();
    return 0;
}