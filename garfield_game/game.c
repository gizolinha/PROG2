#include <stdio.h>
#include "game.h"
#include "player.h"
#include "resources.h"

/*nao criamos o player ainda*/
static player* p = NULL;

/* o jogo sempre comeca no menu*/
gamestate current_state = MENU;

/*inicializa os recursos (player, etc)*/
bool game_init() {
    p = player_create();
    if (!p) {
        return false;
    }

    return true;
}

/* Atualiza a lógica do jogo (posicao de player, colisoes, etc) */
/* retorna o proximo estado do jogo (fim de jogo, vitoria)*/
gamestate game_update() {
    /*maquina de estados*/
    switch(current_state) {
    case MENU:
       
    

        break;

    case JOGANDO:
        // Aqui entra a física, movimento, colisões, etc.
        // current_state = player_check_collision(); // No futuro
        player_update(p);
        break;
            
    case FIM_DE_JOGO:
        // Lógica para esperar o clique de "Voltar ao Menu"
        break;

    case VITORIA:
        // Lógica para esperar o clique de "Próximo Nível" ou "Voltar ao Menu"
        break;
            
    default:
        // O estado PAUSE, por exemplo, não atualiza nada.
        break;
    }
    return current_state;
}

/* desenha os elemtons na tela (background, player, obstaculos)*/
void game_draw() {
    switch (current_state) {
    case MENU:
         /* imagem de fundo do menu*/
        if(assets.fundo_menu) {
            /* desenha o bitmap */
            al_draw_bitmap(assets.fundo_menu, 0, 0, 0);
        }
        else {
            /* se falhar, deixa a tela preta*/
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
        
        /*visualizacao dos botoes*/
        if (assets.bt_iniciar && assets.bt_sair) {
            float btn_w = al_get_bitmap_width(assets.bt_iniciar);
            float center_x = LARGURA_TELA / 2.0f  - btn_w / 2.0f;
            
            // Define as posições Y
            float start_y = ALTURA_TELA / 2.0f; // Posição Y para INICIAR
            float exit_y = start_y + 100.0f;

            // Desenha INICIAR
            al_draw_bitmap(assets.bt_iniciar, center_x, start_y, 0);

            // Desenha SAIR (70px abaixo)
            al_draw_bitmap(assets.bt_sair, center_x, exit_y, 0);
        }
        break;
            
    case JOGANDO:
        player_draw(p);
        //desenha background, player, obstaculos, vida 
        break;
            
    case FIM_DE_JOGO:
        // desenha a tela de game over
        break;

    case VITORIA:
        //desenha a tela de vitoria
        break;
            
    default:
        //tela de pause
        break;
    }
}

/* inputs de teclado*/
void game_input(ALLEGRO_EVENT event) {
    // Apenas processa eventos de tecla para o estado MENU
    if (current_state == MENU && event.type == ALLEGRO_EVENT_KEY_DOWN) {
        
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
            printf("ENTER pressionado. Iniciando JOGANDO...\n");
            current_state = JOGANDO;
        } 
        else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            printf("ESC pressionado. Saindo...\n");
            current_state = SAIR;
        }
    }
}

/*limpar objetos alocados pelo jogo*/
void game_end() {
    if (p) { 
        player_destroy(p);
        p = NULL; 
    }
}