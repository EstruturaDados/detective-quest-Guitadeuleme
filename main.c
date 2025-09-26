#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Sala
{
    char nome[64];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

Sala *criarSala(const char *nome)
{
    Sala *s = malloc(sizeof(Sala));
    if (!s)
    {
        perror("malloc");
        exit(1);
    }
    strncpy(s->nome, nome, sizeof(s->nome) - 1);
    s->nome[sizeof(s->nome) - 1] = '\0';
    s->esq = NULL;
    s->dir = NULL;
    return s;
}

void destruirArvore(Sala *raiz)
{
    if (!raiz)
        return;
    destruirArvore(raiz->esq);
    destruirArvore(raiz->dir);
    free(raiz);
}

void exibirInstrucao(void)
{
    printf("\nDigite: e (esquerda), d (direita), s (sair)\n");
    printf("Escolha: ");
}

void explorarSalas(Sala *raiz)
{
    if (!raiz)
        return;
    Sala *atual = raiz;
    while (true)
    {
        printf("\nVocê está em: %s\n", atual->nome);
        bool folha = (atual->esq == NULL && atual->dir == NULL);
        if (folha)
        {
            printf("Fim do caminho: não há mais portas.\n");
            break;
        }
        exibirInstrucao();
        char buffer[32];
        if (!fgets(buffer, sizeof(buffer), stdin))
            break;
        char op = (char)tolower((unsigned char)buffer[0]);
        if (op == 's')
        {
            printf("Exploração encerrada.\n");
            break;
        }
        else if (op == 'e')
        {
            if (atual->esq)
            {
                atual = atual->esq;
            }
            else
            {
                printf("Não há caminho à esquerda.\n");
            }
        }
        else if (op == 'd')
        {
            if (atual->dir)
            {
                atual = atual->dir;
            }
            else
            {
                printf("Não há caminho à direita.\n");
            }
        }
        else
        {
            printf("Opção inválida.\n");
        }
    }
}

Sala *montarMapa(void)
{
    Sala *hall = criarSala("Hall de entrada");
    Sala *salaEstar = criarSala("Sala de estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *escritorio = criarSala("Escritório");
    Sala *despensa = criarSala("Despensa");
    Sala *jardim = criarSala("Jardim");
    hall->esq = salaEstar;
    hall->dir = cozinha;
    salaEstar->esq = biblioteca;
    salaEstar->dir = escritorio;
    cozinha->esq = despensa;
    cozinha->dir = jardim;
    return hall;
}

int main(void)
{
    Sala *mapa = montarMapa();
    printf("Detective Quest — Exploração da Mansão (Árvore Binária)\n");
    explorarSalas(mapa);
    destruirArvore(mapa);
    return 0;
}
