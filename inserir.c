

#include "lista.h"

int tamanhoLista(struct Lista* lista);

void interageInserir(){
    
    struct Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao, num, posicao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Inserir no Início\n");
        printf("2. Inserir no Fim\n");
        printf("3. Inserir em uma Posição Específica\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número a ser inserido no início: ");
                scanf("%d", &num);
                inserirInicio(&minhaLista, num);
                break;

            case 2:
                printf("Digite um número a ser inserido no fim: ");
                scanf("%d", &num);
                inserirFim(&minhaLista, num);
                break;

            case 3:
                printf("Digite um número para ser inserido em determinada posição: ");
                scanf("%d", &num);
                do {
                    printf("Digite a posição (de 1 a %d): ", tamanhoLista(&minhaLista) + 1);
                    scanf("%d", &posicao);

                    if (posicao < 1 || posicao > tamanhoLista(&minhaLista) + 1) {
                        printf("Posição inválida. Tente novamente.\n");
                    }
                } while (posicao < 1 || posicao > tamanhoLista(&minhaLista) + 1);
                
                inserirPosicao(&minhaLista, num, posicao);
                break;
                
                case 0:
                printf("Saindo do menu de inserção...\n");
                break;

            default:
                printf("Opção inválida. Reveja as opções disponíveis e tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}
