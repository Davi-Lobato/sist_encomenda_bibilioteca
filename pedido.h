#include <stdio.h>
#include <stdlib.h>

typedef struct pedido
{
    int pedido_id; //indentificador
    //o que o estagiário preenche
    char * pedido_nome_aluno;
    int pedido_matricula;
    char * pedido_descricao;
    //o que o secretario preenche
    char * pedido_remetente;
    char * pedido_destinatario;
    char * pedido_responsavel_secretario;
    unsigned short int pedido_prioridade;

    //mecanismo p/ unir nos!
    struct pedido * esq;
    struct pedido * dir;
}PEDIDO;

typedef struct encomenda
{
    PEDIDO * pEncomenda;

    struct encomenda * prox;
}ENCOMENDA;

int lista_tamanho = 0;

void abb_retirar_pedido(void);
void carregar_pedido_estagiario(void);
void carregar_pedido_secretario(void);
PEDIDO * abb_bucar_pedido(int pedido_id, PEDIDO *aux);
void abb_add_pedido(int pedido_id, char *pedido_nome_aluno, int pedido_matricula, char *pedido_descricao);
PEDIDO * abb_excluir_pedido(PEDIDO *raiz, int pedido_id);
void abb_imprimir(PEDIDO * aux);
void lista_add_encomenda(PEDIDO * pedido, char *pedido_remetente, char *pedido_destinatario, char *pedido_responsavel_secretario, unsigned short int pedido_prioridade);
PEDIDO lista_excluir_encomenda();
void lista_imprimir();

