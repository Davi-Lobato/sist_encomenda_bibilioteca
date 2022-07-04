#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
#include "pedido.h"
#include "menu.h"
#include "usuarios.h"


PEDIDO * raiz = NULL;
//USUARIO * user[8];
ENCOMENDA * inicio = NULL;
ENCOMENDA * fim = NULL;

int main()
{
    /*//Secretários
    user[0] = (USUARIO*){"Davi", "123", "321", "S001"};
    user[1] = (USUARIO*){"Maria", "456", "654", "S002"};
    user[2] = (USUARIO*){"Riam", "789", "987", "S003"};
    //Transportadores   
    user[3] = (USUARIO*){"Artur", "147", "741", "T001"};
    user[4] = (USUARIO*){"Jorge", "258", "852", "T002"};
    user[5] = (USUARIO*){"Bruno", "369", "963", "T003"};
    user[6] = (USUARIO*){"Isabella", "159", "951", "T004"};
    user[7] = (USUARIO*){"Ana", "753", "357", "T005"};  */
    

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
    //system("pause");
    return 0;
}

// Menu de Opcoes
int menu(void)
{
    int opcao;
    printf("\n\n=== MENU DE LOGIN ===\n\n");
    printf("1. Estagiario\n");
    printf("2. Secretario\n");
    printf("3. Transportador\n");
    printf("0. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    if ((opcao < 0) || (opcao >= 4))
        printf("Por favor, inserir um numero valido!\n");

    //while ((opcao < 0) || (opcao > 4));

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
            printf("\n=== IMPRIMIR ===\n\n");
            abb_imprimir(raiz);
            break;

        case 2:
            printf("\n=== ADICIONAR ===\n\n");
            carregar_pedido_estagiario();
            break;

        }
    } while (opcao != 0);
    //system("pause");
}
// menu que contém as operacoes que o estagiário pode fazer
int menu_estagiario(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. Imprimir pedidos\n");
        printf("2. Adicionar pedidos\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 3))
            printf("Por favor, inserir um numero valido!\n");

    } while ((opcao < 0) || (opcao > 3));

    return opcao;
}

//chamada das funções após a utilização da função menu_secretario
void operacoes_secretario(void)
{
    int opcao;

    do
    {
        opcao = menu_secretario();
        switch (opcao)
        {

        case 1:
            printf("\n=== IMPRIMIR ENCOMENDA ===\n\n");
            lista_imprimir();
            break;

        case 2:
            printf("\n=== IMPRIMIR PEDIDO ===\n\n");
            abb_imprimir(raiz);
            break;

        case 3:
            printf("\n=== ADICIONAR ENCOMENDA ===\n\n");
            carregar_pedido_secretario();           
            break;

        case 4:
            printf("\n=== RETIRAR PEDIDO ===\n\n");
            abb_retirar_pedido();
            break;

        }
    } while (opcao != 0);
    //system("pause");
}
// menu que contém as operacoes que o secretario pode fazer
int menu_secretario(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. Imprimir encomendas\n");
        printf("2. Imprimir pedidos\n");
        printf("3. Adicionar encomenda\n");
        printf("4. Retirar pedido\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 5))
            printf("Por favor, inserir um numero valido!\n");

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
            printf("\n=== IMPRIMIR ENCOMENDAS ===\n\n");
            lista_imprimir();
            break;

        case 2:
            printf("\n=== REMOVER ENCOMENDA ===\n\n");
            lista_excluir_encomenda();
            break;

        }
    } while (opcao != 0);
    //system("pause");
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
            printf("Por favor, inserir um numero valido!\n");

    } while ((opcao < 0) || (opcao > 3));

    return opcao;
}

//Pergunta para o usuário qual vertice da pedido da arvore ele quer retirar
void abb_retirar_pedido(void)
{
    int pedido_id;

    printf("\nDigite o ID que deseja retirar: ");
    scanf("%d", &pedido_id);
    abb_excluir_pedido(raiz, pedido_id);
}

