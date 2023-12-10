#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void lerProduto(TProduto* produto){
  printf("\n=========== Cadastrar produto ===========");
  printf("\nCodigo: ");
  fflush(stdin);
  scanf("%d", &produto -> codigo);
  getchar();

  printf("Nome: ");
  fflush(stdin);
  fgets(produto -> nome, 20, stdin);

  printf("Descricao: ");
  fflush(stdin);
  fgets(produto -> descricao, 100, stdin);

  printf("Preco: ");
  fflush(stdin);
  scanf("%f", &produto -> preco);

  printf("Quantidade: ");
  fflush(stdin);
  scanf("%d", &produto -> quantidade);
  printf("=========================================\n");
}

// CRIAR A CÉLULA CABEÇA
void FLVazia(TLista* Lista){
  Lista -> primeiro = (TCelula*) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
  Lista -> tamanho = 0;
}

int verificaVazia(TLista Lista){
  return (Lista.primeiro == Lista.ultimo);
}

void inserir(TProduto x, TLista* Lista){
  Lista -> ultimo -> prox = (TCelula*) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> item = x;
  Lista -> ultimo -> prox = NULL;
  Lista -> tamanho++;
}

void excluir(TLista* Lista, TProduto* Produto){
  TCelula *aux1, *aux2;
  aux1 = pesquisar(*Lista, *Produto);
  if (aux1 != NULL){
    aux2 = aux1 -> prox;
    aux1 -> prox = aux2 -> prox;
    *Produto = aux2 -> item;
    if (aux1 == NULL)
      Lista -> ultimo = aux1;
    free(aux2);
    Lista -> tamanho--;
  }
}

void imprimir(TLista Lista){
  TCelula* aux;
  aux = Lista.primeiro -> prox;
  printf("\n----------------------------------------\n");
  while (aux != NULL){
    printf("Codigo: %d\n", aux -> item.codigo);
    printf("Nome: %s", aux -> item.nome);
    printf("Descricao: %s", aux -> item.descricao);
    printf("Preco: %.2f\n", aux -> item.preco);
    printf("Quantidade: %d\n", aux -> item.quantidade);
    printf("----------------------------------------\n");

    aux = aux -> prox;
  }
}

void imprimirProduto(TProduto x){
  printf("\n----------------------------------------\n");
  printf("Codigo: %d\n", x.codigo);
  printf("Nome: %s", x.nome);
  printf("Descricao: %s", x.descricao);
  printf("Preco: %.2f\n", x.preco);
  printf("Quantidade: %d\n", x.quantidade);
  printf("----------------------------------------\n");
}

TCelula* pesquisar(TLista Lista, TProduto x){
  TCelula* aux = Lista.primeiro;
  while (aux -> prox != NULL){
    if (aux -> prox -> item.codigo == x.codigo)
      return aux;
    aux = aux -> prox;
  }
  return NULL;
}

TCelula* pesquisarPorNome(TLista Lista, TProduto x){
  TCelula* aux = Lista.primeiro;
  while (aux -> prox != NULL){
    if (strcmp(aux -> prox -> item.nome, x.nome) == 0)
      return aux;
    aux = aux -> prox;
  }
  return NULL;
}

void liberarLista(TLista *Lista){
  TCelula *aux;
  while (!verificaVazia(*Lista)){
    aux = Lista -> primeiro -> prox;
    Lista -> primeiro -> prox = aux -> prox;
    free(aux);

    if (Lista -> primeiro -> prox == NULL)
      Lista -> ultimo = Lista -> primeiro;

    Lista -> tamanho--;
  }
}

void atualizar(TLista *Lista, TProduto Item){
  TCelula* aux = pesquisarPorNome(*Lista, Item);

  if (aux != NULL ){
    lerProduto(&Item);
    aux -> prox -> item = Item;
  } else
    printf("Produto nao encontrado!");
}

void inserirCrescente(TLista *lista, TProduto x){
    TCelula* aux1 = lista -> primeiro;
    TCelula* aux2;

    while (aux1 -> prox != NULL) {
        int compStr = strcmp(x.nome, aux1 -> prox -> item.nome);

        if (compStr > 0)
            aux1 = aux1 -> prox;

        else {
            aux2 = (TCelula*) malloc(sizeof(TCelula));
            aux2 -> item = x;
            aux2 -> prox = aux1 -> prox;
            aux1 -> prox = aux2;
            lista -> tamanho++;

            return;
        }
    }

    inserir(x, lista);
}

int listasIguais(TLista lista1, TLista lista2){
  TCelula *aux1 = lista1.primeiro;
  TCelula *aux2 = lista2.primeiro;

  if (lista1.tamanho != lista2.tamanho) {
    return 0;
  }

  while (aux1 != NULL && aux2 != NULL) {
    if (aux1->item.codigo != aux2->item.codigo) {
      return 0;
    }
    if (strcmp(aux1->item.nome, aux2->item.nome) != 0) {
      return 0;
    }
    if (strcmp(aux1->item.descricao, aux2->item.descricao) != 0) {
      return 0;
    }
    if (aux1->item.preco != aux2->item.preco) {
      return 0;
    }
    if (aux1->item.quantidade != aux2->item.quantidade) {
      return 0;
    }

    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }

  return (aux1 == NULL && aux2 == NULL);
}

void concatenar(TLista *lista1, TLista lista2){
    TCelula* aux = lista2.primeiro;

    while (aux -> prox != NULL) {
        inserir(aux -> prox -> item, lista1);
        aux = aux -> prox;
    }
}
