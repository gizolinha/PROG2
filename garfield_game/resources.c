#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "resources.h"

gameresources assets;

/* carrega todas as imagens, fontes, etc */
bool resources_load_all() {
    char path[100];

    /* carregamento animacao player parado */
    for (int i = 0; i < FRAMES_PARADO; i++) {
        // Cria a string do caminho: "assets/player/parado_0.png"
        snprintf(path, 100, "assets/personagens/garfield/parado/parado_%d.png", i);
        
        assets.player_parado[i] = al_load_bitmap(path);
        
        if (!assets.player_parado[i]) {
            perror("ERRO: Falha ao carregar frame parado");
            return false;
        }
    } 

    /* carregamento da tela de menu*/
    assets.fundo_menu = al_load_bitmap("assets/background/fundo_menu.png");
    if(!assets.fundo_menu) {
        perror("ERRO: Falha ao carregar fundo_menu.png");
        return false;
    }

    /* carregamento botao menu iniciar jogo e sair jogo*/
    assets.bt_iniciar = al_load_bitmap("assets/background/bt_iniciar.png");
    if(!assets.bt_iniciar) {
        perror("ERRO: Falha ao carregar bt_iniciar.png");
        return false;
    }

    assets.bt_sair = al_load_bitmap("assets/background/bt_sair.png"); 
    if(!assets.bt_sair) {
        perror("ERRO: Falha ao carregar bt_sair.png");
        return false;
    }

    return true; // Retorna true se tudo carregar
}

/* destroi todos os recursos */
void resources_unload_all() {
    // Destruir todas as imagens carregadas
    
    /* destruicao da aniamcao playes parado */
    // destruir cada sprite no array
    for (int i = 0; i < FRAMES_PARADO; i++) {
        if (assets.player_parado[i]) {
            al_destroy_bitmap(assets.player_parado[i]);
            // (Opcional, mas boa prática)
            assets.player_parado[i] = NULL; 
        }
    }

    /* destruicao do fundo do menu */
    if(assets.fundo_menu) {
        al_destroy_bitmap(assets.fundo_menu);
        assets.fundo_menu = NULL;
    }

    /* destruicao dos botoes */
    if (assets.bt_iniciar) {
        al_destroy_bitmap(assets.bt_iniciar);
        assets.bt_iniciar = NULL;
    }
    if (assets.bt_sair) {
        al_destroy_bitmap(assets.bt_sair);
        assets.bt_sair = NULL;
    }

}