#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct usuario
{
    char * usuario_nome;
    char * usuario_cpf;
    char * usuario_senha;
    char * usuario_chave;
    
    struct usuario * prox;
}USUARIO;

int tam_usuarios = 0;

void lista_add_usuario( char * nome, char * cpf, char * senha, char * chave , int pos);
bool verifica_usuario(void);
