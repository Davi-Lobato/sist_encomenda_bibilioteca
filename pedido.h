#include <stdio.h>
#include <stdlib.h>

typedef struct pedido
{
    int pedido_id; //indentificador
    char * pedido_nome_aluno;
    int pedido_matricula;
    char * pedido_descricao;
    
    //mecanismo p/ unir nos!
    struct pedido * esq;
    struct pedido * dir;
}PEDIDO;

void carregar_pedido(void);
PEDIDO * abb_bucar_pedido(int pedido_id, PEDIDO *aux);
PEDIDO * abb_add_pedido(int pedido_id, char *pedido_nome_aluno, int pedido_matricula, char *pedido_descricao);
PEDIDO * abb_excluir_pedido(PEDIDO *raiz, int pedido_id);
