#include <stdio.h>
#include "game.h"
#include "player.h"

/*nao criamos o player ainda*/
static player* p = NULL;

/* o jogo sempre comeca no menu*/
gamestate current_state = MENU;

bool game_init() {
    p = player_create();
    if (!p) {
        return false;
    }

    return true;
}

gamestate game_update() {
    /*maquina de estados*/
    switch(current_state) {
    case MENU:
        // Por enquanto, apenas transiciona para o JOGANDO para vermos a tela.
        // No futuro, isso esperaria o clique em "Start".
        printf("Estado: MENU -> Transicionando para JOGANDO...\n");
        current_state = JOGANDO;
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

void game_draw() {
    switch (current_state) {
    case MENU:
        // Desenha a imagem de fundo do menu e o texto "Aperte ENTER"
        break;
            
    case JOGANDO:
        player_draw(p);
        // Desenha o cenário, player, obstáculos, HUD (vida)
        // al_draw_bitmap(background, ...);
        // player_draw(); // No futuro
        break;
            
    case FIM_DE_JOGO:
        // Desenha a tela vermelha de Game Over
        break;

    case VITORIA:
        // Desenha a tela verde de Vitória
        break;
            
    default:
        //tela de pause
        break;
    }
}

// Lida com o input do usuário
void game_handle_input(ALLEGRO_EVENT event) {
    // Por enquanto, não faz nada
}

void game_end() {
    if (p) { 
        player_destroy(p);
        p = NULL; 
    }
}