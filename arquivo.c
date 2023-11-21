
#include "lista.h"

int tamanhoLista(struct Lista* lista);

void interageArquivo(){
    
    struct Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao, valor;
    char nomeArquivo[50];

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Pesquisar Nó\n");
        printf("2. Exibir Lista\n");
        printf("3. Salvar Lista em Arquivo\n");
        printf("4. Carregar Lista de Arquivo\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
            
                printf("Digite o valor para pesquisar: ");
                scanf("%d", &valor);
                
                struct No* resultadoPesquisa = pesquisarNo(&minhaLista, valor);
                
                if(resultadoPesquisa != NULL){
                    
                    printf("Nó encontrado: %d\n", resultadoPesquisa->valor);
                    
                }else{
                    printf("Nó não encontrado\n");
                }
                break;

            case 2:
            
                printf("Lista: ");
                
                exibirLista(&minhaLista);
                break;

            case 3:
            
                printf("Digite o nome do arquivo para salvar: ");
                scanf("%s", nomeArquivo);
                
                salvarLista(&minhaLista, nomeArquivo);
                break;

            case 4:
            
                printf("Digite o nome do arquivo para carregar: ");
                scanf("%s", nomeArquivo);
                
                carregarLista(&minhaLista, nomeArquivo);
                break;

            case 0:
            
                printf("Saindo do menu do arquivo...\n");
                break;

            default:
                printf("Opção inválida. Reveja as opções disponíveis e tente novamente.\n");
                break;
        }

    } while (opcao != 0);

}

/*
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

*/