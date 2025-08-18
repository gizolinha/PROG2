#include "jukefila.h"
#include "pedido.h"
#include <stdlib.h>
#include <stdio.h>


void imprimir_jukefila (jukefila *fila)
{
	pedido* elemento_atual = fila->inicio;
	printf ("Imprimindo fila de %d elementos\n", contar_jukefila (fila));
	while (elemento_atual != NULL){
		printf ("%s | %f\n", elemento_atual->musica , elemento_atual->valor);
		elemento_atual = elemento_atual->proximo;
	}
	printf ("-----\n");
}

jukefila* criar_jukefila ()
{
	jukefila *fila = malloc (sizeof(jukefila));
	if (fila == NULL)
		return NULL;

	fila->inicio = NULL;
	fila->final = NULL;

	return fila;
}

void destruir_jukefila (jukefila *fila)
{
	pedido *pedido_atual = fila->inicio;
	pedido *temp = NULL;
	for (int i = 0 ; i < contar_jukefila (fila) ; i++){
		temp = pedido_atual->proximo;
		destruir_pedido (pedido_atual);
		pedido_atual = temp;
	}

	free (fila);
}

unsigned int contar_jukefila (jukefila *fila)
{
	pedido *pedido_atual = fila->inicio;
	unsigned int contador = 0;
	
	while (pedido_atual != NULL){
		contador++;
		pedido_atual = pedido_atual->proximo;
	}
	return contador;
}

void inserir_jukefila (pedido * elemento, jukefila *fila)
{

	if (!elemento || !fila)
		return;

	// inserindo em uma fila vazia
	if (contar_jukefila (fila) == 0){
		elemento->proximo = NULL;
		elemento->anterior = NULL;

		fila->inicio = elemento;
		fila->final = elemento;

		return ;
	}

	// inserindo no comeco da lista
	if (elemento->valor > fila->inicio->valor) {
		elemento->proximo = fila->inicio;
		elemento->anterior = NULL;

		fila->inicio = elemento;
		(elemento->proximo)->anterior = elemento;
	}

	//inserir no final da lista
	else if (elemento->valor < fila->final->valor){
		elemento->proximo = NULL;
		elemento->anterior = fila->final;

		fila->final = elemento;
		(elemento->anterior)->proximo = elemento;
	}

	//inserindo entre dois elementos
	else{
		pedido *pedido_atual = fila->inicio;
		while (pedido_atual != NULL && pedido_atual->valor > elemento->valor){
			pedido_atual = pedido_atual->proximo;
		}

		elemento->proximo = pedido_atual;
		elemento->anterior = pedido_atual->anterior;

		pedido_atual->anterior = elemento;
		(elemento->anterior)->proximo = elemento;

	}


}

pedido* consumir_jukefila (jukefila *fila){
	if (!contar_jukefila (fila))
		return NULL;

	pedido *pedido_retirado = fila->inicio;
	

	fila->inicio = pedido_retirado->proximo;

	if (fila->inicio)
		(fila->inicio)->anterior = NULL;

	pedido_retirado->proximo = NULL;


	return pedido_retirado;
}