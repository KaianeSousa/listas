
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
};

struct Lista {
    struct No* inicio;
    struct No* fim;
    int tamanho;  // Adicionado o tamanho da lista
};

//Funções de interação
void interageArquivo();
void interageExcluir();
void interageInserir();

//Função para iniciar as listas
void inicializarLista(struct Lista* lista);

//Funções de inserção de valores a lista
void inserirInicio(struct Lista* lista, int valor);
void inserirFim(struct Lista* lista, int valor);
void inserirPosicao(struct Lista* lista, int valor, int posicao);

//Funções de exclusão 
void excluirInicio(struct Lista* lista);
void excluirFim(struct Lista* lista);
void excluirPosicao(struct Lista* lista, int posicao);

//Função para pesquisar os valores e apontar para uma struct
struct No* pesquisarNo(struct Lista* lista, int valor);

//Função para exibir a lista feita
void exibirLista(struct Lista* lista);

//Funções para carregar o arquivo
void salvarLista(struct Lista* lista, const char* nomeArquivo);
void carregarLista(struct Lista* lista, const char* nomeArquivo);


#endif // LISTA_H
