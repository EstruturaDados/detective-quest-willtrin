#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó (cômodo da mansão)
typedef struct Comodo {
    char nome[30];
    struct Comodo *esquerda;  // saída à esquerda
    struct Comodo *direita;   // saída à direita
} Comodo;

// Função para criar um novo cômodo
Comodo* criarComodo(const char *nome) {
    Comodo *novo = (Comodo*)malloc(sizeof(Comodo));
    strcpy(novo->nome, nome);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para montar automaticamente a mansão (árvore binária)
Comodo* montarMansao() {
    // Cria os cômodos
    Comodo *hall = criarComodo("Hall Principal");
    Comodo *sala = criarComodo("Sala de Estar");
    Comodo *cozinha = criarComodo("Cozinha");
    Comodo *biblioteca = criarComodo("Biblioteca");
    Comodo *quarto = criarComodo("Quarto do Andar Superior");
    Comodo *banheiro = criarComodo("Banheiro");
    Comodo *porao = criarComodo("Porao Escuro");

    // Ligações da árvore (estrutura da mansão)
    hall->esquerda = sala;
    hall->direita = cozinha;

    sala->esquerda = biblioteca;
    sala->direita = quarto;

    cozinha->esquerda = banheiro;
    cozinha->direita = porao;

    // Retorna o início (raiz)
    return hall;
}

// Função de exploração do mapa
void explorarMansao(Comodo *atual) {
    char escolha;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Verifica se é um cômodo sem saídas
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf(" Este cômodo não tem mais saídas. Você chegou ao fim do mapa!\n");
            break;
        }

        // Mostra opções disponíveis
        if (atual->esquerda != NULL)
            printf("A - Ir para a esquerda (%s)\n", atual->esquerda->nome);
        if (atual->direita != NULL)
            printf("D - Ir para a direita (%s)\n", atual->direita->nome);
        printf("S - Sair da mansão\n");

        printf("Escolha uma direção: ");
        scanf(" %c", &escolha);

        if ((escolha == 'A' || escolha == 'a') && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } 
        else if ((escolha == 'D' || escolha == 'd') && atual->direita != NULL) {
            atual = atual->direita;
        } 
        else if (escolha == 'S' || escolha == 's') {
            printf(" Você saiu da mansão em segurança.\n");
            break;
        } 
        else {
            printf("Caminho inválido. Tente novamente.\n");
        }
    }
}

// Função para liberar memória
void liberarMansao(Comodo *raiz) {
    if (raiz == NULL) return;
    liberarMansao(raiz->esquerda);
    liberarMansao(raiz->direita);
    free(raiz);
}

// Programa principal
int main() {
    printf(" Bem-vindo ao Mapa da Mansão Misteriosa!\n");
    printf("Você poderá explorar os cômodos usando as direções A (esquerda) e D (direita).\n");

    Comodo *mansao = montarMansao();

    explorarMansao(mansao);

    liberarMansao(mansao);
    printf("Memória liberada e programa encerrado.\n");
    return 0;
}