#include <stdio.h>
#include <stdlib.h>
#include "functions_pedidos.h"

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

//******************************MENU**********************************

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
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 4))
            printf("Por favor, inserir um numero valido!\n");

    } while ((opcao < 0) || (opcao > 4));

    return opcao;
}

// menu que contém as operacoes que o transportador pode fazer
int menu_transportador(void)
{
    int opcao;
    do
    {
        printf("\n\n=== OPERACOES ===\n\n");
        printf("1. Imprimir encomendas\n");
        printf("2. Retirar encomendas\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 3))
            printf("Por favor, inserir um numero valido!\n");

    } while ((opcao < 0) || (opcao > 3));

    return opcao;
}




//****************************OPERAÇÕES********************************

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

        }
    } while (opcao != 0);
    //system("pause");
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

void inicio()
{
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
}
