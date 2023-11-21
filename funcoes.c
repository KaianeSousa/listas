
#include "lista.h"

struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->anterior = novoNo->proximo = NULL;
    return novoNo;
}

void inicializarLista(struct Lista* lista) {
    lista->inicio = lista->fim = NULL;
    lista->tamanho = 0;
}

int listaVazia(struct Lista* lista) {
    return lista->inicio == NULL;
}

int tamanhoLista(struct Lista* lista) {
    return lista->tamanho;
}

void inserirInicio(struct Lista* lista, int valor) {
    struct No* novoNo = criarNo(valor);
    if (listaVazia(lista)) {
        lista->inicio = lista->fim = novoNo;
    } else {
        novoNo->proximo = lista->inicio;
        lista->inicio->anterior = novoNo;
        lista->inicio = novoNo;
    }
    lista->tamanho++;
}

void inserirFim(struct Lista* lista, int valor) {
    struct No* novoNo = criarNo(valor);
    if (listaVazia(lista)) {
        lista->inicio = lista->fim = novoNo;
    } else {
        novoNo->anterior = lista->fim;
        lista->fim->proximo = novoNo;
        lista->fim = novoNo;
    }
    lista->tamanho++;
}

void inserirPosicao(struct Lista* lista, int valor, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida. Tente novamente.\n");
        return;
    }

    struct No* novoNo = criarNo(valor);
    struct No* noAtual = lista->inicio;

    for (int i = 1; i < posicao && noAtual != NULL; i++) {
        noAtual = noAtual->proximo;
    }

    if (noAtual == NULL) {
        inserirFim(lista, valor);
    } else {
        novoNo->proximo = noAtual->proximo;
        novoNo->anterior = noAtual;
        if (noAtual->proximo != NULL) {
            noAtual->proximo->anterior = novoNo;
        } else {
            lista->fim = novoNo;
        }
        noAtual->proximo = novoNo;
        lista->tamanho++;
    }
}

void excluirInicio(struct Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia\n");
    } else {
        struct No* temp = lista->inicio;
        if (lista->inicio == lista->fim) {
            lista->inicio = lista->fim = NULL;
        } else {
            lista->inicio = lista->inicio->proximo;
            lista->inicio->anterior = NULL;
        }
        free(temp);
        lista->tamanho--;
    }
}

void excluirFim(struct Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia\n");
    } else {
        struct No* temp = lista->fim;
        if (lista->inicio == lista->fim) {
            lista->inicio = lista->fim = NULL;
        } else {
            lista->fim = lista->fim->anterior;
            lista->fim->proximo = NULL;
        }
        free(temp);
        lista->tamanho--;
    }
}

void excluirPosicao(struct Lista* lista, int posicao) {
    if (listaVazia(lista)) {
        printf("Lista vazia\n");
    } else if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida. Tente novamente.\n");
    } else {
        struct No* noAtual = lista->inicio;
        for (int i = 1; i < posicao && noAtual != NULL; i++) {
            noAtual = noAtual->proximo;
        }

        if (noAtual != NULL) {
            if (noAtual->anterior != NULL) {
                noAtual->anterior->proximo = noAtual->proximo;
            } else {
                lista->inicio = noAtual->proximo;
            }

            if (noAtual->proximo != NULL) {
                noAtual->proximo->anterior = noAtual->anterior;
            } else {
                lista->fim = noAtual->anterior;
            }

            free(noAtual);
            lista->tamanho--;
        }
    }
}

struct No* pesquisarNo(struct Lista* lista, int valor) {
    struct No* noAtual = lista->inicio;
    while (noAtual != NULL && noAtual->valor != valor) {
        noAtual = noAtual->proximo;
    }
    return noAtual;
}

void exibirLista(struct Lista* lista) {
    struct No* noAtual = lista->inicio;
    while (noAtual != NULL) {
        printf("%d ", noAtual->valor);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

void salvarLista(struct Lista* lista, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }

    struct No* noAtual = lista->inicio;
    while (noAtual != NULL) {
        fprintf(arquivo, "%d\n", noAtual->valor);
        noAtual = noAtual->proximo;
    }

    fclose(arquivo);
}

void carregarLista(struct Lista* lista, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    inicializarLista(lista);
    int valor;

    while (fscanf(arquivo, "%d", &valor) == 1) {
        inserirFim(lista, valor);
    }

    fclose(arquivo);
}
