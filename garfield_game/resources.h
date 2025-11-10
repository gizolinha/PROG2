/*agrupa todos os recursos allegro*/
#ifndef RESOURCES_H
#define RESOURCES_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>
#include "player.h"
#include "game_def.h"

typedef struct {
    ALLEGRO_BITMAP* player_parado[FPS_PARADO]; //array de sprites
    ALLEGRO_BITMAP* fundo_menu; //tela de menu
    ALLEGRO_BITMAP* bt_iniciar; //botao menu iniciar
    ALLEGRO_BITMAP* bt_sair; //botao menu sair

} gameresources;

/*variavel com todos os resources*/
extern gameresources assets;

/*funcoes sobre os resources*/
bool resources_load_all(); 
void resources_unload_all(); 

#endif /*RESOURCES_H*/