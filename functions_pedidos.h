#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs_pedidos.h"
#include "structs_usuarios.h"

int lista_tamanho = 0;

PEDIDO * raiz = NULL;
//USUARIO * user[8];
ENCOMENDA * inicio_lista_encomenda = NULL;
ENCOMENDA * fim_lista_encomenda = NULL;
USUARIO * inicio_lista_usuarios = NULL;
USUARIO * fim_lista_usuarios = NULL;


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



void carregar_pedido_secretario()
{
    int pedido_id;
    char *pedido_remetente = malloc(20);
    char *pedido_destinatario = malloc(20);
    char *pedido_responsavel_secretario = malloc(20);
    unsigned short int pedido_prioridade = 0;
    bool autenticidade = false;

    autenticidade = verifica_usuario();

    if (autenticidade == true)
    {
        printf("Digite o ID do pedido: ");
        scanf("%d", &pedido_id);
        setbuf(stdin, NULL);

        if (pedido_id == abb_buscar_pedido(pedido_id, raiz)->pedido_id)
        {
            printf("Digite a localizacao do livro: ");
            scanf("%[^\n]s", pedido_remetente);
            setbuf(stdin, NULL);

            printf("Digite a localizacao do aluno: ");
            scanf("%[^\n]s", pedido_destinatario);
            setbuf(stdin, NULL);

            printf("Digite o nome do responsavel(secretario atual): ");
            scanf("%[^\n]s", pedido_responsavel_secretario);
            setbuf(stdin, NULL);

            printf("Digite a prioridade (0 - 100): ");
            scanf("%hu", &pedido_prioridade);
    
            lista_add_encomenda(abb_buscar_pedido(pedido_id, raiz), pedido_remetente, pedido_destinatario, pedido_responsavel_secretario, pedido_prioridade);
            abb_excluir_pedido(raiz, pedido_id); 
        }
        else
        {
            printf("id nao existe");
        }
    }
    else
    {
        printf("Não tem permissão para tal operação");
    }
    
}



PEDIDO * abb_buscar_pedido(int pedido_id, PEDIDO *aux)
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
                return abb_buscar_pedido(pedido_id, aux->esq);
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
                return abb_buscar_pedido(pedido_id, aux->dir);
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
    PEDIDO* buscador = abb_buscar_pedido(pedido_id, raiz);
    
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
            free(raiz);
            raiz->pedido_id = NULL;
            raiz->pedido_nome_aluno = NULL;
            raiz->pedido_matricula = NULL;
            raiz->pedido_descricao = NULL;
        }
        else if (raiz->esq == NULL)
        {
            PEDIDO * aux = raiz;
            raiz = raiz->dir;
            free(aux);
            aux->pedido_id = NULL;
            aux->pedido_nome_aluno = NULL;
            aux->pedido_matricula = NULL;
            aux->pedido_descricao = NULL;
        }
        else if (raiz->dir == NULL)
        {
            PEDIDO * aux = raiz;
            raiz = raiz->esq;
            free(aux);
            aux->pedido_id = NULL;
            aux->pedido_nome_aluno = NULL;
            aux->pedido_matricula = NULL;
            aux->pedido_descricao = NULL;
        }
        else
        {
            PEDIDO * aux = raiz->esq;
            while (aux->dir != NULL)
            {
                aux = raiz ->dir;
            }   
            raiz->pedido_id = aux->pedido_id;
            raiz->pedido_nome_aluno = aux->pedido_nome_aluno;
            raiz->pedido_matricula = aux->pedido_matricula;
            raiz->pedido_descricao = aux->pedido_descricao;
            raiz->esq = abb_excluir_pedido(aux->esq, pedido_id);   
        }        
    }
}



