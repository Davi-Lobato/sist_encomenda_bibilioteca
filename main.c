#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

PEDIDO * raiz = NULL;

int main()
{
    //testando
    char nome[15];
    char desc[15];
    printf("nome: ");
    scanf("%s", &nome);
    printf("desc: ");
    scanf("%s", &desc);
    abb_add_pedido(1, &nome, 511384, &desc);
    abb_bucar_pedido(1, raiz);
    imprimir_arvore(raiz);
    abb_excluir_pedido(raiz, 1);
    abb_bucar_pedido(1, raiz);
    imprimir_arvore(raiz);
    return 0;
}

PEDIDO * abb_bucar_pedido(int pedido_id, PEDIDO *aux)
{
    if(aux != NULL){
        if(aux->pedido_id == pedido_id){
            return aux;
        }else if(pedido_id < aux->pedido_id){
            if(aux->esq != NULL){
                return abb_bucar_pedido(pedido_id, aux->esq);
            }else{
                return aux;
            }
        }else if(pedido_id > aux->pedido_id){
            if(aux->dir != NULL){
                return abb_bucar_pedido(pedido_id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }   
}

PEDIDO * abb_add_pedido(int pedido_id, char *pedido_nome_aluno, int pedido_matricula, char *pedido_descricao)
{
    PEDIDO* buscador = abb_bucar_pedido(pedido_id, raiz);
    
    if(buscador != NULL && buscador->pedido_id == pedido_id){
        printf("Insercao invalida!\n");
    }else{
        
        PEDIDO* novo_pedido = malloc(sizeof(PEDIDO));
        novo_pedido->pedido_id = pedido_id;
        novo_pedido->pedido_nome_aluno = pedido_nome_aluno;
        novo_pedido->pedido_matricula = pedido_matricula;
        novo_pedido->pedido_descricao = pedido_descricao;
        novo_pedido->esq = NULL;
        novo_pedido->dir = NULL;
        
        if(buscador == NULL){//arvore esta vazia
            raiz = novo_pedido;
        }else{
            if(pedido_id < buscador->pedido_id){
                buscador->esq = novo_pedido;
            }else{
                buscador->dir = novo_pedido;
            }
        }
    }
}

PEDIDO * abb_excluir_pedido(PEDIDO *raiz, int pedido_id)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (raiz->pedido_id > pedido_id)
    {
        raiz->esq = abb_excluir_pedido(raiz->esq, pedido_id);
    }
    else if (raiz->pedido_id < pedido_id)
    {
        raiz->dir = abb_excluir_pedido(raiz->dir, pedido_id);
    }
    else
    {
        if (raiz->esq == NULL && raiz->dir ==NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        else if (raiz->esq == NULL)
        {
            PEDIDO * aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        else if (raiz->dir)
        {
            PEDIDO * aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else
        {
            PEDIDO * aux = raiz->esq;
            while (raiz->dir != NULL)
            {
                aux = raiz ->dir;
            }
            raiz->pedido_id = aux->pedido_id;
            aux->pedido_id = pedido_id;
            raiz->esq = abb_excluir_pedido(raiz->esq, pedido_id);   
        }
        return raiz;        
    }
}

void imprimir_arvore(PEDIDO * aux)
{
   if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d\n", aux->pedido_id);
    printf("%s\n", aux->pedido_nome_aluno);
    printf("%d\n", aux->pedido_matricula);
    printf("%s\n", aux->pedido_descricao);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    } 
}