/*carrega os valores do pedido em variaveis e passa como parametro
para a função adicionar na arvore
*/
void carregar_pedido_estagiario(void)
{
    int pedido_id = 0;
    char *pedido_nome = malloc(55);
    int pedido_matricula = 0;
    char *pedido_descricao = malloc(500);
    
    srand(time(NULL));//impede que repita o mesmo valor aleatório

    pedido_id = (rand() % 100);//gera um valor aleatório de 0 a 100

    setbuf(stdin, NULL);
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", pedido_nome);
    //fgets(pedido_nome, 100, stdin);

    //setbuf(stdin, NULL);
    printf("Digite o a matricula do aluno: ");
    scanf("%d", &pedido_matricula);

    setbuf(stdin, NULL);
    printf("Digite os dados do pedido: ");
    scanf("%[^\n]s", pedido_descricao);
    //fgets(pedido_descricao, 500, stdin);

    abb_add_pedido(pedido_id, pedido_nome, pedido_matricula, pedido_descricao);
}

PEDIDO * abb_bucar_pedido(int pedido_id, PEDIDO *aux)
{
    if(aux != NULL)
    {
        if(aux->pedido_id == pedido_id)
        {
            return aux;
        }
        else if(pedido_id < aux->pedido_id)
        {
            if(aux->esq != NULL)
            {
                return abb_bucar_pedido(pedido_id, aux->esq);
            }
            else
            {
                return aux;
            }
        }
        else if(pedido_id > aux->pedido_id)
        {
            if(aux->dir != NULL)
            {
                return abb_bucar_pedido(pedido_id, aux->dir);
            }
            else
            {
                return aux;
            }
        }
    }
    return NULL;
}

void abb_add_pedido(int pedido_id, char *pedido_nome_aluno, int pedido_matricula, char *pedido_descricao)
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
        printf("no nao existe na arvore");
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
            free(raiz);///////////////////////////////////////////////////////
            raiz = NULL;
        }
        else if (raiz->esq == NULL)
        {
            PEDIDO * aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        else if (raiz->dir == NULL)
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
    }
    raiz = NULL;
    return raiz;
}

void abb_imprimir(PEDIDO * aux)
{
    if (aux->pedido_id != NULL)
    {
        if(aux->esq != NULL){
        abb_imprimir(aux->esq);
        }
        printf("Pedido: \n\n");
        printf("ID: %d\n", aux->pedido_id);
        printf("Aluno: %s\n", aux->pedido_nome_aluno);
        printf("Matricula: %d\n", aux->pedido_matricula);
        printf("Descricao: %s\n\n", aux->pedido_descricao);
        if(aux->dir != NULL){
            abb_imprimir(aux->dir);
        }
    }
    else
    {
        printf("nao encontrado\n");
    } 
}

/*int verifica_usuario()
{
    char usuario_cpf[11];
    char usuario_senha[20];
    char usuario_chave[5];

    printf("Digite seu CPF: ");
    scanf("%s", usuario_cpf);
    printf("Digite sua senha: ");
    scanf("%s", usuario_senha);
    printf("Digite sua chave: ");
    scanf("%s", usuario_chave);

    for (int i = 0; i < 2; i++)
    {
        if ((usuario_cpf == user[i]->usuario_cpf) && (usuario_senha == user[i]->usuario_senha) && (usuario_chave == user[i]->usuario_chave))
        {
            printf("\nRegistro Encontrado!\n");
            return 1;
        }        
        else
        {
            printf("\nSenha incorreta\n");
            return 0;
        }
        
    }
}*/

