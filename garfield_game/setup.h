/*definicoes basicas para funcionalidades allegro*/
#ifndef SETUP_H
#define SETUP_H

#include <allegro5/allegro.h>
#include <stdbool.h> 

/* Declaracao externa para o main.c poder acessar os recursos*/
extern ALLEGRO_DISPLAY* disp; //tela do jogo
extern ALLEGRO_TIMER* timer; //relogio do jogo
extern ALLEGRO_EVENT_QUEUE* queue; //fila de eventos

/* funcoes de inicializacao e desligamento */
int setup_init();
void setup_end();

#endif /* SETUP_H */