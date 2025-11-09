#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <allegro5/allegro.h> // Para al_get_bitmap_width
#include "player.h" // Inclui a struct player e declarations
#include "game_def.h"
#include "resources.h" // Para acessar a struct assets

// --- Implementação da Função player_create() ---
player* player_create() {
    // 1. Aloca memória para a estrutura player
    player* p = (player*)malloc(sizeof(player));
    if (!p) {
        perror("ERRO: Falha ao alocar memória para o Player.\n");
        return NULL;
    }

    // 2. Inicializa variáveis de estado e posição
    p->x = LARGURA_TELA / 3.0f; // Posição X inicial no centro
    p->y = ALTURA_TELA - 300.0f; // Posição Y inicial perto do chão
    p->vel_x = 0.0f;
    p->vel_y = 0.0f;
    p->state = PARADO;
    p->on_ground = true;
    p->current_frame = 0;
    p->frame_timer = 0;
    p->anim_direct = 1;

    // 3. Define largura e altura usando o primeiro frame de parado
    // O assets.player_parado[0] DEVE ser válido aqui se resources_load_all() funcionou.
    if (assets.player_parado[0]) {
        p->width = al_get_bitmap_width(assets.player_parado[0]);
        p->height = al_get_bitmap_height(assets.player_parado[0]);
    } else {
        // Se o sprite falhou no carregamento global (verifique resources.c)
        fprintf(stderr, "AVISO: Sprite principal do player não carregado!\n");
        p->width = 50; 
        p->height = 50;
    }

    return p;
}

// Implementação de player_destroy
void player_destroy(player* p) {
    if (p) 
      free(p);
}


/* atualiza o player (Seu código atual) */
void player_update(player* p) {
    // ... (Seu código de animação PARADO) ...

    if (p->state == PARADO) {
        p->frame_timer++;
        
        if (p->frame_timer >= FPS_PARADO) { 
            p->frame_timer = 0;
            // 1. Avança (ou retrocede) o frame
            p->current_frame += p->anim_direct;
            
            if (p->current_frame >= FRAMES_PARADO -1) {
                // Se chegou ao último frame, inverte para -1 (voltar)
                p->anim_direct = -1;
                // Garante que o índice não passe do limite superior
                p->current_frame = FRAMES_PARADO - 1;
            }
            // 3. Verifica se atingiu o INÍCIO da sequência (ex: Frame 0)
            else if (p->current_frame <= 0) {
                // Se chegou ao primeiro frame, inverte para 1 (avançar)
                p->anim_direct = 1;
                // Garante que o índice não passe do limite inferior
                p->current_frame = 0;
            }
        }
    }
    
    // --- Lógica de Posição ---
    p->x += p->vel_x;
    p->y += p->vel_y;
}


/* desenha o player (Seu código atual) */
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

// --- Funções de Input (Implementação Vazia para Compilar) ---
void player_jump(player* p) { /* Lógica de pulo */ }
void player_right(player* p) { /* Lógica de movimento para direita */ }
void player_left(player* p) { /* Lógica de movimento para esquerda */ }
void player_down_start(player* p) { /* Começar abaixar */ }
void player_down_stop(player* p) { /* Parar abaixar */ }
void player_desvio(player* p) { /* Lógica de desvio */ }