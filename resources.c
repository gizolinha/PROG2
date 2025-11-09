#include <stdio.h>
#include "resources.h"

gameresources assets;

bool resources_load_all() {
    char path[100];

    /*--- Carregamento da Animação PARADO ---*/
    for (int i = 0; i < FRAMES_PARADO; i++) {
        // Cria a string do caminho: "assets/player/parado_0.png"
        snprintf(path, 100, "assets/personagens/garfield/parado/parado_%d.png", i);
        
        assets.player_parado[i] = al_load_bitmap(path);
        
        if (!assets.player_parado[i]) {
            perror("ERRO: Falha ao carregar frame parado");
            return false;
        }
    }


    // ... (Implemente o carregamento de todos os itens aqui)

    return true; // Retorna true se tudo carregar
}

void resources_unload_all() {
    // Destruir todas as imagens carregadas
    
    // --- Destruição da Animação PARADO ---
    // Você deve iterar e destruir cada sprite no array
    for (int i = 0; i < FRAMES_PARADO; i++) {
        if (assets.player_parado[i]) {
            al_destroy_bitmap(assets.player_parado[i]);
            // (Opcional, mas boa prática)
            assets.player_parado[i] = NULL; 
        }
    }
}