void abb_imprimir(PEDIDO * aux)
{
    if(raiz != NULL)
    {
        if(aux->esq != NULL){
            abb_imprimir(aux->esq);
        }
        if (aux->pedido_id != NULL && aux->pedido_matricula != NULL)
        {
            printf("=============\n");
            printf("id..........: %d\n", aux->pedido_id);
            printf("aluno.......: %s\n", aux->pedido_nome_aluno);
            printf("matricula...: %d\n", aux->pedido_matricula);
            printf("descricao...: %s\n", aux->pedido_descricao);
            printf("=============\n");
        }
        
        if(aux->dir != NULL){
            abb_imprimir(aux->dir);
        } 
    }
    else
    {
        printf("nao encontrado");
    }
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

    if (inicio_lista_encomenda == NULL)
    {
        inicio_lista_encomenda = novo;
        fim_lista_encomenda = novo;
        lista_tamanho++;
        novo->prox = NULL;
    }
    else
    {
        menor = inicio_lista_encomenda;
        while (menor != NULL && menor->pEncomenda->pedido_prioridade > novo->pEncomenda->pedido_prioridade)
        {
            maior = menor;
            menor = menor->prox;
        }
        novo->prox = menor;

        if (maior == NULL)
        {
            inicio_lista_encomenda = novo;
            lista_tamanho++;
        }
        else
        {
            maior->prox = novo;
            lista_tamanho++;
            fim_lista_encomenda = novo;
        }
    }
}



PEDIDO lista_excluir_encomenda()
{
    bool autenticidade = false;
    PEDIDO encomenda;

    autenticidade = verifica_usuario();

    if (autenticidade == true)
    {
        if (inicio_lista_encomenda != NULL)
        {
            ENCOMENDA * lixo = inicio_lista_encomenda;

            inicio_lista_encomenda = inicio_lista_encomenda->prox;
            encomenda.pedido_id = lixo->pEncomenda->pedido_id;

            printf("\n\n Pedido Excluido \n");
            printf("Aluno: %s\n", lixo->pEncomenda->pedido_nome_aluno);
            printf("ID: %d\n", lixo->pEncomenda->pedido_id);

            free(lixo);
            lista_tamanho--;

            if (lista_tamanho == 1)
            {
                fim_lista_encomenda = NULL;
            }
        }
    return encomenda;
    }
    return encomenda;
}



void lista_imprimir()
{
    ENCOMENDA * aux = malloc(sizeof(ENCOMENDA));
    aux = inicio_lista_encomenda;
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

void lista_add_usuario( char * nome, char * cpf, char * senha, char * chave , int pos){
    if(pos >= 0 && pos <= tam_usuarios){
        USUARIO * novo = (USUARIO*)malloc(sizeof(USUARIO));

        novo->usuario_nome=(char*)malloc(sizeof(char)*50);
        novo->usuario_senha=(char*)malloc(sizeof(char)*50);
        novo->usuario_cpf=(char*)malloc(sizeof(char)*11);
        novo->usuario_chave=(char*)malloc(sizeof(char)*4);

        novo->usuario_senha = senha;
        novo->usuario_cpf = cpf;
        novo->usuario_nome = nome;
        novo->usuario_chave = chave;

        novo->prox = NULL;
        if(inicio_lista_usuarios == NULL){ //lista vazia
            inicio_lista_usuarios = novo;
            fim_lista_usuarios = novo;
            tam_usuarios++;
        }else{
            novo->prox = inicio_lista_usuarios;
            inicio_lista_usuarios = novo;
            tam_usuarios++;
        }
    }
}

bool verifica_usuario(){
    USUARIO * aux = inicio_lista_usuarios;
    bool verificado = false;
    char cpf[11];
    char senha[50];
    char chave[4];
    
    printf("digite seu CPF: ");
    scanf("%s",cpf);
    printf("digite sua senha: ");
    scanf("%s",senha);
    printf("digite sua chave: ");
    scanf("%s",chave);

    for(int i = 0; i < tam_usuarios; i++){
      
        if (strcmp(cpf, aux->usuario_cpf) == 0 && strcmp(senha, aux->usuario_senha) == 0 && strcmp(chave, aux->usuario_chave) == 0)    
        {
            verificado = true;
            return verificado;    
        }
        else if (aux->prox == NULL)
        {
            return verificado;
        }
        else
            aux = aux->prox;
    }
}

void carrega_usuarios()
{
    lista_add_usuario("joao pedro","11111111111","12ab","s",0);
    lista_add_usuario("davi","123","12ab","s",0);
    lista_add_usuario("rafael","33333333333","12ab","s",0);
    lista_add_usuario("lara","44444444444","12ab","t",0);
    lista_add_usuario("roberto carlos","55555555555","12ab","t",0);
    lista_add_usuario("igor","66666666666","12ab","t",0);
    lista_add_usuario("tatiane","77777777777","12ab","t",0);
    lista_add_usuario("pedro vitor","88888888888","12ab","t",0);
}