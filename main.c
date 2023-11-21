
#include "lista.h"

int main(){
    
    struct Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao, valor, posicao;
    char nomeArquivo[50];

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Inserir\n");
        printf("2. Excluir\n");
        printf("3. Manipular arquivo\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            
                interageInserir();
                break;

            case 2:
            
                interageExcluir();
                break;

            case 3:
            
                interageArquivo();
                break;

            case 0:
                printf("Esperamos que tenha aproveitado nosso programa. Até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
