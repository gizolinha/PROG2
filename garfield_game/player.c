#include <stdio.h>
#include <stdlib.h> 
#include <allegro5/allegro.h> // Para al_get_bitmap_width
#include "player.h" // Inclui a struct player e declarations
#include "game_def.h"
#include "resources.h" // Para acessar a struct assets


/*inicializa o player e carrega recursos*/
player* player_create() {
    //aloca memória para a estrutura player
    player* p = (player*)malloc(sizeof(player));
    if (!p) {
        perror("ERRO: Falha ao alocar memória para o Player.\n");
        return NULL;
    }

    // Inicializa variáveis de estado e posição
    p->x = LARGURA_TELA / 3.0f; // Posição X inicial no centro
    p->y = ALTURA_TELA - 300.0f; // Posição Y inicial perto do chão
    p->vel_x = 0.0f;
    p->vel_y = 0.0f;
    p->state = PARADO;
    p->on_ground = true;
    p->current_frame = 0;
    p->frame_timer = 0;
    p->anim_direct = 1;

    // define largura e altura usando o primeiro frame de parado
    if (assets.player_parado[0]) {
        p->width = al_get_bitmap_width(assets.player_parado[0]);
        p->height = al_get_bitmap_height(assets.player_parado[0]);
    } else {
        // se o sprite falhou no carregamento (verificar resources.c)
        perror("ERRO: Sprite principal do player não carregado!\n");
        p->width = 50; 
        p->height = 50;
    }

    return p;
}

/* atualiza o player */
void player_update(player* p) {

    if (p->state == PARADO) {
        p->frame_timer++;

        //revisar a lógica da animacao ping pong
        if (p->frame_timer >= FPS_PARADO) { 
            p->frame_timer = 0;
            //avança (ou retrocede) o frame
            p->current_frame += p->anim_direct;
            
            if (p->current_frame >= FRAMES_PARADO -1) {
                //se chegou ao ultimo frame, inverte para -1 (voltar)
                p->anim_direct = -1;
                // garante que o indice nao passe do limite
                p->current_frame = FRAMES_PARADO - 1;
            }
            //verifica se chegou o inicio da sequência (frame 0)
            else if (p->current_frame <= 0) {
                // se chegou ao primeiro frame, inverte para 1 (avança)
                p->anim_direct = 1;
                // garante que o indice não passe do limite
                p->current_frame = 0;
            }
        }
    }
    
    //logica de posicao
    p->x += p->vel_x;
    p->y += p->vel_y;
}


/* desenha o sprite do player */
void player_draw(player* p) {
    if (!p) return; // Não desenha se o player não foi criado
    
    ALLEGRO_BITMAP *current_sprite = NULL;

    switch (p->state) {
        case PARADO:
            current_sprite = assets.player_parado[p->current_frame]; 
            break;
            
        case ANDANDO:
            current_sprite = assets.player_parado[0]; // Placeholder
            break;
            
        default:
            current_sprite = assets.player_parado[0];
            break;
    }

    if (current_sprite) {
        al_draw_bitmap(current_sprite, 
                       p->x - p->width / 2, 
                       p->y - p->height / 2, 
                       0); 
    }
}


/* funcoes de input teclado */
void player_jump(player* p) { /* pulo */ }
void player_right(player* p) { /* movimento para direita */ }
void player_left(player* p) { /* movimento para esquerda */ }
void player_down_start(player* p) { /* Começar abaixar */ }
void player_down_stop(player* p) { /* Parar abaixar */ }
void player_desvio(player* p) { /* desvio */ }

/*desaloca memoria do player */
void player_destroy(player* p) {
    if (p) 
      free(p);
}