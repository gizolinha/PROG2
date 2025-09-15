#include <stdio.h>
#include <stdlib.h>
#include "pelucia.h"


long aleat (long min, long max) {

    return min + rand() % (max - min + 1);
} 

//insere a maquina na lista de acordo com a probabilidade
int insere_maquina(struct loja* loja, unsigned int id, unsigned int probabilidade) {
    if(!loja)
        return -1;

    //aloca memoria para o novo item
    struct maquina_pelucia* nova_maquina = malloc(sizeof(struct maquina_pelucia));
        if (nova_maquina == NULL) {
            printf("erro ao alocar memoria");
            return -1;
        }
    nova_maquina->id = id;
    nova_maquina->probabilidade = probabilidade;
    //nao apontam para nada pois nao foram inseridos ainda
    nova_maquina->anterior = NULL;
    nova_maquina->proximo = NULL;
    
    //se a lista estiver vazia ou o novo elemento tem maior probabilidade
    if(loja->inicio == NULL) {
         //como tem apenas um item todos apontam para ele
        loja->inicio = nova_maquina;
        nova_maquina->proximo = nova_maquina;
        nova_maquina->anterior = nova_maquina;
        return 0;    
    }
    
    struct maquina_pelucia* primeiro = loja->inicio;
    
    //inserir antes do primeiro elemento se a probabilidade for maior
    if (probabilidade > primeiro->probabilidade) {
        nova_maquina->proximo = primeiro;
        nova_maquina->anterior = primeiro->anterior;
        primeiro->anterior->proximo = nova_maquina;
        primeiro->anterior = nova_maquina;
        //atualiza o incio da fila
        loja->inicio = nova_maquina;
        return 0;
    }
    
    //inserir em uma posicao x com base na probabilidade
    //começa do segundo elemento
    struct maquina_pelucia* atual = primeiro->proximo;
    //percorre ate achar prob menopr ou voltar para o incio
    while(atual != primeiro && probabilidade <= atual->probabilidade)
        atual = atual->proximo;

    //insere antes do no atual
    nova_maquina->proximo = atual;
    nova_maquina->anterior = atual->anterior;
    atual->anterior->proximo = nova_maquina;
    atual->anterior = nova_maquina;

    return 0;
}

//cria uma nova loja com uma quantidade n de maquinas
struct loja* criar_loja (unsigned int numero_maquinas) {
    if(numero_maquinas == 0)
        return NULL;

   struct loja* loja = malloc(sizeof( struct loja));
   if (loja == NULL) {
        printf("erro ao alocar memoria");
        return NULL;
    }
    loja->inicio = NULL;
    loja->numero_maquinas = numero_maquinas;
    
    for(int i = 1; i <= numero_maquinas; i++) {
        unsigned int id  = i;
        unsigned int probabilidade = aleat(0,100);

        if (insere_maquina(loja, id, probabilidade) == -1){
            printf("falha ao inserir a maquina %d\n", i);
            destruir_loja(loja);
            return NULL;
        }      
    }

    return loja;
}

void destruir_loja (struct loja *loja) {
    //se a lista ja estiver destruida retorna
    if (loja == NULL)
        return;
    
   if (loja->inicio) {
        struct maquina_pelucia* atual = loja->inicio;
        do {
            struct maquina_pelucia* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        } while(atual != loja->inicio);
    }
    free(loja);
}


//retira a maquina da lista caso o jogador ganhe
int retira_maquina(struct loja* loja, unsigned int id) {
    if(!loja || loja->numero_maquinas == 0)
        return 0;

    struct maquina_pelucia* atual = loja->inicio;

    do {
        if (atual->id == id) {
            //se a loja tiver apenas uma maquina
            if(atual->proximo == atual)
                loja->inicio = NULL;
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;

                //se for o primeiro eda lista, atualiza o inicio
                if (atual == loja->inicio)
                    loja->inicio = atual->proximo;
            }
            loja->numero_maquinas--;
            free(atual);
            return 1; //se achou
        }
        atual = atual->proximo;
    } while(atual != loja->inicio);
    
    return 0; //nao achou
}


int jogar (struct loja *loja) { 
    if (!loja) {
        printf("Loja invalida\n");
        return -2;
    }
    
    if(loja->numero_maquinas == 0){
        printf("Nao ha maquinas disponiveis\n");
        return -2;
    }

    unsigned int maquina_esc = aleat(1, loja->numero_maquinas);
    unsigned int num_jogador = aleat(0,100);

    struct maquina_pelucia* atual = loja->inicio;
    for (unsigned int i = 1; i <= loja->numero_maquinas; i++) {
        if (atual->id == maquina_esc) {
            break;
        }
        else  
            atual = atual->proximo;
    }

    if(num_jogador < atual->probabilidade) {
        retira_maquina(loja, atual->id);
        return 1;
    }

    return 0; //perdeu
}

//imprimir as maquinas que restaram
void encerrar_dia (struct loja *loja) {
    if (!loja || !loja->inicio)
        return;

    struct maquina_pelucia* atual = loja->inicio;
    do {
            printf("id: %u, probabilidade: %u\n", atual->id, atual->probabilidade);
            atual = atual->proximo;
    } while (atual != loja->inicio);

}


