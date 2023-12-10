# ifndef LISTA_H_INCLUDED
# define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// TIPO PRODUTO
typedef struct {
  int codigo;
  char nome[20];
  float preco;
  char descricao[100];
  int quantidade;
} TProduto;

// TIPO CÉLULA
typedef struct celula{
  TProduto item;
  struct celula* prox;
} TCelula;

// TIPO LISTA
typedef struct {
  TCelula* primeiro;
  TCelula* ultimo;
  int tamanho;
} TLista;

// MÉTODOS
void FLVazia(TLista* Lista);
int verificaVazia(TLista Lista);

void lerProduto(TProduto* produto);
void inserir(TProduto x, TLista* Lista);
void excluir(TLista* Lista, TProduto* Produto);
void imprimir(TLista Lista);
void imprimirProduto(TProduto x);
TCelula* pesquisar(TLista Lista, TProduto x);
TCelula* pesquisarPorNome(TLista Lista, TProduto produto);
void liberarLista(TLista *Lista);
void atualizar(TLista *Lista, TProduto Item);
void inserirCrescente(TLista *lista, TProduto x);
int listasIguais(TLista lista1, TLista lista2);
void concatenar(TLista* lista1, TLista lista2);

# endif // LISTA_H_INCLUDED
