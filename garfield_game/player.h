/* definicoes basicas para o player(personagem) */

#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include "game.h"

/*estado do player*/
typedef enum {
    PARADO,
    ANDANDO,
    PULANDO,
    ABAIXADO,
    INTERACAO, //balancando ou desviando
} player_state;

/* estrutura do jogador*/
typedef struct {
    float x, y, vel_x, vel_y;
    int width;   // largura do sprite
    int height;  // altura do sprite
    player_state state;
    bool on_ground; //para fisica do pulo
    int current_frame; // indice do frame atual 
    int frame_timer;   // Contador para controlar a velocidade da troca de frames
    int anim_direct; //direcao da animacao

} player;


player *player_create();
void player_destroy(player* p);
void player_update(player* p);
void player_draw(player* p);

/* funcoes de input teclado */
void player_jump(player* p);
void player_right(player* p);
void player_left(player* p);
void player_down_start(player* p);
void player_down_stop(player* p);
void player_desvio(player* p);

#endif /* PLAYER_H */