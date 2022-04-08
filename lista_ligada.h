//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo que define o protótipo das funções da lista ligada
#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct no {
    char dado;
    struct no *prox;
} No;

No* criar_lista();
void destruir_lista(No **p);

//imprimir
void imprimir_lista(No *p);

//Adicionar
void adicionar_inicio_modificado(No **p, char x , int indice);
void adicionar_final(No **p, char x);

void substituir_lista(No *p, char l1, char l2);

void inverter_lista(No **p);
#endif