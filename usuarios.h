#include <stdio.h>
#include <stdlib.h>

typedef struct usuario
{
    char * usuario_nome;
    char * usuario_cpf;
    char * usuario_senha;
    char * usuario_chave;
    
    struct usuario * prox;
}USUARIO;

void lista_add_ususario(char * usurio_nome, char * usuario_cpf, char* usuario_senha, char* usuario_chave, struct usuario prox);
bool verificar_usuario(void);
