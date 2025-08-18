#include <stdio.h>
#include <stdlib.h>
#include "pelucia.h"


long aleat (long min, long max) {

    return min + rand() % (max - min + 1);
} 

//insere a maquina na lista de acordo com a probabilidade
struct loja* insere_maquina(struct loja* loja, struct maquina_pelucia* maquina) {


}

//cria uma nova loja com uma quantidade n de maquinas
struct loja* criar_loja (unsigned int numero_maquinas) {
    if(numero_maquinas == NULL)
        return NULL;

   struct loja* loja = malloc(sizeof( struct loja));
   if (loja == NULL)
        printf("erro ao alocar memoria");
        return NULL;
    
    loja->inicio = NULL;
    loja->numero_maquinas = numero_maquinas;
    
    for(int i = 1; i <= numero_maquinas; i++) {
        struct maquina_pelucia* maquina = malloc(sizeof(struct maquina_pelucia));
        if (maquina == NULL)
            printf("erro ao alocar memoria");
            return NULL;
        
        maquina->id = i;
        maquina->probabilidade = aleat(0,100);
        insere_maquina(loja, maquina);
        
    }

    return criar_loja;
}

//retira a maquina da lista caso o jogador ganhe
struct loja* retira_maquina(struct loja* loja, int pos) {
    if(!loja)
        return NULL;

    struct maquina_pelucia* maquina_retira = loja->inicio;

    

}


int jogar (struct loja *loja) { 
    if (!loja)
        return -1;
    
    if(loja->numero_maquinas == 0);
        return -1;

    unsigned int maquina_esc = aleat(1, loja->numero_maquinas);
    unsigned int num_jogador = aleat(0,100);

    struct maquina_pelucia* atual = loja->inicio;
    for (unsigned int i = 1; i <= loja->numero_maquinas; i++) {
        if (i == maquina_esc) {
            break;
        }
        else  
            atual = atual->proximo;
    }
    
    




}

//imprimir as maquinas que restaram???
void encerrar_dia (struct loja *loja) {

}


void destruir_loja (struct loja *loja) {
    if (loja == NULL)
        return NULL;



    free(loja);
}



