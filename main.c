#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pedido.h"
#include "menu.h"
#include "usuarios.h"

PEDIDO * raiz = NULL;
USUARIO * user[8];

int main()
{
    //Secretários
    user[0]->usuario_nome = "Davi";
    user[0]->usuario_cpf = "123";
    user[0]->usuario_senha = "123";
    user[1]->usuario_nome = "Maria";
    user[1]->usuario_cpf = "456";
    user[1]->usuario_senha = "654";
    user[2]->usuario_nome = "Riam";
    user[2]->usuario_cpf = "789";
    user[2]->usuario_senha = "987";
    //Transportadores
    user[3]->usuario_nome = "Artur";
    user[3]->usuario_cpf = "789";
    user[3]->usuario_senha = "987";
    user[4]->usuario_nome = "Camila";
    user[4]->usuario_cpf = "147";
    user[4]->usuario_senha = "741";
    user[5]->usuario_nome = "Bruno";
    user[5]->usuario_cpf = "258";
    user[5]->usuario_senha = "852";
    user[6]->usuario_nome = "Isabella";
    user[6]->usuario_cpf = "369";
    user[6]->usuario_senha = "963";
    user[7]->usuario_nome = "Ana";
    user[7]->usuario_cpf = "159";
    user[7]->usuario_senha = "951";

    int opcao;

    do
    {
        opcao = menu();
        switch (opcao)
        {

        case 1:
            printf("\n===Estagiario===\n\n");
            operacoes_estagiario();
            break;

        case 2:
            printf("\n===Secretario===\n\n");
            operacoes_secretario();
            break;

        case 3:
            printf("\n===Transportador===\n\n");
            operacoes_transportador();
            break;

        }
    } while (opcao != 0);
    system("pause");
    return 0;
}

// Menu de Opcoes
int menu(void)
{
    int opcao;
    do
    {

        printf("\n\n=== MENU DE LOGIN ===\n\n");
        printf("1. Estagiario\n");
        printf("2. Secretario\n");
        printf("3. Transportador\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 4))
            printf("por favor, inserir um numero valido!\\n");

    } while ((opcao < 0) || (opcao > 4));

    return opcao;
}

//chamada das funções após a utilização da função menu_estágiario
void operacoes_estagiario(void)
{
    int opcao;

    do
    {
        opcao = menu_estagiario();
        switch (opcao)
        {

        case 1:
            printf("\n=== ADICIONAR ===\n\n");
            carregar_pedido();
            break;

        case 2:
            printf("\n=== IMPRIMIR ===\n\n");
            imprimir_arvore(raiz);
            break;

        }
    } while (opcao != 0);
    system("pause");
}
// menu que contém as operacoes que o estagiário pode fazer
int menu_estagiario(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. imprimir pedidos\n");
        printf("2. adicionar pedidos\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 3))
            printf("por favor, inserir um numero valido!\\n");

    } while ((opcao < 0) || (opcao > 3));

    return opcao;
}

//chamada das funções após a utilização da função menu_secretario
void operacoes_secretario(void)
{

    /*falta verificar se tem opção de acessar a pagina, fazer um if aqui:*/
    int opcao;

    do
    {
        opcao = menu_secretario();
        switch (opcao)
        {

        case 1:
            printf("\n=== IMPRIMIR ENCOMENDA ===\n\n");
            //imprimir encomenda da lista encadeada
            break;

        case 2:
            printf("\n=== IMPRIMIR PEDIDO ===\n\n");
            imprimir_arvore(raiz);
            break;

        case 3:
            printf("\n=== ADICIONAR ENCOMENDA ===\n\n");
            if (verifica_usuario() == true)
            {
                //adicionar encomenda na lista encadeada
            }
            break;

        case 4:
            printf("\n=== RETIRAR PEDIDO ===\n\n");
            retirar_pedido();
            break;

        }
    } while (opcao != 0);
    system("pause");
}
// menu que contém as operacoes que o secretario pode fazer
int menu_secretario(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. imprimir encomendas\n");
        printf("2. imprimir pedidos\n");
        printf("3. adicionar encomenda\n");
        printf("4. retirar pedido\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 5))
            printf("por favor, inserir um numero valido!\\n");

    } while ((opcao < 0) || (opcao > 5));

    return opcao;
}

//chamada das funções após a utilização da função menu_trasnportador
void operacoes_transportador(void)
{

    /*falta verificar se tem opção de acessar a pagina, fazer ou um if ou uma funcao aqui:*/
    int opcao;

    do
    {
        opcao = menu_transportador();
        switch (opcao)
        {

        case 1:
            printf("\n=== IMPRIMIR ENCOMENDA ===\n\n");
            //imprimir encomenda da lista encadeada
            break;

        case 2:
            printf("\n=== REMOVER ENCOMENDA ===\n\n");
            if (verifica_usuario() == true)
            {
                //remover encomenda na lista encadeada
            }
            break;

        }
    } while (opcao != 0);
    system("pause");
}
// menu que contém as operacoes que o transportador pode fazer
int menu_transportador(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. imprimir encomendas\n");
        printf("2. retirar encomendas\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 3))
            printf("por favor, inserir um numero valido!\\n");

    } while ((opcao < 0) || (opcao > 3));

    return opcao;
}

//Pergunta para o usuário qual vertice da pedido da arvore ele quer retirar
void retirar_pedido(void)
{
    int pedido_id;

    printf("\nDigite o numero que deseja retirar: ");
    scanf("%d", pedido_id);
    abb_excluir_pedido(raiz, pedido_id);
}

/*carrega os valores do pedido em variaveis e passa como parametro
para a função adicionar na arvore
*/
void carregar_pedido(void)
{
    int pedido_id = 0;
    char *pedido_nome = malloc(55);
    int pedido_matricula = 0;
    char *pedido_descricao = malloc(500);
    
    srand(time(NULL));//impede que repita o mesmo valor aleatório

    pedido_id = (rand() % 100);//gera um valor aleatório de 0 a 100
    printf(" %d\n", pedido_id);

    printf("Digite o nome do aluno: \n");
    scanf("%s", pedido_nome);
    printf("Digite o a matricula do aluno: \n");
    scanf("%d", &pedido_matricula);
    printf("Digite os dados do pedido: \n");
    scanf("%s", pedido_descricao);

    abb_add_pedido(pedido_id, pedido_nome, pedido_matricula, pedido_descricao);
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
        printf("nó não existe na árvore");
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
            printf("\n\nentrou aqui");
            free(raiz);
            raiz->pedido_id = NULL;
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
        imprimir_arvore(aux->esq);
    }
    printf("%d\n", aux->pedido_id);
    printf("%s\n", aux->pedido_nome_aluno);
    printf("%d\n", aux->pedido_matricula);
    printf("%s\n", aux->pedido_descricao);
    if(aux->dir != NULL){
        imprimir_arvore(aux->dir);
    } 
}

bool verifica_usuario()
{
    char usuario_cpf[11];
    char usuario_senha[20];

    for (int i = 0; i < 8; i++)
    {
        if ((strcmp(usuario_cpf, user[i]->usuario_cpf)) && (strcmp(usuario_senha, user[i]->usuario_senha)))
        {
            printf("\nRegistro Encontrado!\n");
            return true;
        }        
    }
    printf("\nSenha incorreta\n");
    return false;
}


