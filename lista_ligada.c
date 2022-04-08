//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//arquivo com as funções
#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

No* criar_lista() {
    return NULL;
}

void destruir_lista(No **p) {
    No *q;
    while(*p != NULL){
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}

void imprimir_lista(No *p) {
    No* q;
    for (q = p; q != NULL; q = q->prox){
        printf("%c", q->dado);
    }
}

//funcao que 'move' o cursor para o inicio da lista e começa adicionar as letras na frente do cursor
void adicionar_inicio_modificado(No **p, char x, int indice){
    No *q;
    q = (No*) malloc(sizeof(No));

    if(q==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

   
    // o Nó 'q' será o nó que sera adicionado a lista
    q->dado = x;

    No *aux = *p;

    if(indice == 0){
        //se o indice for zero o 'cursor' será movido para o comeco
        //então para isso o q->prox apontará para o nó que está no começo da lista até o momento (*p)
        // e o no do começo  da lista agora será o nó 'q' que acabou de ser criado
        q->prox = *p;
        *p = q;
    
    }else{
        //caso o indice for maior que 0, iremos adicionar na posicao de acordo com o indice
        // se a posicao for 1 por exemplo, significa que iremos adicionar 1 posicao na frente do nó inicial, e assim sucessivamente.
        for(int i = 1; i < indice; i++){
            aux = aux->prox;
        }
        q->prox = aux->prox;
        aux->prox = q;
    }
}

void adicionar_final(No **p, char x) {
    No *aux, *q;
    q = (No*) malloc(sizeof(No));
    q->dado = x;
    q->prox = NULL;
    
    if (*p == NULL){
        *p = q;
    }else {
        aux = *p;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = q;
    }
}

//funcao que verifica se a letra que está inserida na lista é igual a letra que está sendo procurada
//caso for, substitui a letra pela qual foi solicitada
void substituir_lista(No *p, char l1, char l2){
    No* q;
    for (q = p; q != NULL; q = q->prox){
        if(q->dado == l1){
            q->dado = l2;
        }
    }
}
//função que inverte a lista
void inverter_lista(No **p){
    No *atual = *p; //nó atual
    No *prox = (*p)->prox; //nó proximo
    No *aux = (*p)->prox; //nó temporario para preservação

    //enquanto o proximo nó for diferente de nulo
    while(prox != NULL){
        //o auxiliar recebe seu o proximo nó
        aux = aux->prox;

        //o proximo nó do nó prox(ligação entre os nós) recebe o nó atual
        //com isso começamos inverter a lista
        prox->prox = atual;

        //o nó atual recebe o proximo nó assim selecionamos outro elemento para fazer transição
        atual = prox;

        //o proximo nó recebe o auxiliar(que está uma posição na frente do prox atualmente)
        prox = aux;
    }
    //após o proximo nó ser nulo chegamos no fim da lista e continuaremos aqui:
    
    //o próximo do nó inicial(ligação entre nós) recebe nulo
    (*p)->prox = NULL;
    //o nó inicial agora passa a ser o nó atual(o que antes era o último da lista)
    *p = atual;
}