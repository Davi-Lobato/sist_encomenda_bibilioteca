#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct usuario
{
    char *usuario_nome;
    char *usuario_cpf;
    char *usuario_senha;
    char *usuario_chave;
}USUARIO;

bool verifica_usuario(void);