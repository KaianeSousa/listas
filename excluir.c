
#include "lista.h"

int tamanhoLista(struct Lista* lista);

void interageExcluir(){
    
    struct Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao, posicao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Excluir do Início\n");
        printf("2. Excluir do Fim\n");
        printf("3. Excluir de uma Posição Específica\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                excluirInicio(&minhaLista);
                break;

            case 2:
                excluirFim(&minhaLista);
                break;

            case 3:
                do {
                    printf("Digite a posição para excluir (de 1 a %d): ", tamanhoLista(&minhaLista));
                    scanf("%d", &posicao);

                    if (posicao < 1 || posicao > tamanhoLista(&minhaLista)) {
                        printf("Posição inválida. Tente novamente.\n");
                    }
                } while (posicao < 1 || posicao > tamanhoLista(&minhaLista));
                excluirPosicao(&minhaLista, posicao);
                break;

            case 0:
                printf("Saindo do meu de exclusão...\n");
                break;

            default:
                printf("Opção inválida. Reveja as opções disponíveis e tente novamente.\n");
                break;
        }

    } while (opcao != 0);

}

/*

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
*/