void carregar_pedido_secretario()
{
    int pedido_id;
    char pedido_remetente[20];
    char pedido_destinatario[20];
    char pedido_responsavel_secretario[20];
    unsigned short int pedido_prioridade = 0;

    printf("Digite o ID do pedido: ");
    scanf("%d", &pedido_id);
    printf("Digite a localizacao do livro: ");
    scanf("%s", pedido_remetente);
    printf("Digite a localizacao do aluno: ");
    scanf("%s", pedido_destinatario);
    printf("Digite o nome do responsavel(secretario atual): ");
    scanf("%s", pedido_responsavel_secretario);
    printf("Digite a prioridade (0 - 100): ");
    scanf("%hu", &pedido_prioridade);
    
    lista_add_encomenda(abb_bucar_pedido(pedido_id, raiz), pedido_remetente, pedido_destinatario, pedido_responsavel_secretario, pedido_prioridade);
    abb_excluir_pedido(raiz, pedido_id); 
    
}

void lista_add_encomenda(PEDIDO * pedido, char *pedido_remetente, char *pedido_destinatario, char *pedido_responsavel_secretario, unsigned short int pedido_prioridade)
{
    PEDIDO * Encomenda = malloc(sizeof(PEDIDO));

    Encomenda->pedido_id = pedido->pedido_id;
    Encomenda->pedido_nome_aluno = pedido->pedido_nome_aluno;
    Encomenda->pedido_matricula = pedido->pedido_matricula;
    Encomenda->pedido_descricao = pedido->pedido_descricao;
    Encomenda->pedido_remetente = pedido_remetente;
    Encomenda->pedido_destinatario = pedido_destinatario;
    Encomenda->pedido_responsavel_secretario = pedido_responsavel_secretario;
    Encomenda->pedido_prioridade = pedido_prioridade;

    ENCOMENDA * novo = malloc(sizeof(ENCOMENDA));

    ENCOMENDA * menor, * maior = malloc(sizeof(ENCOMENDA));

    novo->pEncomenda = Encomenda;
    novo->prox = NULL;

    if (inicio == NULL)
    {
        inicio = novo;
        fim = novo;
        lista_tamanho++;
        novo->prox = NULL;
    }
    else
    {
        menor = inicio;
        while (menor != NULL && menor->pEncomenda->pedido_prioridade > novo->pEncomenda->pedido_prioridade)
        {
            maior = menor;
            menor = menor->prox;
        }
        
        novo->prox = menor;

        if (maior == NULL)
        {
            inicio = novo;
            lista_tamanho++;
        }
        else
        {
            maior->prox = novo;
            lista_tamanho++;
            fim = novo;
        }
    }
}

PEDIDO lista_excluir_encomenda()
{
    PEDIDO encomenda;
    if (inicio != NULL)
    {
        ENCOMENDA * lixo = inicio;
        inicio = inicio->prox;
        encomenda.pedido_id = lixo->pEncomenda->pedido_id;
        printf("\n\n Pedido Excluido \n");
        printf("Aluno: %s\n", lixo->pEncomenda->pedido_nome_aluno);
        printf("ID: %d\n", &lixo->pEncomenda->pedido_id);
        free(lixo);
        lista_tamanho--;
        if (lista_tamanho == 1)
        {
            fim = NULL;
        }
    }
    return encomenda;
}

void lista_imprimir()
{
    ENCOMENDA * aux = malloc(sizeof(ENCOMENDA));
    aux = inicio;
    while(aux != NULL)
    {
        printf("ID: %d\n", aux->pEncomenda->pedido_id);
        printf("Aluno: %s\n", aux->pEncomenda->pedido_nome_aluno);
        printf("Matricula: %d\n", aux->pEncomenda->pedido_matricula);
        printf("Descricao: %s\n", aux->pEncomenda->pedido_descricao);
        printf("Remetente: %s\n", aux->pEncomenda->pedido_remetente);
        printf("Destinatario: %s\n", aux->pEncomenda->pedido_destinatario);
        printf("Responsavel: %s\n", aux->pEncomenda->pedido_responsavel_secretario);
        printf("Prioridade: %hu\n", aux->pEncomenda->pedido_prioridade);
        printf("tamanho da lista: %d\n", lista_tamanho);
        aux = aux->prox;
    }
}

