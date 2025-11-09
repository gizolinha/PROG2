/*definicoes basicas para o jogo*/
#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "game_def.h"

/* Atualiza a lógica do jogo (posição de player, colisões, etc.) */
/* retorna o proximo estado do jogo (morreu, tela derro, tela vitoria)*/
gamestate game_update();

/* desenha os elemtons na tela (background, player, obstaculos)*/
void game_draw();

/*inicializa os recursos (player, etc)*/
bool game_init();

/* inputs de teclado*/
void game_input(ALLEGRO_EVENT event);

/*limpar objetos alocados pelo jogo*/
void game_end();

/* estado atual do jogo*/
extern gamestate current_state;

#endif /* GAME_H */