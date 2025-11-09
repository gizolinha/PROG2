/*definicoes basicas para os aspectos do jogo*/
#ifndef GAME_DEF 
#define GAME_DEF

//nao sei se vou usar todas mas vou deixar por precaucao
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
//depois incluir os outros .h


/* constantes globais */
#define LARGURA_TELA 900
#define ALTURA_TELA 800
#define FPS 30
#define GRAVIDADE 0.5f

#define FRAMES_PARADO 5 //5 sprites para a animação parado
#define FPS_PARADO 10

/*estados do jogo */
typedef enum {
    MENU,
    JOGANDO,
    FIM_DE_JOGO,
    SAIR,
    VITORIA,
} gamestate;

#endif /* GAME_DEF */