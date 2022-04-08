//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo com a função main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"

int main() {
    //crindo a lista
    No *L = criar_lista();
    char letra;
    //criando dinamicamente um array para armazenar as ordens
    char *ordem = (char*) malloc(15*sizeof(char));
    char l1,l2;
    
    //variaveis auxiliares
    int adiciona_inicio = 0;
    int indice = 0;
    
    //le a frase principal até a letra '$' que simboliza o fim da entrada
    while(scanf("%c",&letra) && letra!='$'){
        
        if(letra == '['){
            // se a letra for '[' então é necessário mover o cursor para o comeco
            //adiciona_inicio indica que é necessário usar a funcao que insere as letras no comeco da lista e indice mostra a posicao do cursor
            adiciona_inicio = 1;
            indice = 0;
        }else if(letra == ']'){
            // indica que é necessário adicionar no final
            adiciona_inicio = 0;
        
        }else{
            if(adiciona_inicio == 0){
                adicionar_final(&L,letra);

            }else if (adiciona_inicio == 1){
                //cada vez que adiciona no começo o cursor(indice) é incrementado pois este vai mudando também(nao permanece no comeco sempre)
                adicionar_inicio_modificado(&L,letra, indice);
                indice = indice + 1;
            }
        }
    }

    //escaneia as ordens até está ser igual a 'FIM'
    while(scanf(" %[^\n]", ordem) && strcmp(ordem, "FIM") != 0){
        
        if(ordem[0] == 'I'){
            //caso a letra inicial do comando seja 'I' significa que é necessário inverter
           inverter_lista(&L);
        }else if(ordem[0] == 'S'){
            //caso a letra inicial do comando seja 'S' significa que é necessário substituir
            l1 = ordem[11];
            l2 = ordem[13];
            substituir_lista(L, l1, l2);
        }
    }
    //desaloca a memoria alocada dinamicamente em ordem
    free(ordem);

    //imprime a lista e por fim a destroi
    imprimir_lista(L);
    printf("\n");
    destruir_lista(&L);
    return 0;
}