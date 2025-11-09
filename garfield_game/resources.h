#ifndef RESOURCES_H
#define RESOURCES_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>
#include "player.h"

typedef struct {
    ALLEGRO_BITMAP* player_parado[FPS_PARADO]; //array de sprites

} gameresources;

/*variavel com todos os resources*/
extern gameresources assets;

/*funcoes sobre os reosurces*/
bool resources_load_all(); // Carrega todas as imagens, fontes, etc.
void resources_unload_all(); // Destrói todos os recursos

#endif /*RESOURCES_H*/